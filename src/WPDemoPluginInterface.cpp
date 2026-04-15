/* ==========================================================================

    Copyright © 2025-26 Technical University of Denmark

    CWPDemoPluginInterface

    Author :		Giovanni Meroni

	Purpose :		CWPDemoPluginInterface implements CWinProMoPluginInterface 
                    for the WinProMo Demo Plugin. 

   ========================================================================*/
#include "stdafx.h"
#include "WPDemoPluginInterface.h"
#include "resource.h"
#include "DemoEditor/WPDemoControlFactory.h"
#include "DemoEditor/WPDemoCmdHandler.h"

CWPDemoPluginInterface::CWPDemoPluginInterface()
    : CWinProMoPluginInterface(IDR_WPPLUGIN, _T("demoPlugin"), _T("WinProMo Demo Plugin Diagram"), new CWPDemoControlFactory())
/* =========================================================================
    Function :		CWPDemoPluginInterface::CWPDemoPluginInterface
    Description :	Constructor
    Access :		Public
    Return :    	void
	Parameters :	none
    Notes :			Customize the parameters passed to the base constructor to
                    set the document ID, type, description, and control factory
                    of your plugin. The document ID should be a unique integer
                    (e.g., 1234) that identifies the type of documents created by
                    the plugin. The document type should be a unique string (e.g.,
                    "demoPlugin") that identifies the type of documents created by
                    the plugin. The document description is a string that describes
                    the type of documents created by the plugin and is shown in the
                    "New" dialog when creating a new document. The control factory is
                    responsible for creating the controls of the diagram (e.g., nodes,
                    edges, labels, etc.) and their properties. You can create a custom
                    control factory by deriving from CProMoControlFactory and overriding
					its methods to create your custom controls.
* ========================================================================*/
{
}

CObArray* CWPDemoPluginInterface::GetElements()
/* =========================================================================
    Function :		CWPDemoPluginInterface::GetElements
    Description :	Returns the list of elements to be added to the Insert
					menu and the tool palette. Each element is represented by 
					a CWinProMoPluginCommand object. To display a separator, 
					add a command with ID=0 and caption="-". To group commands 
                    in a submenu, add a command with subcommands (m_subCommands) 
                    containing the submenu commands.
	Access :		Public
    Return :    	CObArray* : list of CWinProMoPluginCommand objects
    Parameters :	none
	Notes :			Customize this method to add the elements of your diagram. 
                    The command ID of each element will be passed to the 
                    command handler (GetCmdHandler) when the element is 
                    selected, so make sure to set it to a unique value and 
                    handle it in the command handler.
* ========================================================================*/
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
/* =========================================================================
    Function :		CWPDemoPluginInterface::GetCommands
    Description :	Returns the list of elements to be added as additional
                    menu entries (after the x menu) and toolbars. Each element
                    is represented by a CWinProMoPluginCommand object. To 
                    display a separator, add a command with ID=0 and 
                    caption="-". To group commands in a submenu, add a 
                    command with subcommands (m_subCommands) containing the 
                    submenu commands.
    Access :		Public
    Return :    	CObArray* : list of CWinProMoPluginCommand objects
    Parameters :	none
    Notes :			Customize this method if you need any plugin-specific
                    functionality (e.g., model checking) to be accessible 
                    to the end-user.
* ========================================================================*/
{
    return NULL;
}

CProMoCmdHandler* CWPDemoPluginInterface::GetCmdHandler()
/* =========================================================================
    Function :		CWPDemoPluginInterface::GetCmdHandler
    Description :	Returns a pointer to the command handler of the plugin. The
                    command handler is responsible for handling the commands 
                    defined in GetElements and GetCommands.
    Access :		Public
    Return :    	CProMoCmdHandler* : pointer to the command handler
    Parameters :	none
    Notes :			Customize this method to return an instance of your plugin's
                    command handler. Make sure that the command handler properly
					handles all the commands defined in GetElements and GetCommands.
* ========================================================================*/
{
    return new CWPDemoCmdHandler;
}