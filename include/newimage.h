#ifndef NEWIMAGE_H
#define NEWIMAGE_H

//(*Headers(NewImage)
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/filepicker.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class NewImage: public wxDialog
{
	public:

		NewImage(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~NewImage();

		//(*Declarations(NewImage)
		wxChoice* m_pCmbDiskType;
		wxFilePickerCtrl* m_pFilePickerBaseImage;
		wxFilePickerCtrl* m_pFilePickerImage;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxTextCtrl* m_pTxtSize;
		//*)

	protected:

		//(*Identifiers(NewImage)
		static const long ID_STATICTEXT1;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT2;
		static const long ID_FILEPICKERCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_FILEPICKERCTRL2;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL1;
		//*)

	private:

		//(*Handlers(NewImage)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
