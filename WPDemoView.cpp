#include "stdafx.h"
#include "WPDemoView.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CWPDemoView, CWinProMoView)

BEGIN_MESSAGE_MAP(CWPDemoView, CWinProMoView)
	//{{AFX_MSG_MAP(CWinProMoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_INSERT_NODE, OnInsertNode)
	ON_UPDATE_COMMAND_UI(ID_INSERT_NODE, OnUpdateInsertNode)
	ON_COMMAND(ID_INSERT_EDGE, OnInsertEdge)
	ON_UPDATE_COMMAND_UI(ID_INSERT_EDGE, OnUpdateInsertEdge)
END_MESSAGE_MAP()


CWPDemoView::CWPDemoView()
{
}

CWPDemoView::~CWPDemoView()
{
}

void CWPDemoView::OnInsertNode()
{
	m_editor->UnselectAll();
	CProMoBlockView* obj = new CProMoBlockView;
	m_editor->StartDrawingObject(obj);

}

void CWPDemoView::OnUpdateInsertNode(CCmdUI* pCmdUI)
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

void CWPDemoView::OnInsertEdge()
{
	m_editor->UnselectAll();
	CProMoEdgeView* obj = new CProMoEdgeView;
	m_editor->StartDrawingObject(obj);
}

void CWPDemoView::OnUpdateInsertEdge(CCmdUI* pCmdUI)
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
