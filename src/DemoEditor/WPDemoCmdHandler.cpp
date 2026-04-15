/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	CWPDemoCmdHandler

	Author :		Giovanni Meroni

	Purpose :		CWPDemoCmdHandler implements CWinProMoCmdHandler
					for the WinProMo Demo Plugin.

   ========================================================================*/
#include "stdafx.h"
#include "WPDemoCmdHandler.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoLabel.h"
#include "WPDemoBlockView.h"
#include "WPDemoEdgeView.h"
#include "WPDemoEditor.h"
#include "../resource.h"

CWPDemoCmdHandler::CWPDemoCmdHandler()
	: CProMoCmdHandler(new CWPDemoEditor)
/* =========================================================================
	Function :		CWPDemoCmdHandler::CWPDemoCmdHandler
	Description :	Constructor
	Access :		Public
	Return :    	void
	Parameters :	none
	Notes :			Customize the parameters passed to the base constructor to
					set the editor of your plugin. The editor is responsible 
					for managing the diagram and its elements, and provides 
					methods to manipulate them. You can create a custom
					editor deriving from CProMoEditor and overriding
					its methods.
* ========================================================================*/
{
}

BOOL CWPDemoCmdHandler::OnPluginCommand(UINT cmdID)
/* =========================================================================
	Function :		CWPDemoCmdHandler::OnPluginCommand
	Description :	Handles the commands of the plugin. This method is called 
					when a command of the plugin is selected (e.g., from the 
					Insert menu or the tool palette). The cmdID parameter is 
					the ID of the command that was selected, which should match 
					the ID of the command defined in the GetElements method of 
					the plugin interface. You should handle each command by its ID
					and perform the appropriate action (e.g., insert a new element, 
					modify the diagram, etc.). Return TRUE if the command was handled, 
					or FALSE if it was not handled (in which case it will be routed to
					the next handler).
	Access :		Public
	Return :    	BOOL		-   "TRUE" if the command was handled, "FALSE" 
									otherwise
	Parameters :	UINT cmdID  -   ID of the command that was selected
	Notes :			Customize this method to handle the commands of your plugin.
					Make sure to handle each command by its ID and perform the 
					appropriate action. You can use the GetEditor() method to
					access the editor of the plugin and manipulate the diagram
					and its elements.
* ========================================================================*/
{
	switch (cmdID)
	{
	case ID_INSERT_LABEL:
		OnInsertLabel();
		return TRUE;

	case ID_INSERT_NODE:
		OnInsertNode();
		return TRUE;

	case ID_INSERT_EDGE:
		OnInsertEdge();
		return TRUE;

	default:
		return FALSE; // not handled
	}
}

BOOL CWPDemoCmdHandler::OnPluginUpdateCommandUI(CCmdUI* pCmdUI)
/* =========================================================================
	Function :		CWPDemoCmdHandler::OnPluginUpdateCommandUI
	Description :	Updates the UI of the plugin commands. This method is called 
					when the UI of the plugin needs to be updated (e.g., to check 
					or uncheck a menu item or toolbar button). The pCmdUI parameter
					is a pointer to a CCmdUI object that represents the UI element
					to be updated. You should update the UI element based on the
					current state of the plugin (e.g., whether a command is active
					or not). Return TRUE if the UI was updated, or FALSE if it was
					not updated (in which case it will be routed to the next handler).
	Access :		Public
	Return :    	BOOL			-   "TRUE" if the UI was updated, "FALSE" 
										otherwise
	Parameters :	CCmdUI* pCmdUI  -   pointer to the UI element to be updated
	Notes :			Customize this method to update the UI of your plugin commands.
					Make sure to update each UI element based on the current state
					of the plugin. You can use the GetEditor() method to access
					the editor of the plugin and manipulate the diagram and its elements.
* ========================================================================*/
{
	UINT cmdID = pCmdUI->m_nID;

	switch (cmdID)
	{
	case ID_INSERT_LABEL:
		OnUpdateInsertLabel(pCmdUI);
		return TRUE;

	case ID_INSERT_NODE:
		OnUpdateInsertNode(pCmdUI);
		return TRUE;

	case ID_INSERT_EDGE:
		OnUpdateInsertEdge(pCmdUI);
		return TRUE;

	default:
		return FALSE;
	}
}

void CWPDemoCmdHandler::OnInsertLabel()
{
	GetEditor()->UnselectAll();
	CProMoLabel* obj = new CProMoLabel;
	GetEditor()->StartDrawingObject(obj);
}

void CWPDemoCmdHandler::OnUpdateInsertLabel(CCmdUI* pCmdUI)
{
	if (GetEditor()->IsDrawing()) {
		CProMoLabel* obj = dynamic_cast<CProMoLabel*>(GetEditor()->GetDrawingObject());
		if (obj) {
			pCmdUI->SetCheck(TRUE);
			return;
		}
	}
	pCmdUI->SetCheck(FALSE);
}

void CWPDemoCmdHandler::OnInsertNode()
{
	GetEditor()->UnselectAll();
	CWPDemoBlockView* obj = new CWPDemoBlockView;
	GetEditor()->StartDrawingObject(obj);

}

void CWPDemoCmdHandler::OnUpdateInsertNode(CCmdUI* pCmdUI)
{
	if (GetEditor()->IsDrawing()) {
		CWPDemoBlockView* obj = dynamic_cast<CWPDemoBlockView*>(GetEditor()->GetDrawingObject());
		if (obj) {
			pCmdUI->SetCheck(TRUE);
			return;
		}
	}
	pCmdUI->SetCheck(FALSE);

}

void CWPDemoCmdHandler::OnInsertEdge()
{
	GetEditor()->UnselectAll();
	CWPDemoEdgeView* obj = new CWPDemoEdgeView;
	GetEditor()->StartDrawingObject(obj);
}

void CWPDemoCmdHandler::OnUpdateInsertEdge(CCmdUI* pCmdUI)
{
	if (GetEditor()->IsDrawing()) {
		CWPDemoEdgeView* obj = dynamic_cast<CWPDemoEdgeView*>(GetEditor()->GetDrawingObject());
		if (obj) {
			pCmdUI->SetCheck(TRUE);
			return;
		}
	}
	pCmdUI->SetCheck(FALSE);
}