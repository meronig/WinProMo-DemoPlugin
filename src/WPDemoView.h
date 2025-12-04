/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _DEMOVIEW_H_
#define _DEMOVIEW_H_

#include "../../WinProMo-App/src/WinProMoView.h"

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
	afx_msg void OnInsertLabel();
	afx_msg void OnUpdateInsertLabel(CCmdUI* pCmdUI);
	afx_msg void OnInsertNode();
	afx_msg void OnUpdateInsertNode(CCmdUI* pCmdUI);
	afx_msg void OnInsertEdge();
	afx_msg void OnUpdateInsertEdge(CCmdUI* pCmdUI);
	//}}AFX_MSG
	//Commands
	DECLARE_MESSAGE_MAP()

};

#endif //_DEMOVIEW_H_

