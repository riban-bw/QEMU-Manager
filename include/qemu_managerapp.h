/***************************************************************
 * Name:      QEMU_ManagerApp.h
 * Purpose:   Defines Application Class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2020-01-23
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL V3
 **************************************************************/

#ifndef QEMU_MANAGERAPP_H
#define QEMU_MANAGERAPP_H

#include <wx/app.h>

class QEMU_ManagerApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // QEMU_MANAGERAPP_H
