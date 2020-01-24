#include "preferencesdialog.h"
#include <wx/dirdlg.h>

//(*InternalHeaders(PreferencesDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(PreferencesDialog)
const long PreferencesDialog::ID_STATICTEXT1 = wxNewId();
const long PreferencesDialog::ID_TEXTCTRL1 = wxNewId();
const long PreferencesDialog::ID_BUTTON1 = wxNewId();
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
	FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer1->AddGrowableCol(1);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("QEMU Path"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pTxtQemuPath = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer1->Add(m_pTxtQemuPath, 1, wxALL|wxEXPAND, 5);
	m_pBtnQemuPath = new wxButton(this, ID_BUTTON1, _(".."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer1->Add(m_pBtnQemuPath, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON2, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PreferencesDialog::OnQemuPathChange);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PreferencesDialog::OnQemuPathButton);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PreferencesDialog::OnButtonClose);
	//*)

	if(!pConfig)
        Close();
	m_pConfig = pConfig;
	wxString sValue;
    m_pConfig->Read("Qemu/Path", &sValue);
	m_pTxtQemuPath->SetValue(sValue);
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

void PreferencesDialog::OnQemuPathChange(wxCommandEvent& event)
{
    m_pConfig->Write("Qemu/Path", event.GetString());
}

void PreferencesDialog::OnQemuPathButton(wxCommandEvent& event)
{
    wxString sPath;
    m_pConfig->Read("Qemu/Path", &sPath);
    wxDirDialog dlgPath(this, "Select path to QEMU executables", sPath);
    if(wxID_CANCEL == dlgPath.ShowModal())
        return;
    m_pTxtQemuPath->SetValue(dlgPath.GetPath());
}
