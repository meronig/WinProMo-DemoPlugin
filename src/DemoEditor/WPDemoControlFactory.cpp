/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	CWPDemoControlFactory

	Author :		Giovanni Meroni

	Purpose :		CWPDemoControlFactory implements CProMoControlFactory
					for the WinProMo Demo Plugin.

   ========================================================================*/

#include "StdAfx.h"
#include "WPDemoControlFactory.h"
#include "WPDemoEdgeModel.h"
#include "WPDemoEdgeView.h"
#include "WPDemoBlockModel.h"
#include "WPDemoBlockView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWPDemoControlFactory

CDiagramEntity* CWPDemoControlFactory::CreateViewFromString(const CString& str)
/* ============================================================
	Function :		CWPDemoControlFactory::CreateViewFromString
	Description :	The function returns an object from the
					parameter str.

	Return :		CDiagramEntity*		-	The new object, or
											NULL is str is not a
											valid representation.
	Parameters :	const CString& str	-	The string to create
											a new object from

	Usage :			Call this function while reading
					string representations of objects from a
					text file. Note that the caller is
					responsible for the allocated memory.

   ============================================================*/
{
	CDiagramEntity* obj;

	obj = CWPDemoBlockView::CreateFromString(str);
	if (!obj)
		obj = CWPDemoEdgeView::CreateFromString(str);

	return obj;
}

CDiagramEntity* CWPDemoControlFactory::CreateViewFromString(const CString& str, CProMoModel* model)
/* ============================================================
	Function :		CWPDemoControlFactory::CreateViewFromString
	Description :	The function returns an object from the
					parameter str.

	Return :		CDiagramEntity*		-	The new object, or
											NULL is str is not a
											valid representation.
	Parameters :	const CString& str	-	The string to create
											a new object from
					CProMoModel* model	-	The model that will
											be linked to the
											created object

	Usage :			Call this static function while reading
					string representations of objects from a
					text file. Note that the caller is
					responsible for the allocated memory of
					the created object only. The created object
					will take ownership of the model being
					passed, which should be created on the heap.

   ============================================================*/
{
	CDiagramEntity* obj;

	obj = CWPDemoBlockView::CreateFromString(str, model);
	if (!obj)
		obj = CWPDemoEdgeView::CreateFromString(str, model);

	return obj;
}

CProMoModel* CWPDemoControlFactory::CreateModelFromString(const CString& str)
/* ============================================================
	Function :		CWPDemoControlFactory::CreateModelFromString
	Description :	The function returns an object from the
					parameter str.

	Return :		CDiagramEntity*		-	The new object, or
											NULL is str is not a
											valid representation.
	Parameters :	const CString& str	-	The string to create
											a new object from

	Usage :			Call this static function while reading
					string representations of objects from a
					text file. Note that the caller is
					responsible for the allocated memory.

   ============================================================*/
{
	CProMoModel* obj;

	obj = CWPDemoBlockModel::CreateFromString(str);
	if (!obj)
		obj = CWPDemoEdgeModel::CreateFromString(str);

	return obj;
}

CDiagramEntity* CWPDemoControlFactory::CreateNewEntity(const CString& str)
/* ============================================================
	Function :		CWPDemoControlFactory::CreateNewEntity
	Description :	The function returns an object with a type
					corresponding to the parameter str.
	Return :		CDiagramEntity*		-	The new object, or
											NULL if str is not a
											valid object type.
	Parameters :	const CString& str	-	The object type to
											create
	Usage :			Call this static function from the UI or the
					automation interface to create new objects
					of the specified type. Note that the caller
					is responsible for the allocated memory.
   ============================================================*/
{
	CDiagramEntity* obj;

	obj = CWPDemoBlockView::Create(str);
	
	if (!obj)
		obj = CWPDemoEdgeView::Create(str);

	return obj;
}

void CWPDemoControlFactory::GetEntityTypes(CStringArray& typeList)
/* ============================================================
	Function :		CWPDemoControlFactory::GetEntityTypes
	Description :	Fills the provided list with the types of
					objects that can be created by this factory.
	Return :		void
	Parameters :	CStringArray& typeList	-	The list to fill
	Usage :			Call this function to get the list of
					available object types for use in the UI
					or the automation interface.
   ============================================================*/
{
	// Clear the list
	typeList.RemoveAll();
	// Add block types
	CDiagramEntity* obj = new CWPDemoBlockView;
	typeList.Add(obj->GetType());
	delete obj;
	// Add edge types
	obj = new CWPDemoEdgeView;
	typeList.Add(obj->GetType());
	delete obj;
}
