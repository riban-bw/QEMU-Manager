#include "qemuvm.h"

QemuVm::QemuVm()
{
    //ctor
}

QemuVm::~QemuVm()
{
    //dtor
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
