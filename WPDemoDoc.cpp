/* ==========================================================================

	Copyright © 2025 Technical University of Denmark

	Author :		Giovanni Meroni

   ========================================================================*/
#include "stdafx.h"
#include "WPDemoDoc.h"

IMPLEMENT_DYNCREATE(CWPDemoDoc, CWinProMoDoc)


CWPDemoDoc::CWPDemoDoc()
{

}

CWPDemoDoc::~CWPDemoDoc()
{
}

void CWPDemoDoc::CreateContainer()
{
	if (!m_objs) {
		m_objs = new CProMoEntityContainer("demoPlugin");
	}
}