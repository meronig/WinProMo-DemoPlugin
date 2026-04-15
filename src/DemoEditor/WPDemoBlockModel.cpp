/* ==========================================================================

	Copyright © 2025-26 Technical University of Denmark

	CWPDemoBlockModel

	Author :		Giovanni Meroni

	Purpose :		CWPDemoBlockModel implements CProMoBlockModel
					for the WinProMo Demo Plugin.

   ========================================================================*/

#include "StdAfx.h"
#include "WPDemoBlockModel.h"
#include "../../../WinProMo/src/DiagramEditor/Tokenizer.h"
#include "../../../WinProMo/src/FileUtils/FileParser.h"
#include "../../../WinProMo/src/ProMoEditor/ProMoProperty.h"

CWPDemoBlockModel::CWPDemoBlockModel()
/* ============================================================
	Function :		CWPDemoBlockModel::CWPDemoBlockModel
	Description :	Constructor
	Access :		Public

	Return :		void
	Parameters :	none

	Usage :			Override to set the type of the model element to a
					unique string, (e.g., "my_block_model") and call
					CreateProperties to add additional properties to 
					the model.

============================================================*/
{
	SetType(_T("promo_block_model"));
	CreateProperties();
}

CWPDemoBlockModel::~CWPDemoBlockModel()
/* ============================================================
	Function :		CProMoBlockModel::~CProMoBlockModel
	Description :	Destructor
	Access :		Public

	Return :		void
	Parameters :	none

============================================================*/
{
}

CProMoModel* CWPDemoBlockModel::Clone()
/* ============================================================
	Function :		CWPDemoBlockModel::Clone
	Description :	Clones this object and returns a new one.
	Access :		Public

	Return :		CProMoModel*	-	The resulting clone
	Parameters :	none

	Usage :			Call to clone the current object.

============================================================*/
{
	CWPDemoBlockModel* obj = new CWPDemoBlockModel;
	return obj;
}

BOOL CWPDemoBlockModel::CanBeSubBlockOf(CProMoBlockModel* block) const
/* ============================================================
	Function :		CWPDemoBlockModel::CanBeSubBlockOf
	Description :	Returns if this block can be a subblock of the
					block being passed as input	parameter.
	Access :		Public

	Return :		BOOL					-	"TRUE" if the
												block can be
												nested
	Parameters :	CProMoBlockModel* block	-	the block that
												should nest
												this block
	Usage:			Override to implement diagram-specific logic. 
					By default, all blocks that are not the same 
					as or a grand(parent) of this block can 
					be subblocks of it.

   ============================================================*/
{
	BOOL result = CProMoBlockModel::CanBeSubBlockOf(block);
	if (result) {
		// add custom logic here
	}
	return result;
}

BOOL CWPDemoBlockModel::CanBeBoundaryOf(CProMoBlockModel* block, unsigned int alignment) const
/* ============================================================
	Function :		CWPDemoBlockModel::CanBeBoundaryOf
	Description :	Returns if this block can be a boundary
					block of the block being passed as input
					parameter.
	Access :		Public

	Return :		BOOL					-	"TRUE" if the
												block can be
												a boundary
												block
	Parameters :	CProMoBlockModel* block	-	the block that
												should have
												this block as
												boundary
					unsigned int alignment	-	the type of
												attachment for
												the boundary
												block
	Usage:			Override to implement diagram-specific logic.
					By default, all blocks can be boundary blocks for all
					attachment types, a block cannot be a boundary block 
					of itself, and circular nesting is not allowed.

   ============================================================*/
{
	BOOL result = CProMoBlockModel::CanBeBoundaryOf(block, alignment);
	if (result) {
		// add custom logic here
	}
	return result;
}

CProMoModel* CWPDemoBlockModel::CreateFromString(const CString& str)
/* ============================================================
	Function :		CWPDemoBlockModel::CreateFromString
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

	CWPDemoBlockModel* obj = new CWPDemoBlockModel;
	if (!obj->FromString(str))
	{
		delete obj;
		obj = NULL;
	}

	return obj;

}

void CWPDemoBlockModel::CreateProperties()
/* ============================================================
	Function :		CWPDemoBlockModel::CreateProperties
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
	wrapper.SetInt(1);
	AddProperty(new CProMoProperty(_T("MyBlockProperty"), PROPTYPE_INT, wrapper, FALSE, FALSE, TRUE, this));
}

void CWPDemoBlockModel::CustomizeLabel(CProMoLabel* label)
/* ============================================================
	Function :		CWPDemoBlockModel::CustomizeLabel
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
		if (label->GetPropertyName() == CString("Title") && label->GetModel()) {
			//Make the label bounding box as large as the block, and reposition the label to the top middle of the block
			label->SetFitView(TRUE);
			label->SetLock(LOCK_REPOSITIONING);

			CObArray subBlocks;
			GetSubBlocks(subBlocks);
			// if the block has subblocks, position the label at the top middle of the block, otherwise center it
			if (subBlocks.GetSize() > 0) {
				label->SetViewAnchorPoint(DEHT_TOPMIDDLE);
				label->SetLabelAnchorPoint(DEHT_TOPMIDDLE);
			}
			else {
				label->SetViewAnchorPoint(DEHT_CENTER);
				label->SetLabelAnchorPoint(DEHT_CENTER);
			}
		}
	}

	CProMoModel::CustomizeLabel(label);
}