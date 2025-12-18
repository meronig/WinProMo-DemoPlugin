/* ==========================================================================

    Copyright © 2025 Technical University of Denmark

    Author :		Giovanni Meroni

   ========================================================================*/
#include "stdafx.h"
#include "WPDemoPluginInterface.h"
#include "resource.h"
#include "../../WinProMo/src/ProMoEditor/ProMoEditor.h"
#include "../../WinProMo/src/ProMoEditor/ProMoEntityContainer.h"
#include "WPDemoCmdHandler.h"

CObArray* CWPDemoPluginInterface::GetElements()
{
    CObArray* commands = new CObArray();
    if (commands) {
        CWinProMoPluginCommand* cmd1 = new CWinProMoPluginCommand();
        cmd1->m_commandID = ID_INSERT_LABEL;
        cmd1->m_caption = _T("Label");
        cmd1->m_icon = AfxGetApp()->LoadIcon(IDI_ICON_NODE);
        cmd1->m_subCommands = NULL;

        CWinProMoPluginCommand* space1 = new CWinProMoPluginCommand();
        space1->m_commandID = 0;
        space1->m_caption = _T("-");
        space1->m_icon = NULL;
        space1->m_subCommands = NULL;

        CWinProMoPluginCommand* cmd2 = new CWinProMoPluginCommand();
        cmd2->m_commandID = ID_INSERT_NODE;
        cmd2->m_caption = _T("Node");
        cmd2->m_icon = AfxGetApp()->LoadIcon(IDI_ICON_NODE);
        cmd2->m_subCommands = NULL;

        CWinProMoPluginCommand* space2 = new CWinProMoPluginCommand();
        space2->m_commandID = 0;
        space2->m_caption = _T("-");
        space2->m_icon = NULL;
        space2->m_subCommands = NULL;

        CWinProMoPluginCommand* cmd3 = new CWinProMoPluginCommand();
        cmd3->m_commandID = ID_INSERT_EDGE;
        cmd3->m_caption = _T("Edge");
        cmd3->m_icon = AfxGetApp()->LoadIcon(IDI_ICON_EDGE);
        cmd3->m_subCommands = NULL;

        commands->Add(cmd1);
        commands->Add(space1);
        commands->Add(cmd2);
        commands->Add(space2);
        commands->Add(cmd3);
    }
    return commands;
}

CObArray* CWPDemoPluginInterface::GetCommands()
{
    return NULL;
}

const CString CWPDemoPluginInterface::GetDocumentType()
{
    return _T("demoPlugin");
}

const UINT CWPDemoPluginInterface::GetDocumentID()
{
    return IDR_WPPLUGIN;
}

const CString CWPDemoPluginInterface::GetDocumentDescr()
{
    return CString("WinProMo Demo Plugin Diagram");
}

void CWPDemoPluginInterface::Destroy()
{
    delete this;
}

CProMoCmdHandler* CWPDemoPluginInterface::GetCmdHandler()
{
    return new CWPDemoCmdHandler;
}

CProMoEntityContainer* CWPDemoPluginInterface::GetContainer()
{
    return new CProMoEntityContainer("demoPlugin");
}

CProMoControlFactory* CWPDemoPluginInterface::GetControlFactory()
{
    return new CProMoControlFactory;
}

CProMoRenderer* CWPDemoPluginInterface::GetRenderer()
{
    return new CProMoRenderer;
}
