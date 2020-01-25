#include "preferencesdialog.h"
#include <wx/dirdlg.h>

//(*InternalHeaders(PreferencesDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(PreferencesDialog)
const long PreferencesDialog::ID_STATICTEXT1 = wxNewId();
const long PreferencesDialog::ID_DIRPICKERCTRL1 = wxNewId();
const long PreferencesDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PreferencesDialog,wxDialog)
	//(*EventTable(PreferencesDialog)
	//*)
END_EVENT_TABLE()

PreferencesDialog::PreferencesDialog(wxWindow* parent, wxConfig* pConfig)
{
	//(*Initialize(PreferencesDialog)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Preferences"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer1->AddGrowableCol(1);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("QEMU Path"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pDirPicker = new wxDirPickerCtrl(this, ID_DIRPICKERCTRL1, wxEmptyString, _("Select QEMU path"), wxDefaultPosition, wxDefaultSize, wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_DIRPICKERCTRL1"));
	FlexGridSizer1->Add(m_pDirPicker, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON2, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PreferencesDialog::OnButtonClose);
	//*)

	if(!pConfig)
        Close();
	m_pConfig = pConfig;
	wxString sValue;
	m_pConfig->SetPath("/");
    m_pConfig->Read("QEMU/Path", &sValue);
    m_pDirPicker->SetPath(sValue);
}

PreferencesDialog::~PreferencesDialog()
{
	//(*Destroy(PreferencesDialog)
	//*)
}


void PreferencesDialog::OnButtonClose(wxCommandEvent& event)
{
    Close();
}

void PreferencesDialog::OnQemuPathChange(wxFileDirPickerEvent& event)
{
    m_pConfig->Write("QEMU/Path", event.GetPath());
}
