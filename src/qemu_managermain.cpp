/***************************************************************
 * Name:      qemu_managermain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2020-01-23
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL-V3
 **************************************************************/

#include "qemu_managermain.h"
#include <wx/msgdlg.h>
#include <wx/dir.h>
#include <wx/display.h>
#include <wx/filename.h>
#include "preferencesdialog.h"
#include "icon.xpm"
#include <wx/process.h>

using namespace std;

//(*InternalHeaders(QEMU_ManagerFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(QEMU_ManagerFrame)
const long QEMU_ManagerFrame::ID_LISTBOX1 = wxNewId();
const long QEMU_ManagerFrame::ID_SCROLLEDWINDOW1 = wxNewId();
const long QEMU_ManagerFrame::ID_STATICTEXT1 = wxNewId();
const long QEMU_ManagerFrame::ID_TEXTCTRL1 = wxNewId();
const long QEMU_ManagerFrame::ID_STATICTEXT2 = wxNewId();
const long QEMU_ManagerFrame::ID_CHOICE1 = wxNewId();
const long QEMU_ManagerFrame::ID_STATICTEXT3 = wxNewId();
const long QEMU_ManagerFrame::ID_FILEPICKERCTRL1 = wxNewId();
const long QEMU_ManagerFrame::ID_STATICTEXT4 = wxNewId();
const long QEMU_ManagerFrame::ID_TEXTCTRL3 = wxNewId();
const long QEMU_ManagerFrame::ID_STATICTEXT6 = wxNewId();
const long QEMU_ManagerFrame::ID_CHECKBOX1 = wxNewId();
const long QEMU_ManagerFrame::ID_STATICTEXT5 = wxNewId();
const long QEMU_ManagerFrame::ID_TEXTCTRL4 = wxNewId();
const long QEMU_ManagerFrame::ID_STATICTEXT7 = wxNewId();
const long QEMU_ManagerFrame::ID_STATICTEXT8 = wxNewId();
const long QEMU_ManagerFrame::ID_SCROLLEDWINDOW2 = wxNewId();
const long QEMU_ManagerFrame::ID_SPLITTERWINDOW1 = wxNewId();
const long QEMU_ManagerFrame::idMenuQuit = wxNewId();
const long QEMU_ManagerFrame::idMenuAbout = wxNewId();
const long QEMU_ManagerFrame::ID_STATUSBAR1 = wxNewId();
const long QEMU_ManagerFrame::ID_TOOLBAR_NEW = wxNewId();
const long QEMU_ManagerFrame::ID_TOOLBAR_DELETE = wxNewId();
const long QEMU_ManagerFrame::ID_TOOLBAR_START = wxNewId();
const long QEMU_ManagerFrame::ID_TOOLBAR_RESTART = wxNewId();
const long QEMU_ManagerFrame::ID_TOOLBAR_STOP = wxNewId();
const long QEMU_ManagerFrame::ID_TOOLBAR_PREFERENCES = wxNewId();
const long QEMU_ManagerFrame::ID_TOOLBAR1 = wxNewId();
const long QEMU_ManagerFrame::ID_TIMER = wxNewId();
//*)

BEGIN_EVENT_TABLE(QEMU_ManagerFrame,wxFrame)
    //(*EventTable(QEMU_ManagerFrame)
    //*)
    EVT_CLOSE(QEMU_ManagerFrame::OnClose)
END_EVENT_TABLE()

