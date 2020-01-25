/***************************************************************
 * Name:      qemuvm.h
 * Purpose:   Defines QEMU VM
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2020-01-23
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL-V3
 **************************************************************/
#pragma once
#include <wx/wx.h>

class QemuVm
{
    public:
        QemuVm();
        virtual ~QemuVm();

        /** @brief  Get name of the VM
        *   @retval wxString VM name
        */
        wxString GetName();

        /** @brief  Set name of the VM
        *   @param sName VM name
        */
        void SetName(wxString sName);

        /** @brief  Get VM system type
        *   @retval wxString System
        */
        wxString GetSystem();

        /** @brief  Set VM system type
        *   @param  sSystem System type
        */
        void SetSystem(wxString sSystem);

        /** @brief  Get disk image full path and filename
        *   @retval wxString Disk image path and filename
        */
        wxString GetImage();

        /** @brief  Set disk image full path and filename
        *   @param  sImage Disk image path and filename
        */
        void SetImage(wxString sImage);

        /** @brief  Get other arbitrary QEMU command line parameters
        *   @retval wxString Other parameters
        */
        wxString GetParams();

        /** @brief  Set other arbitary QEMU command line parameters
        *   @param  sParams Other parameters
        */
        void SetParams(wxString sParams);

        /** @brief  Get VM memory allocation
        *   @retval unsigned int Memory in MB
        */
        unsigned int GetMemory();

        /** @brief  Set VM memory allocation
        *   @param  nMemory Memory in MB
        */
        void SetMemory(unsigned int nMemory);

        /** @brief  Get whether QEMU will display user interface window
        *   @retval bool True if QEMU will display interface
        */
        bool GetShowDisplay();

        /** @brief  Set whether QEMU will display user interface window
        *   @param  bShow True to show interface
        */
        void SetShowDisplay(bool bShow);

        /** @brief  Get PID of QEMU process
        *   @retval long PID (0 if not running)
        */
        long GetPid();

        /** @brief  Starts the VM
        */
        void Start();

        /** @brief  Get the name of the qemu executable
        *   @param  bWithPath True to return full path and filename
        *   @retval wxString QEMU executable
        */
        wxString GetCommand(bool bWithPath = false);

        /** @brief  Get the command line parameters for QEMU
        *   @retval wxString Command line parameters
        */
        wxString GetCommandParameters();

        /** @brief  Is the VM running
        *   @param  nPid Set VM's PID (optional)
        *   @retval bool True if VM running
        */
        bool IsRunning(unsigned int nPid = 0);

        static wxString QEMU_PATH;

    protected:

    private:
        wxString m_sName = "New VM";
        wxString m_sSystem = "i386";
        wxString m_sImage;
        unsigned int m_nMemory = 512;
        wxString m_sParams;
        bool m_bShowDisplay = true;
        unsigned int m_nPid = 0;
};

