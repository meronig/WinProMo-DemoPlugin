/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPDEMOPLUGININTERFACE_H_
#define _WPDEMOPLUGININTERFACE_H_

#include "../WinProMo/WinProMoPluginInterface.h"
class CWPDemoPluginInterface :
    public CWinProMoPluginInterface
{
	virtual CMultiDocTemplate* RegisterPlugin(CRuntimeClass* pFrameClass, CProMoClipboardHandler* pClip);
	virtual CObArray* GetElements();
	virtual CObArray* GetCommands();
	virtual const CString GetDocumentType();
	virtual const UINT GetDocumentID();
	virtual void Destroy();
};

#endif