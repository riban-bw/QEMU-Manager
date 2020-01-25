/***************************************************************
 * Name:      qemuvm.cpp
 * Purpose:   Code for QEMU VM
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2020-01-23
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL-V3
 **************************************************************/
#include "qemuvm.h"
#include <wx/filename.h>
#include <wx/process.h>

#ifdef __WXMSW__
#include "psapi.h"
#endif // __WXMSW__

wxString QemuVm::QEMU_PATH = "";

QemuVm::QemuVm()
{
}

QemuVm::~QemuVm()
{
}

wxString QemuVm::GetName()
{
    return m_sName;
}

void QemuVm::SetName(wxString sName)
{
    m_sName = sName;
}

wxString QemuVm::GetSystem()
{

    return m_sSystem;
}

void QemuVm::SetSystem(wxString sSystem)
{
    m_sSystem = sSystem;
}

wxString QemuVm::GetImage()
{
    return m_sImage;
}

void QemuVm::SetImage(wxString sImage)
{
    m_sImage = sImage;
}

unsigned int QemuVm::GetMemory()
{
    return m_nMemory;
}

void QemuVm::SetMemory(unsigned int nMemory)
{
    m_nMemory = nMemory;
}

wxString QemuVm::GetParams()
{
    return m_sParams;
}

void QemuVm::SetParams(wxString sParams)
{
    m_sParams = sParams;
}

bool QemuVm::GetShowDisplay()
{
    return m_bShowDisplay;
}

void QemuVm::SetShowDisplay(bool bShow)
{
    m_bShowDisplay = bShow;
}

long QemuVm::GetPid()
{
    return m_nPid;
}

void QemuVm::Start()
{
    if(m_nPid)
        return;
    wxString sCommand = wxString::Format("%s %s", GetCommand(true).c_str(), GetCommandParameters().c_str());
    m_nPid = wxExecute(sCommand.c_str(), wxEXEC_HIDE_CONSOLE);
}

wxString QemuVm::GetCommand(bool bWithPath)
{
    wxString sFilename = "qemu-system-" + m_sSystem;
    #ifdef __WXMSW__
    sFilename += ".exe";
    #endif // __WXMSW__
    if(bWithPath)
        sFilename = wxFileName(QEMU_PATH + "/" + sFilename).GetFullPath();
    return(sFilename);
}

wxString QemuVm::GetCommandParameters()
{
    wxString sParams = wxString::Format("%s -m %d %s",
                                         m_sImage.c_str(),
                                         m_nMemory,
                                         m_sParams.c_str());
    if(!m_bShowDisplay)
        sParams += " -nographic";
    return sParams;
}

bool QemuVm::IsRunning(unsigned int nPid)
{
    if(nPid)
        m_nPid = nPid;
    bool bRunning = (m_nPid != 0);
    if(bRunning)
    {
        //Get process name from PID
        wxString sProcess;
        #ifdef __WXMSW__
        HANDLE handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, m_nPid);
        if(handle)
        {
            TCHAR pName[MAX_PATH];
            if(GetModuleFileNameEx(handle, 0, pName, MAX_PATH))
                sProcess = wxString(pName);
            CloseHandle(handle);
        }
        #elif
        char* pName = (char*)calloc(PATH_MAX, sizeof(char));
        if(pName)
        {
            sprintf(pName, "/proc/%d/cmdline", m_nPid);
            FILE* filePid = fopen(pName, "r");
            if(filePid)
            {
                size_t nSize;
                nSize = fread(pName, sizeof(char), PATH_MAX, filePid);
                if(nSize>0){
                    if('\n' == pName[nSize - 1])
                        pName[size - 1] = '\0';
                }
                fclose(filePid);
            }
        }
        sProcess = wxString(pName);
        #endif // __WXMSW__
        bRunning = (GetCommand(true).IsSameAs(sProcess, false));
    }
    if(!bRunning)
        m_nPid = 0;
    return bRunning;
}
