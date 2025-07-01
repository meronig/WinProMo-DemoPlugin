#include "stdafx.h"
#include "WPDemoPluginInterface.h"
#include "resource.h"
#include "WPDemoView.h"
#include "WPDemoDoc.h"
#include "../WinProMo/WinProMoDocTemplate.h"

CMultiDocTemplate* CWPDemoPluginInterface::RegisterPlugin(CRuntimeClass* pFrameClass, CProMoClipboardHandler* pClip)
{
    static CMultiDocTemplate* g_pTemplate = NULL;

    if (!g_pTemplate)
    {
        g_pTemplate = new CWinProMoDocTemplate(
            IDR_WPPLUGIN,
            RUNTIME_CLASS(CWPDemoDoc),
            pFrameClass,
            RUNTIME_CLASS(CWPDemoView),
            pClip
        );
    }

    return g_pTemplate;
}

CObArray* CWPDemoPluginInterface::GetElements()
{
    CObArray* commands = new CObArray();
    if (commands) {
        CWinProMoPluginCommand* cmd1 = new CWinProMoPluginCommand();
        cmd1->m_commandID = ID_INSERT_NODE;
        cmd1->m_caption = _T("Node");
        cmd1->m_icon = AfxGetApp()->LoadIcon(IDI_ICON_NODE);
        cmd1->m_subCommands = NULL;

        CWinProMoPluginCommand* space1 = new CWinProMoPluginCommand();
        space1->m_commandID = 0;
        space1->m_caption = _T("-");
        space1->m_icon = NULL;
        space1->m_subCommands = NULL;

        CWinProMoPluginCommand* cmd2 = new CWinProMoPluginCommand();
        cmd2->m_commandID = ID_INSERT_EDGE;
        cmd2->m_caption = _T("Edge");
        cmd2->m_icon = AfxGetApp()->LoadIcon(IDI_ICON_EDGE);
        cmd2->m_subCommands = NULL;

        commands->Add(cmd1);
        commands->Add(space1);
        commands->Add(cmd2);
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
    return IDR_WPDPLUGIN;
}

void CWPDemoPluginInterface::Destroy()
{
    delete this;
}
