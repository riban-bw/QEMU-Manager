#include "newimage.h"

//(*InternalHeaders(NewImage)
#include <wx/button.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(NewImage)
const long NewImage::ID_STATICTEXT1 = wxNewId();
const long NewImage::ID_CHOICE1 = wxNewId();
const long NewImage::ID_STATICTEXT2 = wxNewId();
const long NewImage::ID_FILEPICKERCTRL1 = wxNewId();
const long NewImage::ID_STATICTEXT3 = wxNewId();
const long NewImage::ID_FILEPICKERCTRL2 = wxNewId();
const long NewImage::ID_STATICTEXT4 = wxNewId();
const long NewImage::ID_TEXTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(NewImage,wxDialog)
	//(*EventTable(NewImage)
	//*)
END_EVENT_TABLE()

NewImage::NewImage(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(NewImage)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxStdDialogButtonSizer* StdDialogButtonSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer2->AddGrowableCol(1);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pCmbDiskType = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	m_pCmbDiskType->SetSelection( m_pCmbDiskType->Append(_("qcow2")) );
	m_pCmbDiskType->Append(_("raw"));
	FlexGridSizer2->Add(m_pCmbDiskType, 1, wxALL|wxEXPAND, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pFilePickerImage = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL1, wxEmptyString, _("Select path and filename for new file"), _T("Disk Images (*.qcow;*.qcow2;*.img;*.raw)|*.qcow;*.qcow2;*.img;*.raw|All files (*.*)|*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
	FlexGridSizer2->Add(m_pFilePickerImage, 1, wxALL|wxEXPAND, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Base Image"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer2->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pFilePickerBaseImage = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL2, wxEmptyString, _("Select disk image to shadow"), _T("Disk Images (*.qcow;*.qcow2;*.img;*.raw)|*.qcow;*.qcow2;*.img;*.raw|All files (*.*)|*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_FILEPICKERCTRL2"));
	FlexGridSizer2->Add(m_pFilePickerBaseImage, 1, wxALL|wxEXPAND, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("(Max) Size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer2->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pTxtSize = new wxTextCtrl(this, ID_TEXTCTRL1, _("20G"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer2->Add(m_pTxtSize, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StdDialogButtonSizer1 = new wxStdDialogButtonSizer();
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_OK, _("Create Image")));
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_CANCEL, wxEmptyString));
	StdDialogButtonSizer1->Realize();
	FlexGridSizer1->Add(StdDialogButtonSizer1, 1, wxALL|wxEXPAND, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	//*)
}

NewImage::~NewImage()
{
	//(*Destroy(NewImage)
	//*)
}

