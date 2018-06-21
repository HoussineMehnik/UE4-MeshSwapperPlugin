// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MeshSwapAnimationEditor/SMeshSwapAnimationEditorViewportToolbar.h"
#include "SEditorViewport.h"
#include "MeshSwapAnimationEditor/MeshSwapAnimationEditorCommands.h"

#define LOCTEXT_NAMESPACE "SMeshSwapAnimationEditorViewportToolbar"

///////////////////////////////////////////////////////////
// SMeshSwapAnimationEditorViewportToolbar

void SMeshSwapAnimationEditorViewportToolbar::Construct(const FArguments& InArgs, TSharedPtr<class ICommonEditorViewportToolbarInfoProvider> InInfoProvider)
{
	SCommonEditorViewportToolbarBase::Construct(SCommonEditorViewportToolbarBase::FArguments(), InInfoProvider);
}

TSharedRef<SWidget> SMeshSwapAnimationEditorViewportToolbar::GenerateShowMenu() const
{
	GetInfoProvider().OnFloatingButtonClicked();

	TSharedRef<SEditorViewport> ViewportRef = GetInfoProvider().GetViewportWidget();

	const bool bInShouldCloseWindowAfterMenuSelection = true;
	FMenuBuilder ShowMenuBuilder(bInShouldCloseWindowAfterMenuSelection, ViewportRef->GetCommandList());
	{
		
	}

	return ShowMenuBuilder.MakeWidget();
}

#undef LOCTEXT_NAMESPACE
