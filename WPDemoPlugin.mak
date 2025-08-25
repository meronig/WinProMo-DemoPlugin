# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=DemoPlugin - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to DemoPlugin - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "DemoPlugin - Win32 Release" && "$(CFG)" !=\
 "DemoPlugin - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "WPDemoPlugin.mak" CFG="DemoPlugin - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DemoPlugin - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "DemoPlugin - Win32 Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "DemoPlugin - Win32 Debug"
CPP=cl.exe
RSC=rc.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "DemoPlugin - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\Release\DemoPlugin.dll"

CLEAN : 
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\WPDemoDoc.obj"
	-@erase "$(INTDIR)\WPDemoPlugin.obj"
	-@erase "$(INTDIR)\WPDemoPlugin.pch"
	-@erase "$(INTDIR)\WPDemoPlugin.res"
	-@erase "$(INTDIR)\WPDemoPluginInterface.obj"
	-@erase "$(INTDIR)\WPDemoView.obj"
	-@erase "$(OUTDIR)\DemoPlugin.exp"
	-@erase "$(OUTDIR)\DemoPlugin.lib"
	-@erase "..\Release\DemoPlugin.dll"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D WPDEMOPLUGIN_EXPORTS=1 /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GR /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D WPDEMOPLUGIN_EXPORTS=1\
 /Fp"$(INTDIR)/WPDemoPlugin.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/WPDemoPlugin.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/WPDemoPlugin.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 ../WinPromo/Release/WinProMo.lib /nologo /base:0x12000000 /subsystem:windows /dll /machine:I386 /out:"../Release/DemoPlugin.dll"
LINK32_FLAGS=../WinPromo/Release/WinProMo.lib /nologo /base:0x12000000\
 /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)/DemoPlugin.pdb"\
 /machine:I386 /out:"../Release/DemoPlugin.dll"\
 /implib:"$(OUTDIR)/DemoPlugin.lib" 
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WPDemoDoc.obj" \
	"$(INTDIR)\WPDemoPlugin.obj" \
	"$(INTDIR)\WPDemoPlugin.res" \
	"$(INTDIR)\WPDemoPluginInterface.obj" \
	"$(INTDIR)\WPDemoView.obj"

"..\Release\DemoPlugin.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DemoPlugin - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\Debug\DemoPlugin.dll"

CLEAN : 
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\WPDemoDoc.obj"
	-@erase "$(INTDIR)\WPDemoPlugin.obj"
	-@erase "$(INTDIR)\WPDemoPlugin.pch"
	-@erase "$(INTDIR)\WPDemoPlugin.res"
	-@erase "$(INTDIR)\WPDemoPluginInterface.obj"
	-@erase "$(INTDIR)\WPDemoView.obj"
	-@erase "$(OUTDIR)\DemoPlugin.exp"
	-@erase "$(OUTDIR)\DemoPlugin.lib"
	-@erase "$(OUTDIR)\DemoPlugin.pdb"
	-@erase "..\Debug\DemoPlugin.dll"
	-@erase "..\Debug\DemoPlugin.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D WPDEMOPLUGIN_EXPORTS=1 /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GR /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D\
 WPDEMOPLUGIN_EXPORTS=1 /Fp"$(INTDIR)/WPDemoPlugin.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/WPDemoPlugin.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/WPDemoPlugin.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 ../WinPromo/Debug/WinProMo.lib /nologo /base:0x12000000 /subsystem:windows /dll /debug /machine:I386 /out:"../Debug/DemoPlugin.dll"
LINK32_FLAGS=../WinPromo/Debug/WinProMo.lib /nologo /base:0x12000000\
 /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)/DemoPlugin.pdb" /debug\
 /machine:I386 /out:"../Debug/DemoPlugin.dll" /implib:"$(OUTDIR)/DemoPlugin.lib"\
 
LINK32_OBJS= \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WPDemoDoc.obj" \
	"$(INTDIR)\WPDemoPlugin.obj" \
	"$(INTDIR)\WPDemoPlugin.res" \
	"$(INTDIR)\WPDemoPluginInterface.obj" \
	"$(INTDIR)\WPDemoView.obj"

"..\Debug\DemoPlugin.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "DemoPlugin - Win32 Release"
# Name "DemoPlugin - Win32 Debug"

!IF  "$(CFG)" == "DemoPlugin - Win32 Release"

!ELSEIF  "$(CFG)" == "DemoPlugin - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "DemoPlugin - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GR /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D WPDEMOPLUGIN_EXPORTS=1\
 /Fp"$(INTDIR)/WPDemoPlugin.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\WPDemoPlugin.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "DemoPlugin - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D\
 "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D\
 WPDEMOPLUGIN_EXPORTS=1 /Fp"$(INTDIR)/WPDemoPlugin.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\WPDemoPlugin.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\WPDemoPlugin.cpp
DEP_CPP_WPDEM=\
	"..\WinProMo\DiagramEditor\DiagramClipboardHandler.h"\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\ProMoEditor\ProMoClipboardHandler.h"\
	"..\WinProMo\stdafx.h"\
	"..\WinProMo\WinProMoPluginInterface.h"\
	".\StdAfx.h"\
	".\WPDemoPluginInterface.h"\
	