QEMU_ManagerFrame::QEMU_ManagerFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(QEMU_ManagerFrame)
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("riban QEMU Manager"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(icon);
    	SetIcon(FrameIcon);
    }
    SplitterWindow1 = new wxSplitterWindow(this, ID_SPLITTERWINDOW1, wxPoint(152,216), wxDefaultSize, wxSP_3D, _T("ID_SPLITTERWINDOW1"));
    SplitterWindow1->SetMinimumPaneSize(10);
    SplitterWindow1->SetSashGravity(0.5);
    ScrolledWindow1 = new wxScrolledWindow(SplitterWindow1, ID_SCROLLEDWINDOW1, wxPoint(144,286), wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
    FlexGridSizer3 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer3->AddGrowableCol(0);
    FlexGridSizer3->AddGrowableRow(0);
    m_pLstVms = new wxListBox(ScrolledWindow1, ID_LISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    FlexGridSizer3->Add(m_pLstVms, 0, wxEXPAND, 0);
    ScrolledWindow1->SetSizer(FlexGridSizer3);
    FlexGridSizer3->Fit(ScrolledWindow1);
    FlexGridSizer3->SetSizeHints(ScrolledWindow1);
    ScrolledWindow2 = new wxScrolledWindow(SplitterWindow1, ID_SCROLLEDWINDOW2, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW2"));
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(1);
    StaticText1 = new wxStaticText(ScrolledWindow2, ID_STATICTEXT1, _("Name"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT|wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
    FlexGridSizer2->Add(StaticText1, 1, wxALL|wxEXPAND, 5);
    m_pTxtName = new wxTextCtrl(ScrolledWindow2, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer2->Add(m_pTxtName, 1, wxALL|wxEXPAND, 5);
    StaticText2 = new wxStaticText(ScrolledWindow2, ID_STATICTEXT2, _("System"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pCmbSystem = new wxChoice(ScrolledWindow2, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    FlexGridSizer2->Add(m_pCmbSystem, 1, wxALL|wxEXPAND, 5);
    StaticText3 = new wxStaticText(ScrolledWindow2, ID_STATICTEXT3, _("Disk Image"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer2->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pTxtImage = new wxFilePickerCtrl(ScrolledWindow2, ID_FILEPICKERCTRL1, wxEmptyString, _("Select disk image"), _T("Disk Images (*.qcow;*.qcow2;*.img;*.raw)|*.qcow;*.qcow2;*.img;*.raw|All files (*.*)|*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
    FlexGridSizer2->Add(m_pTxtImage, 1, wxALL|wxEXPAND, 5);
    StaticText4 = new wxStaticText(ScrolledWindow2, ID_STATICTEXT4, _("Memory (MB)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer2->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pTxtMemory = new wxTextCtrl(ScrolledWindow2, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer2->Add(m_pTxtMemory, 1, wxALL|wxEXPAND, 5);
    StaticText6 = new wxStaticText(ScrolledWindow2, ID_STATICTEXT6, _("Show Display"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer2->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pChkShowDisplay = new wxCheckBox(ScrolledWindow2, ID_CHECKBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    m_pChkShowDisplay->SetValue(true);
    FlexGridSizer2->Add(m_pChkShowDisplay, 1, wxALL|wxEXPAND, 5);
    StaticText5 = new wxStaticText(ScrolledWindow2, ID_STATICTEXT5, _("Other parameters"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pTxtParams = new wxTextCtrl(ScrolledWindow2, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer2->Add(m_pTxtParams, 1, wxALL|wxEXPAND, 5);
    StaticText7 = new wxStaticText(ScrolledWindow2, ID_STATICTEXT7, _("Status"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer2->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pLblStatus = new wxStaticText(ScrolledWindow2, ID_STATICTEXT8, _("Unknown"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer2->Add(m_pLblStatus, 1, wxALL|wxEXPAND, 5);
    ScrolledWindow2->SetSizer(FlexGridSizer2);
    FlexGridSizer2->Fit(ScrolledWindow2);
    FlexGridSizer2->SetSizeHints(ScrolledWindow2);
    SplitterWindow1->SplitVertically(ScrolledWindow1, ScrolledWindow2);
    SplitterWindow1->SetSashPosition(100);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    m_pStatusbar = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    m_pStatusbar->SetFieldsCount(1,__wxStatusBarWidths_1);
    m_pStatusbar->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(m_pStatusbar);
    m_pToolbar = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER, _T("ID_TOOLBAR1"));
    m_pToolbtnNew = m_pToolbar->AddTool(ID_TOOLBAR_NEW, _("New VM"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NEW")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    m_pToolbtnDelete = m_pToolbar->AddTool(ID_TOOLBAR_DELETE, _("Delete VM"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_DELETE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    m_pToolbtnStart = m_pToolbar->AddTool(ID_TOOLBAR_START, _("Start VM"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_TICK_MARK")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    m_pToolbtnRestart = m_pToolbar->AddTool(ID_TOOLBAR_RESTART, _("Restart VM"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_REDO")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    m_pToolbtnKill = m_pToolbar->AddTool(ID_TOOLBAR_STOP, _("Kill VM"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_CROSS_MARK")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    m_pToolbtnPreferences = m_pToolbar->AddTool(ID_TOOLBAR_PREFERENCES, _("Preferences"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_LIST_VIEW")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    m_pToolbar->Realize();
    SetToolBar(m_pToolbar);
    m_pTimer.SetOwner(this, ID_TIMER);
    m_pTimer.Start(5000, false);

    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&QEMU_ManagerFrame::OnVmSelect);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&QEMU_ManagerFrame::OnVmNameChange);
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&QEMU_ManagerFrame::OnVmSystemChange);
    Connect(ID_FILEPICKERCTRL1,wxEVT_COMMAND_FILEPICKER_CHANGED,(wxObjectEventFunction)&QEMU_ManagerFrame::OnVmImageChange);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&QEMU_ManagerFrame::OnVmMemoryChange);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&QEMU_ManagerFrame::OnVmShowDisplayChange);
    Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&QEMU_ManagerFrame::OnVmParamsChange);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&QEMU_ManagerFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&QEMU_ManagerFrame::OnAbout);
    Connect(ID_TOOLBAR_NEW,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&QEMU_ManagerFrame::OnNewVm);
    Connect(ID_TOOLBAR_DELETE,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&QEMU_ManagerFrame::OnDeleteVm);
    Connect(ID_TOOLBAR_START,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&QEMU_ManagerFrame::OnStartVm);
    Connect(ID_TOOLBAR_STOP,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&QEMU_ManagerFrame::OnKillVm);
    Connect(ID_TOOLBAR_PREFERENCES,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&QEMU_ManagerFrame::OnPreferences);
    Connect(ID_TIMER,wxEVT_TIMER,(wxObjectEventFunction)&QEMU_ManagerFrame::OnTimer);
    //*)

    LoadConfig();
    LoadScreen();
    m_nCurrentVm = -1;
    RefreshVmList();
}

QEMU_ManagerFrame::~QEMU_ManagerFrame()
{
    //(*Destroy(QEMU_ManagerFrame)
    //*)
    while(m_vVm.size())
        DeleteVm(m_vVm[0]);
}

void QEMU_ManagerFrame::OnClose(wxCloseEvent& event)
{
    SaveConfig();
    SaveScreen();
    delete m_pConfig;
    m_pConfig = NULL;
    event.Skip();
}

void QEMU_ManagerFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void QEMU_ManagerFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("QEMU Manager\n\nriban (2020)", "About");
}

void QEMU_ManagerFrame::OnNewVm(wxCommandEvent& event)
{
    QemuVm* pVm = new QemuVm();
    m_vVm.push_back(pVm);
    m_nCurrentVm = m_vVm.size() - 1;
    RefreshVmList();
    OnVmSelect(event);
}

void QEMU_ManagerFrame::RefreshVmList()
{
    m_pLstVms->Clear();
    for(auto it = m_vVm.begin(); it != m_vVm.end(); ++it)
    {
        QemuVm* pVm = *it;
        m_pLstVms->Append(pVm->GetName(), pVm);
    }
    m_pLstVms->Select(m_nCurrentVm);
}

void QEMU_ManagerFrame::DeleteVm(QemuVm* pVm)
{
    if(!pVm)
        return;
    //!@todo Stop VM
    auto it = m_vVm.begin();
    for(; it != m_vVm.end(); ++it)
    {
        if(*it == pVm)
            break;
    }
    if(it == m_vVm.end())
        return;
    m_vVm.erase(it);
    m_nCurrentVm = m_vVm.size() - 1; //!@todo Only do this if vm selected or at end of list
    RefreshVmList();
    if(m_pConfig)
        m_pConfig->DeleteGroup(pVm->GetName());
    delete pVm;
}

void QEMU_ManagerFrame::OnDeleteVm(wxCommandEvent& event)
{
    int nSelection = m_pLstVms->GetSelection();
    if(nSelection == wxNOT_FOUND)
        return;
    QemuVm* pVm = (QemuVm*)m_pLstVms->GetClientData(nSelection);
    if(wxMessageBox("Do you want to delete: " + pVm->GetName(), "Please confirm", wxYES_NO) != wxYES)
        return;
    if(m_pConfig)
        m_pConfig->DeleteGroup(pVm->GetName());
    DeleteVm(pVm);
}

void QEMU_ManagerFrame::OnVmSelect(wxCommandEvent& event)
{
    int nSelection = m_pLstVms->GetSelection();
    if(nSelection == wxNOT_FOUND)
        return;
    QemuVm* pVm = (QemuVm*)m_pLstVms->GetClientData(nSelection);
    m_nCurrentVm = nSelection;
    m_pTxtName->SetValue(pVm->GetName());
    m_pTxtParams->SetValue(pVm->GetParams());
    m_pTxtImage->SetPath(pVm->GetImage());
    m_pTxtMemory->SetValue(wxString::Format("%d", pVm->GetMemory()));
    m_pCmbSystem->SetSelection(m_pCmbSystem->FindString(pVm->GetSystem()));
    m_pChkShowDisplay->SetValue(pVm->GetShowDisplay());
    bool bRunning = pVm->IsRunning();
    EnableEdit(!bRunning);
    wxString sStatus;
    if(bRunning)
        sStatus = wxString::Format("Running (PID: %d)", pVm->GetPid());
    else
        sStatus = "Stopped";
    m_pLblStatus->SetLabel(sStatus);
}

void QEMU_ManagerFrame::EnableEdit(bool bEnable)
{
    m_pTxtName->Enable(bEnable);
    m_pTxtParams->Enable(bEnable);
    m_pTxtImage->Enable(bEnable);
    m_pTxtMemory->Enable(bEnable);
    m_pCmbSystem->Enable(bEnable);
    m_pChkShowDisplay->Enable(bEnable);
}

void QEMU_ManagerFrame::SaveVm(QemuVm* pVm)
{
    if(!pVm || !m_pConfig)
        return;
    m_pConfig->SetPath("/VM");
    m_pConfig->Write(wxString::Format("%s/name", pVm->GetName().c_str()), pVm->GetName());
    m_pConfig->Write(wxString::Format("%s/system", pVm->GetName().c_str()), pVm->GetSystem());
    m_pConfig->Write(wxString::Format("%s/image", pVm->GetName().c_str()), pVm->GetImage());
    m_pConfig->Write(wxString::Format("%s/memory", pVm->GetName().c_str()), pVm->GetMemory());
    m_pConfig->Write(wxString::Format("%s/showdisplay", pVm->GetName().c_str()), pVm->GetShowDisplay());
    m_pConfig->Write(wxString::Format("%s/params", pVm->GetName().c_str()), pVm->GetParams());
    m_pConfig->Write(wxString::Format("%s/pid", pVm->GetName().c_str()), pVm->GetPid());
}

void QEMU_ManagerFrame::LoadConfig()
{
    if(!m_pConfig)
        m_pConfig = new wxConfig("qemumanager", "riban");
    m_pConfig->Read("QEMU/Path", &QemuVm::QEMU_PATH);
    wxString sKey;
    long lCookie;
    m_pConfig->SetPath("/VM");
    bool bMoreGroups = m_pConfig->GetFirstGroup(sKey, lCookie);
    while(bMoreGroups)
    {
        wxString sValue;
        long lValue;
        bool bValue;
        QemuVm* pVm = new QemuVm();
        m_pConfig->Read(sKey + "/name", &sValue);
        pVm->SetName(sValue);
        m_pConfig->Read(sKey + "/system", &sValue);
        pVm->SetSystem(sValue);
        m_pConfig->Read(sKey + "/image", &sValue);
        pVm->SetImage(sValue);
        m_pConfig->Read(sKey + "/params", &sValue);
        pVm->SetParams(sValue);
        m_pConfig->Read(sKey + "/memory", &lValue);
        pVm->SetMemory(lValue);
        m_pConfig->Read(sKey + "/showdisplay", &bValue, true);
        pVm->SetShowDisplay(bValue);
        m_pConfig->Read(sKey + "/pid", &lValue, 0);
        pVm->IsRunning(lValue);
        m_vVm.push_back(pVm);
        bMoreGroups = m_pConfig->GetNextGroup(sKey, lCookie);
    }
    PopulateSystems();
}

void QEMU_ManagerFrame::PopulateSystems()
{
    m_pCmbSystem->Clear();
    // Get the available systems from the executable file names
    wxArrayString asFiles;
    wxDir::GetAllFiles(QemuVm::QEMU_PATH, &asFiles, "qemu-system-*");
    for(unsigned int nIndex = 0; nIndex < asFiles.GetCount(); ++nIndex)
    {
        wxString sSystem = asFiles[nIndex].AfterLast('-');
        if(sSystem.BeforeFirst('.') != wxEmptyString)
            sSystem = sSystem.BeforeFirst('.'); // Remove filename extension if present
        m_pCmbSystem->Append(sSystem);
    }
}

void QEMU_ManagerFrame::SaveConfig()
{
    for(auto it = m_vVm.begin(); it != m_vVm.end(); ++it)
        SaveVm(*it);
}

void QEMU_ManagerFrame::OnPreferences(wxCommandEvent& event)
{
    PreferencesDialog dlgPref(this, m_pConfig);
    dlgPref.ShowModal();
    PopulateSystems();
}

QemuVm* QEMU_ManagerFrame::GetSelectedVm()
{
    int nSelection = m_pLstVms->GetSelection();
    if(nSelection == wxNOT_FOUND)
        return NULL;
    return (QemuVm*)m_pLstVms->GetClientData(nSelection);
}

void QEMU_ManagerFrame::OnVmNameChange(wxCommandEvent& event)
{
    QemuVm* pVm = GetSelectedVm();
    if(!pVm)
        return;
    pVm->SetName(event.GetString());
    RefreshVmList();
}

void QEMU_ManagerFrame::OnVmImageChange(wxFileDirPickerEvent& event)
{
    QemuVm* pVm = GetSelectedVm();
    if(!pVm)
        return;
    pVm->SetImage(event.GetPath());
}

void QEMU_ManagerFrame::OnVmMemoryChange(wxCommandEvent& event)
{
    QemuVm* pVm = GetSelectedVm();
    if(!pVm)
        return;
    long lValue;
    event.GetString().ToLong(&lValue);
    pVm->SetMemory(lValue);
}

void QEMU_ManagerFrame::OnVmParamsChange(wxCommandEvent& event)
{
    QemuVm* pVm = GetSelectedVm();
    if(!pVm)
        return;
    pVm->SetParams(event.GetString());
}

void QEMU_ManagerFrame::OnVmSystemChange(wxCommandEvent& event)
{
    QemuVm* pVm = GetSelectedVm();
    if(!pVm)
        return;
    pVm->SetSystem(event.GetString());
}

void QEMU_ManagerFrame::OnVmShowDisplayChange(wxCommandEvent& event)
{
    QemuVm* pVm = GetSelectedVm();
    if(!pVm)
        return;
    pVm->SetShowDisplay(event.IsChecked());
}

void QEMU_ManagerFrame::OnStartVm(wxCommandEvent& event)
{
    QemuVm* pVm = GetSelectedVm();
    if(!pVm)
        return;
    pVm->Start();
    EnableEdit(false);
    m_pLblStatus->SetLabel("Starting...");
}

void QEMU_ManagerFrame::SaveScreen()
{
    if(!m_pConfig)
        return;
    m_pConfig->SetPath("/ScreenLayout");
    m_pConfig->Write("maximised", IsMaximized());
    if(!IsMaximized())
    {
        m_pConfig->Write("width", GetSize().GetWidth());
        m_pConfig->Write("height", GetSize().GetHeight());
        m_pConfig->Write("left", GetPosition().x);
        m_pConfig->Write("top", GetPosition().y);
    }
}

void QEMU_ManagerFrame::LoadScreen()
{
    if(!m_pConfig)
        return;
    m_pConfig->SetPath("/ScreenLayout");
    int nX, nY, nWidth, nHeight;
    bool bMaximised;
    m_pConfig->Read(wxT("left"), &nX, 0);
    m_pConfig->Read(wxT("top"), &nY, 0);
    m_pConfig->Read(wxT("width"), &nWidth, 800);
    m_pConfig->Read(wxT("height"), &nHeight, 600);
    m_pConfig->Read(wxT("maximised"), &bMaximised, false);
    Maximize(bMaximised);
    SetSize(nWidth, nHeight);
    bool bCanSee = false;
	for(unsigned int nDisplay = 0; nDisplay < wxDisplay::GetCount(); nDisplay++)
    {
        bCanSee |= wxDisplay(nDisplay).GetGeometry().Intersects(wxRect(nX, nY, nWidth, nHeight));
    }
    if(bCanSee)
        Move(nX, nY);
}


void QEMU_ManagerFrame::OnStopVm(wxCommandEvent& event)
{
}

void QEMU_ManagerFrame::OnKillVm(wxCommandEvent& event)
{
    QemuVm* pVm = GetSelectedVm();
    if(!pVm)
        return;
    long lPid = pVm->GetPid();
    if(lPid > 0)
        wxProcess::Kill(lPid, wxSIGKILL);
}

void QEMU_ManagerFrame::OnTimer(wxTimerEvent& event)
{
    QemuVm* pVm = GetSelectedVm();
    if(!pVm)
        return;
    bool bRunning = pVm->IsRunning();
    EnableEdit(!bRunning);
    wxString sStatus;
    if(bRunning)
        sStatus = wxString::Format("Running (PID: %d)", pVm->GetPid());
    else
        sStatus = "Stopped";
    m_pLblStatus->SetLabel(sStatus);

}
