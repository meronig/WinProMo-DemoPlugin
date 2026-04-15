/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#ifndef _WPDEMOPLUGININTERFACE_H_
#define _WPDEMOPLUGININTERFACE_H_

#include "../../WinProMo/src/WinProMoPluginInterface.h"


class CWPDemoPluginInterface :
    public CWinProMoPluginInterface
{
public:
	CWPDemoPluginInterface();
	virtual CObArray* GetElements();
	virtual CObArray* GetCommands();
	virtual CProMoCmdHandler* GetCmdHandler();
	
};

#endif