"$(INTDIR)\WPDemoPlugin.obj" : $(SOURCE) $(DEP_CPP_WPDEM) "$(INTDIR)"\
 "$(INTDIR)\WPDemoPlugin.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\WPDemoPluginInterface.cpp
DEP_CPP_WPDEMO=\
	"..\WinProMo\DiagramEditor\DiagramClipboardHandler.h"\
	"..\WinProMo\DiagramEditor\DiagramEditor.h"\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramEntityContainer.h"\
	"..\WinProMo\DiagramEditor\DiagramLine.h"\
	"..\WinProMo\DiagramEditor\DiagramMenu.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\HitParams.h"\
	"..\WinProMo\DiagramEditor\HitParamsRect.h"\
	"..\WinProMo\DiagramEditor\Tokenizer.h"\
	"..\WinProMo\DiagramEditor\UndoItem.h"\
	"..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	"..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	"..\WinProMo\ProMoEditor\ProMoClipboardHandler.h"\
	"..\WinProMo\ProMoEditor\ProMoControlFactory.h"\
	"..\WinProMo\ProMoEditor\ProMoEdgeView.h"\
	"..\WinProMo\ProMoEditor\ProMoEditor.h"\
	"..\WinProMo\ProMoEditor\ProMoEntityContainer.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\stdafx.h"\
	"..\WinProMo\WinProMoDoc.h"\
	"..\WinProMo\WinProMoDocTemplate.h"\
	"..\WinProMo\WinProMoPluginInterface.h"\
	"..\WinProMo\WinProMoView.h"\
	".\StdAfx.h"\
	".\WPDemoDoc.h"\
	".\WPDemoPluginInterface.h"\
	".\WPDemoView.h"\
	

"$(INTDIR)\WPDemoPluginInterface.obj" : $(SOURCE) $(DEP_CPP_WPDEMO) "$(INTDIR)"\
 "$(INTDIR)\WPDemoPlugin.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\WPDemoView.cpp
DEP_CPP_WPDEMOV=\
	"..\WinProMo\DiagramEditor\DiagramClipboardHandler.h"\
	"..\WinProMo\DiagramEditor\DiagramEditor.h"\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramEntityContainer.h"\
	"..\WinProMo\DiagramEditor\DiagramLine.h"\
	"..\WinProMo\DiagramEditor\DiagramMenu.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\HitParams.h"\
	"..\WinProMo\DiagramEditor\HitParamsRect.h"\
	"..\WinProMo\DiagramEditor\Tokenizer.h"\
	"..\WinProMo\DiagramEditor\UndoItem.h"\
	"..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	"..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	"..\WinProMo\ProMoEditor\ProMoClipboardHandler.h"\
	"..\WinProMo\ProMoEditor\ProMoControlFactory.h"\
	"..\WinProMo\ProMoEditor\ProMoEdgeView.h"\
	"..\WinProMo\ProMoEditor\ProMoEditor.h"\
	"..\WinProMo\ProMoEditor\ProMoEntityContainer.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\stdafx.h"\
	"..\WinProMo\WinProMoDoc.h"\
	"..\WinProMo\WinProMoView.h"\
	".\StdAfx.h"\
	".\WPDemoView.h"\
	

"$(INTDIR)\WPDemoView.obj" : $(SOURCE) $(DEP_CPP_WPDEMOV) "$(INTDIR)"\
 "$(INTDIR)\WPDemoPlugin.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\WPDemoDoc.cpp
DEP_CPP_WPDEMOD=\
	"..\WinProMo\DiagramEditor\DiagramClipboardHandler.h"\
	"..\WinProMo\DiagramEditor\DiagramEntity.h"\
	"..\WinProMo\DiagramEditor\DiagramEntityContainer.h"\
	"..\WinProMo\DiagramEditor\DiagramPropertyDlg.h"\
	"..\WinProMo\DiagramEditor\Tokenizer.h"\
	"..\WinProMo\DiagramEditor\UndoItem.h"\
	"..\WinProMo\ProMoEditor\ProMoBlockModel.h"\
	"..\WinProMo\ProMoEditor\ProMoBlockView.h"\
	"..\WinProMo\ProMoEditor\ProMoClipboardHandler.h"\
	"..\WinProMo\ProMoEditor\ProMoControlFactory.h"\
	"..\WinProMo\ProMoEditor\ProMoEntityContainer.h"\
	"..\WinProMo\ProMoEditor\ProMoModel.h"\
	"..\WinProMo\ProMoEditor\PropertyDialog.h"\
	"..\WinProMo\stdafx.h"\
	"..\WinProMo\WinProMoDoc.h"\
	".\StdAfx.h"\
	".\WPDemoDoc.h"\
	

"$(INTDIR)\WPDemoDoc.obj" : $(SOURCE) $(DEP_CPP_WPDEMOD) "$(INTDIR)"\
 "$(INTDIR)\WPDemoPlugin.pch"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\WPDemoPlugin.rc
DEP_RSC_WPDEMOP=\
	".\res\ico00002.ico"\
	".\res\icon1.ico"\
	".\res\WinProMoDoc.ico"\
	".\res\WPDemoPlugin.rc2"\
	

"$(INTDIR)\WPDemoPlugin.res" : $(SOURCE) $(DEP_RSC_WPDEMOP) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
# End Target
# End Project
################################################################################
