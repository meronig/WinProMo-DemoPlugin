/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _DEMOCOMMANDHANDLER_H_
#define _DEMOCOMMANDHANDLER_H_

#include "../../../WinProMo/src/ProMoEditor/ProMoCmdHandler.h"

class AFX_EXT_CLASS CWPDemoCmdHandler :
    public CProMoCmdHandler
{
public:
    CWPDemoCmdHandler();
    
	virtual void OnInsertLabel();
	virtual void OnUpdateInsertLabel(CCmdUI* pCmdUI);
	virtual void OnInsertNode();
	virtual void OnUpdateInsertNode(CCmdUI* pCmdUI);
	virtual void OnInsertEdge();
	virtual void OnUpdateInsertEdge(CCmdUI* pCmdUI);

	// implements
	virtual BOOL OnPluginCommand(UINT cmdID);
	virtual BOOL OnPluginUpdateCommandUI(CCmdUI* pCmdUI);

};

#endif //_DEMOCOMMANDHANDLER_H_

