/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#include "stdafx.h"
#include "WPDemoCmdHandler.h"
#include "../../WinProMo/src/ProMoEditor/ProMoLabel.h"
#include "../../WinProMo/src/ProMoEditor/ProMoBlockView.h"
#include "../../WinProMo/src/ProMoEditor/ProMoEdgeView.h"
#include "resource.h"

CWPDemoCmdHandler::CWPDemoCmdHandler()
{
	m_editor = new CProMoEditor;
}

CWPDemoCmdHandler::~CWPDemoCmdHandler()
{
	delete m_editor;
}

BOOL CWPDemoCmdHandler::OnPluginCommand(UINT cmdID)
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

CProMoEditor* CWPDemoCmdHandler::GetEditor() 
{
	return m_editor;
}

void CWPDemoCmdHandler::OnInsertLabel()
{
	m_editor->UnselectAll();
	CProMoLabel* obj = new CProMoLabel;
	m_editor->StartDrawingObject(obj);
}

void CWPDemoCmdHandler::OnUpdateInsertLabel(CCmdUI* pCmdUI)
{
	if (m_editor->IsDrawing()) {
		CProMoLabel* obj = dynamic_cast<CProMoLabel*>(m_editor->GetDrawingObject());
		if (obj) {
			pCmdUI->SetCheck(TRUE);
			return;
		}
	}
	pCmdUI->SetCheck(FALSE);
}

void CWPDemoCmdHandler::OnInsertNode()
{
	m_editor->UnselectAll();
	CProMoBlockView* obj = new CProMoBlockView;
	m_editor->StartDrawingObject(obj);

}

void CWPDemoCmdHandler::OnUpdateInsertNode(CCmdUI* pCmdUI)
{
	if (m_editor->IsDrawing()) {
		CProMoBlockView* obj = dynamic_cast<CProMoBlockView*>(m_editor->GetDrawingObject());
		if (obj) {
			pCmdUI->SetCheck(TRUE);
			return;
		}
	}
	pCmdUI->SetCheck(FALSE);

}

void CWPDemoCmdHandler::OnInsertEdge()
{
	m_editor->UnselectAll();
	CProMoEdgeView* obj = new CProMoEdgeView;
	m_editor->StartDrawingObject(obj);
}

void CWPDemoCmdHandler::OnUpdateInsertEdge(CCmdUI* pCmdUI)
{
	if (m_editor->IsDrawing()) {
		CProMoEdgeView* obj = dynamic_cast<CProMoEdgeView*>(m_editor->GetDrawingObject());
		if (obj) {
			pCmdUI->SetCheck(TRUE);
			return;
		}
	}
	pCmdUI->SetCheck(FALSE);
}