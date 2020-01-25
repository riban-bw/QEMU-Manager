/***************************************************************
 * Name:      QEMU_ManagerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2020-01-23
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL V3
 **************************************************************/

#include "qemu_managerapp.h"

//(*AppHeaders
#include "qemu_managermain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(QEMU_ManagerApp);

bool QEMU_ManagerApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	QEMU_ManagerFrame* Frame = new QEMU_ManagerFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
