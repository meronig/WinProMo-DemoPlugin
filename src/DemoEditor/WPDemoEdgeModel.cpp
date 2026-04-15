/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	CWPDemoEdgeModel

	Author :		Giovanni Meroni

	Purpose :		CWPDemoEdgeModel implements CProMoEdgeModel
					for the WinProMo Demo Plugin.

   ========================================================================*/

#include "StdAfx.h"
#include "WPDemoEdgeModel.h"
#include "../../../WinProMo/src/DiagramEditor/Tokenizer.h"
#include "../../../WinProMo/src/FileUtils/FileParser.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoProperty.h"

CWPDemoEdgeModel::CWPDemoEdgeModel()
/* ============================================================
	Function :		CWPDemoEdgeModel::CWPDemoEdgeModel
	Description :	Constructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Override to set the type of the model element to a
					unique string, (e.g., "my_edge_model") and call
					CreateProperties to add additional properties to 
					the model.

============================================================*/
{
	SetType(_T("promo_edge_model"));
	CreateProperties();
}

CWPDemoEdgeModel::~CWPDemoEdgeModel()
/* ============================================================
	Function :		CWPDemoEdgeModel::~CWPDemoEdgeModel
	Description :	Destructor
	Access :		Public

	Return :		void
	Parameters :	none

============================================================*/
{
}

CProMoModel* CWPDemoEdgeModel::Clone()
/* ============================================================
	Function :		CWPDemoEdgeModel::Clone
	Description :	Clones this object and returns a new one.
	Access :		Public

	Return :		CProMoModel*	-	The resulting clone
	Parameters :	none

	Usage :			Call to clone the current object.

============================================================*/
{
	CWPDemoEdgeModel* obj = new CWPDemoEdgeModel;
	return obj;
}

BOOL CWPDemoEdgeModel::CanConnectSource(CProMoBlockModel* source) const
/* ============================================================
	Function :		CWPDemoEdgeModel::CanConnectSource
	Description :	Returns if the object being passed as input
					parameter can be a source object.
	Access :		Public

	Return :		BOOL						-	"TRUE" if the
													object can be
													a source
	Parameters :	CProMoBlockModel* source	-	the object
													that should
													be the source
	Usage:			Override to implement diagram-specific logic. 
					By default, any block can be a source. Add 
					custom logic as needed.
   ============================================================*/
{
	BOOL result = CProMoEdgeModel::CanConnectSource(source);
	if (result) {
		// add custom logic here
	}
	return result;
}


BOOL CWPDemoEdgeModel::CanConnectDestination(CProMoBlockModel* destination) const
/* ============================================================
	Function :		CWPDemoEdgeModel::CanConnectDestination
	Description :	Returns if the object being passed as input
					parameter can be a destination object.
	Access :		Public

	Return :		BOOL							-	"TRUE" if
														the object
														can be a
														destination
	Parameters :	CProMoBlockModel* destination	-	the
														object
														that
														should
														be the
														destination
	Usage:			Override to implement diagram-specific logic. 
					By default, any block can be a destination. Add 
					custom logic as needed.
   ============================================================*/
{
	BOOL result = CProMoEdgeModel::CanConnectDestination(destination);
	if (result) {
		// add custom logic here
	}
	return result;
}

CProMoModel* CWPDemoEdgeModel::CreateFromString(const CString& str)
/* ============================================================
	Function :		CWPDemoEdgeModel::CreateFromString
	Description :	Static factory function that creates and
					returns an instance of this class if "str"
					is a valid representation.
	Access :		Public

	Return :		CProMoModel*		-	The object, or "NULL"
											if "str" is not a
											representation of
											this type.
	Parameters :	const CString& str	-	The string to create
											from.

	Usage :			Can be used as a factory for text file loads.
					Each object type should have its own
					version - the default one is a model
					implementation.

   ============================================================*/
{

	CWPDemoEdgeModel* obj = new CWPDemoEdgeModel;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}

	return obj;

}

void CWPDemoEdgeModel::CreateProperties()
/* ============================================================
	Function :		CWPDemoEdgeModel::CreateProperties
	Description :	Creates the properties for this object.
	Access :		Protected

	Return :		void
	Parameters :	none

	Usage :			Override to add properties to the model. Call
					the base class version to add the Title property
					(e.g., "Name") and then add the	custom ones using
					AddProperty.

   ============================================================*/
{
	CProMoModel::CreateProperties();
	CVariantWrapper wrapper;
	wrapper.SetInt(0);
	AddProperty(new CProMoProperty(_T("MyEdgeProperty"), PROPTYPE_INT, wrapper, FALSE, TRUE, TRUE, this));
}

void CWPDemoEdgeModel::CustomizeLabel(CProMoLabel* label)
/* ============================================================
	Function :		CWPDemoEdgeModel::CustomizeLabel
	Description :	Customizes the input label.
	Access :		Public

	Return :		void
	Parameters :	CProMoLabel*		-	A pointer to the
											label to customize
	Usage :			Override to customize the appearance of the
					labels linked to this model. Must call the base
					class version to reposition the label.

   ============================================================*/
{
	if (label) {
		if (label->GetPropertyName() == CString("MyEdgeProperty")) {
			// Position the label representing MyEdgeProperty in the middle of the edge, and above it
			label->SetViewAnchorPoint(DEHT_CENTER);
			label->SetLabelAnchorPoint(DEHT_TOPMIDDLE);

			// If the value of MyEdgeProperty is 0, hide the label and make it non-selectable, otherwise show it and make it selectable
			if (GetPropertyValue("MyEdgeProperty").GetInt() == 0) {
				label->SetVisible(FALSE);
				label->SetLock(label->GetLock() | LOCK_SELECTION);
			}
			else {
				label->SetVisible(TRUE);
				label->SetLock(label->GetLock() & ~LOCK_SELECTION);
			}
		}
		if (label->GetPropertyName() == CString("Title")) {
			// Position the label representing Title in the middle of the edge, and below it
			label->SetViewAnchorPoint(DEHT_CENTER);
			label->SetLabelAnchorPoint(DEHT_BOTTOMMIDDLE);
		}
	}

	CProMoModel::CustomizeLabel(label);
}

void CWPDemoEdgeModel::OnPropertyChanged(CProMoProperty* prop)
/* ============================================================
	Function :		CWPDemoEdgeModel::OnPropertyChanged
	Description :	Notification that a property has changed.
	Access :		Public

	Return :		void
	Parameters :	CProMoProperty* prop	-	Property that
												changed.

	Usage :			Can be called by a property to notify the
					model that it changed, and to trigger UI
					updates. Must call the base class version to
					update the label text, and then add custom logic.

   ============================================================*/
{
	CProMoModel::OnPropertyChanged(prop);

	CustomizeLabel(GetLabel(prop->GetFullName()));

}