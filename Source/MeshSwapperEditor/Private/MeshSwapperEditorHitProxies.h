//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#pragma once

#include "HitProxies.h"
#include "UObject/NameTypes.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


struct HKeyMeshSocketHitProxy : public HHitProxy
{
	DECLARE_HIT_PROXY();

public:
	HKeyMeshSocketHitProxy(FName InSocketName) :
		HHitProxy(HPP_UI),
		SocketName(InSocketName)
	{

	}

	virtual EMouseCursor::Type GetMouseCursor() override
	{
		return EMouseCursor::Hand;
	}

	FName SocketName;

	virtual bool AlwaysAllowsTranslucentPrimitives() const override
	{
		return true;
	}

};







