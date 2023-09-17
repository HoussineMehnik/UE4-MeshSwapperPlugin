//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#include "MeshSwapperEditorShared/SocketEditing.h"
#include "Engine/EngineTypes.h"
#include "SceneManagement.h"
#include "CanvasItem.h"
#include "CanvasTypes.h"
#include "Engine/StaticMeshSocket.h"
#include "Engine/StaticMesh.h"
#include "Components/PrimitiveComponent.h"
#include "CanvasTypes.h"
#include "UnrealClient.h"
#include "SceneView.h"
#include "Engine/Engine.h"


//////////////////////////////////////////////////////////////////////////
// FSocketEditingHelper

void FSocketEditingHelper::DrawSockets(UPrimitiveComponent* PreviewComponent, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	if (PreviewComponent != nullptr)
	{
		const bool bIsHitTesting = PDI->IsHitTesting();

		const float DiamondSize = 5.0f;
		const FColor UnselectedDiamondColor(255, 128, 128);
		const FColor SelectedDiamondColor(FColor::White);

		TArray<FComponentSocketDescription> SocketList;
		PreviewComponent->QuerySupportedSockets(/*out*/ SocketList);

		for (const FComponentSocketDescription& Socket : SocketList)
		{
			const FColor& DiamondColor = UnselectedDiamondColor;
			const FMatrix SocketTM = PreviewComponent->GetSocketTransform(Socket.Name, RTS_World).ToMatrixWithScale();
			DrawWireDiamond(PDI, SocketTM, DiamondSize, DiamondColor, SDPG_Foreground);

			if (bIsHitTesting)
			{
				PDI->SetHitProxy(nullptr);
			}
		}
	}
}

void FSocketEditingHelper::DrawSocketNames(UPrimitiveComponent* PreviewComponent, FViewport& Viewport, FSceneView& View, FCanvas& Canvas)
{
	if (PreviewComponent != nullptr)
	{
		const int32 HalfX = Viewport.GetSizeXY().X / 2;
		const int32 HalfY = Viewport.GetSizeXY().Y / 2;

		const FColor UnselectedSocketNameColor(255, 196, 196);
		const FColor SelectedSocketNameColor(FColor::White);

		TArray<FComponentSocketDescription> SocketList;
		PreviewComponent->QuerySupportedSockets(/*out*/ SocketList);

		for (const FComponentSocketDescription& Socket : SocketList)
		{
			const FVector SocketWorldPos = PreviewComponent->GetSocketLocation(Socket.Name);

			const FPlane Proj = View.Project(SocketWorldPos);
			if (Proj.W > 0.f)
			{
				const int32 XPos = HalfX + (HalfX * Proj.X);
				const int32 YPos = HalfY + (HalfY * (-Proj.Y));


				const FColor& SocketColor = UnselectedSocketNameColor;

				FCanvasTextItem Msg(FVector2D(XPos, YPos), FText::FromString(Socket.Name.ToString()), GEngine->GetMediumFont(), SocketColor);
				Msg.EnableShadow(FLinearColor::Black);
				Canvas.DrawItem(Msg);

				// 				//@TODO: Draws the current value of the rotation (probably want to keep this!)
				// 				if (bManipulating && StaticMeshEditorPtr.Pin()->GetSelectedSocket() == Socket)
				// 				{
				// 					// Figure out the text height
				// 					FTextSizingParameters Parameters(GEngine->GetSmallFont(), 1.0f, 1.0f);
				// 					UCanvas::CanvasStringSize(Parameters, *Socket->SocketName.ToString());
				// 					int32 YL = FMath::TruncToInt(Parameters.DrawYL);
				// 
				// 					DrawAngles(&Canvas, XPos, YPos + YL, 
				// 						Widget->GetCurrentAxis(), 
				// 						GetWidgetMode(),
				// 						Socket->RelativeRotation,
				// 						Socket->RelativeLocation);
				// 				}
			}
		}
	}
}
