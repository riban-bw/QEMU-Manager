/***************************************************************
 * Name:      qemuvm.h
 * Purpose:   Defines QemuVm Class
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
        QemuVm(unsigned int nApiPort = 0);
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

        /** @brief  Get CD ROM image full path and filename
        *   @retval wxString CD ROM image path and filename
        */
        wxString GetCdrom();

        /** @brief  Set CD ROM image full path and filename
        *   @param  sImage CD ROM  image path and filename
        */
        void SetCdrom(wxString sImage);

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
        *   @param  bWithPath True to return full path and filename (Default: false)
        *   @param  bWithParams True to return command line parameters appended to command (Default: false)
        *   @retval wxString QEMU executable
        */
        wxString GetCommand(bool bWithPath = false, bool bWithParams = false);

        /** @brief  Get the command line parameters for QEMU
        *   @retval wxString Command line parameters
        */
        wxString GetCommandParameters();

        /** @brief  Is the VM running
        *   @param  nPid Set VM's PID (optional)
        *   @retval bool True if VM running
        */
        bool IsRunning(unsigned int nPid = 0);

        /** @brief  Enables / disables CD ROM
        *   @param  bEnable True to enable CD ROM (Default: true)
        */
        void EnableCdrom(bool bEnable = true);

        /** @brief  Check if CD ROM is enabled
        *   @retval bool True if CD ROM enabled
        */
        bool IsCdromEnabled();

        /** @brief  Get API port number
        *   @retval unsigned int API port number
        */
        unsigned int GetApiPort();

        static wxString QEMU_PATH;

    protected:

    private:
        wxString m_sName = "New VM";
        wxString m_sSystem = "i386";
        wxString m_sImage;
        wxString m_sCdrom;
        unsigned int m_nMemory = 512;
        wxString m_sParams;
        bool m_bShowDisplay = true;
        unsigned int m_nPid = 0;
        unsigned int m_nApiPort;
        bool m_bCdromEnabled = true;
};

