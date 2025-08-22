/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _DEMOVIEW_H_
#define _DEMOVIEW_H_

#include "..\WinProMo\WinProMoView.h"

class WPDEMOPLUGIN_API CWPDemoView :
    public CWinProMoView
{
public: // create from serialization only
    DECLARE_DYNCREATE(CWPDemoView)

public:
    CWPDemoView();
    virtual ~CWPDemoView();

protected:
	//{{AFX_MSG(CWPDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnInsertNode();
	afx_msg void OnUpdateInsertNode(CCmdUI* pCmdUI);
	afx_msg void OnInsertEdge();
	afx_msg void OnUpdateInsertEdge(CCmdUI* pCmdUI);
	//}}AFX_MSG
	//Commands
	DECLARE_MESSAGE_MAP()

};

#ifndef _DEBUG  // debug version in WinProMoView.cpp
inline CWinProMoDoc* CWPDemoView::GetDocument()
{
    return (CWinProMoDoc*)m_pDocument;
}
#endif

#endif //_DEMOVIEW_H_

