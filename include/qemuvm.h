#pragma once
#include <wx/wx.h>

class QemuVm
{
    public:
        QemuVm();
        virtual ~QemuVm();

        wxString GetName();
        void SetName(wxString sName);
        wxString GetSystem();
        void SetSystem(wxString sName);
        wxString GetImage();
        void SetImage(wxString sName);
        wxString GetParams();
        void SetParams(wxString sParams);
        unsigned int GetMemory();
        void SetMemory(unsigned int nMemory);
        bool GetShowDisplay();
        void SetShowDisplay(bool bShow);

    protected:

    private:
        wxString m_sName = "New VM";
        wxString m_sSystem = "i386";
        wxString m_sImage;
        unsigned int m_nMemory = 512;
        wxString m_sParams;
        bool m_bShowDisplay = true;
};

