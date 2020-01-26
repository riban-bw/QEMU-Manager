/***************************************************************
 * Name:      qemu_managermain.h
 * Purpose:   Defines Application Frame
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2020-01-23
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL-V3
 **************************************************************/

#pragma once

//(*Headers(QEMU_ManagerFrame)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/filepicker.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/splitter.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
#include <wx/toolbar.h>
//*)
#include <vector>
#include "qemuvm.h"
#include <wx/config.h>
#include <wx/socket.h>

class QEMU_ManagerFrame: public wxFrame
{
    public:

        QEMU_ManagerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~QEMU_ManagerFrame();

    private:

        //(*Handlers(QEMU_ManagerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnNewVm(wxCommandEvent& event);
        void OnDeleteVm(wxCommandEvent& event);
        void OnVmSelect(wxCommandEvent& event);
        void OnVmNameChange(wxCommandEvent& event);
        void OnPreferences(wxCommandEvent& event);
        void OnVmMemoryChange(wxCommandEvent& event);
        void OnVmParamsChange(wxCommandEvent& event);
        void OnVmSystemChange(wxCommandEvent& event);
        void OnVmImageChange(wxFileDirPickerEvent& event);
        void OnStartVm(wxCommandEvent& event);
        void OnVmShowDisplayChange(wxCommandEvent& event);
        void OnStopVm(wxCommandEvent& event);
        void OnKillVm(wxCommandEvent& event);
        void OnTimer(wxTimerEvent& event);
        void OnVmCdromChange(wxFileDirPickerEvent& event);
        void OnNewHdd(wxCommandEvent& event);
        void OnLogDClick(wxCommandEvent& event);
        void OnEnableCdrom(wxCommandEvent& event);
        //*)

        //(*Identifiers(QEMU_ManagerFrame)
        static const long ID_LISTBOX1;
        static const long ID_SCROLLEDWINDOW1;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT3;
        static const long ID_FILEPICKERCTRL1;
        static const long ID_BUTTON_NEWHDD;
        static const long ID_STATICTEXT9;
        static const long ID_FILEPICKERCTRL2;
        static const long ID_CHECKBOX2;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT6;
        static const long ID_CHECKBOX1;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_PANEL1;
        static const long ID_LISTBOX2;
        static const long ID_PANEL2;
        static const long ID_NOTEBOOK1;
        static const long ID_SPLITTERWINDOW1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TOOLBAR_NEW;
        static const long ID_TOOLBAR_DELETE;
        static const long ID_TOOLBAR_START;
        static const long ID_TOOLBAR_RESTART;
        static const long ID_TOOLBAR_STOP;
        static const long ID_TOOLBAR_PREFERENCES;
        static const long ID_TOOLBAR1;
        static const long ID_TIMER;
        //*)

        //(*Declarations(QEMU_ManagerFrame)
        wxButton* m_pBtnNewHdd;
        wxCheckBox* m_pChkEnableCdrom;
        wxCheckBox* m_pChkShowDisplay;
        wxChoice* m_pCmbSystem;
        wxFilePickerCtrl* m_pFilePickerCdrom;
        wxFilePickerCtrl* m_pFilePickerHdd;
        wxListBox* m_pLstLog;
        wxListBox* m_pLstVms;
        wxNotebook* Notebook1;
        wxPanel* Panel2;
        wxPanel* m_pPnlSettings;
        wxScrolledWindow* ScrolledWindow1;
        wxSplitterWindow* m_pSplitter;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        wxStaticText* m_pLblStatus;
        wxStatusBar* m_pStatusbar;
        wxTextCtrl* m_pTxtMemory;
        wxTextCtrl* m_pTxtName;
        wxTextCtrl* m_pTxtParams;
        wxTimer m_pTimer;
        wxToolBar* m_pToolbar;
        wxToolBarToolBase* m_pToolbtnDelete;
        wxToolBarToolBase* m_pToolbtnKill;
        wxToolBarToolBase* m_pToolbtnNew;
        wxToolBarToolBase* m_pToolbtnPreferences;
        wxToolBarToolBase* m_pToolbtnRestart;
        wxToolBarToolBase* m_pToolbtnStart;
        //*)

        /** Handle Close event
        *   @param  event Close event
        */
        void OnClose(wxCloseEvent& event);

        /** Deletes a virtual machine
        *   @param  pVm Pointer to the VM to delete
        */
        void DeleteVm(QemuVm* pVm);

        void RefreshVmList();

        void LoadConfig();

        void SaveConfig();

        /** Saves the VM details to configuration
        *   @param pVm Pointer to the VM
        */
        void SaveVm(QemuVm* pVm);

        void PopulateSystems();

        /** Get a pointer to the VM currently selected in the list
        */
        QemuVm* GetSelectedVm();

        /** Save current screen position and size
        */
        void SaveScreen();

        /** Load screen position and size
        */
        void LoadScreen();

        /** Get the command line that will be executed
        *   @param pVm Pointer to virtual machine (Default - Currently selected VM)
        *   @retval wxString Command line used to launch VM
        */
        wxString GetCommand(QemuVm* pVm = NULL);

        /** Enable or disable ability to edit VM parameters
        *   @param  bEnable True to allow editing (Default: True)
        */
        void EnableEdit(bool bEnable = true);

        /** Get the next available API port, starting at 2001
        *   @retval unsigned int Port number
        */
        unsigned int GetNextApiPort();

        /** Get status text for a VM
        *   @param  pVm Pointer to VM
        *   @retval wxString Status text
        */
        wxString GetStatus(QemuVm* pVm);

        std::vector<QemuVm*> m_vVm; // List of VMs
        int m_nCurrentVm; // Index of currently selected VM within m_vVm or -1 for none selected
        wxConfig* m_pConfig = NULL; // Pointer to the configuration
        wxSocketClient m_socketApi; // Client socket for QAPI

        DECLARE_EVENT_TABLE()
};
