/***************************************************************
 * Name:      QEMU_ManagerMain.h
 * Purpose:   Defines Application Frame
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2020-01-23
 * Copyright: Brian Walton (riban.co.uk)
 * License:
 **************************************************************/

#ifndef QEMU_MANAGERMAIN_H
#define QEMU_MANAGERMAIN_H

//(*Headers(QEMU_ManagerFrame)
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/filepicker.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/menu.h>
#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/splitter.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/toolbar.h>
//*)
#include <vector>
#include "qemuvm.h"
#include <wx/config.h>

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
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT6;
        static const long ID_CHECKBOX1;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL4;
        static const long ID_SCROLLEDWINDOW2;
        static const long ID_SPLITTERWINDOW1;
        static const long ID_MENU_SAVE;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TOOLBAR_NEW;
        static const long ID_TOOLBAR_DELETE;
        static const long ID_TOOLBAR_START;
        static const long ID_TOOLBAR_RESTART;
        static const long ID_TOOLBAR_STOP;
        static const long ID_TOOLBAR_SAVE;
        static const long ID_TOOLBAR_PREFERENCES;
        static const long ID_TOOLBAR1;
        //*)

        //(*Declarations(QEMU_ManagerFrame)
        wxCheckBox* m_pChkShowDisplay;
        wxChoice* m_pCmbSystem;
        wxFilePickerCtrl* m_pTxtImage;
        wxListBox* m_pLstVms;
        wxMenuItem* MenuItem3;
        wxScrolledWindow* ScrolledWindow1;
        wxScrolledWindow* ScrolledWindow2;
        wxSplitterWindow* SplitterWindow1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStatusBar* StatusBar1;
        wxTextCtrl* m_pTxtMemory;
        wxTextCtrl* m_pTxtName;
        wxTextCtrl* m_pTxtParams;
        wxToolBar* m_pToolbar;
        wxToolBarToolBase* m_pToolbtnDelete;
        wxToolBarToolBase* m_pToolbtnNew;
        wxToolBarToolBase* m_pToolbtnPreferences;
        wxToolBarToolBase* m_pToolbtnRestart;
        wxToolBarToolBase* m_pToolbtnSave;
        wxToolBarToolBase* m_pToolbtnStart;
        wxToolBarToolBase* m_pToolbtnStop;
        //*)

        /** Override the OnClose event
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

        /** Sets the dirty status
        *   @param bDirty True to set dirty, false to set clean (Default: true)
        */
        void SetDirty(bool bDirty = true);

        /** Save current screen position and size
        */
        void SaveScreen();

        /** Load screen position and size
        */
        void LoadScreen();

        std::vector<QemuVm*> m_vVm; // List of VMs
        int m_nCurrentVm; // Index of currently selected VM within m_vVm or -1 for none selected
        wxString m_sQemuPath;
        wxConfig* m_pConfig = NULL; // Pointer to the configuration
        bool m_bDirty; // True if unsaved changes
        bool m_bIhibitDirty = false; // True to indicate that dirty flag should not be altered

        DECLARE_EVENT_TABLE()
};

#endif // QEMU_MANAGERMAIN_H
