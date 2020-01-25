#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

//(*Headers(PreferencesDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/filepicker.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)
#include <wx/config.h>

class PreferencesDialog: public wxDialog
{
	public:

		PreferencesDialog(wxWindow* parent, wxConfig* pConfig);
		virtual ~PreferencesDialog();

		//(*Declarations(PreferencesDialog)
		wxButton* Button1;
		wxDirPickerCtrl* m_pDirPicker;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(PreferencesDialog)
		static const long ID_STATICTEXT1;
		static const long ID_DIRPICKERCTRL1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(PreferencesDialog)
		void OnButtonClose(wxCommandEvent& event);
		void OnQemuPathChange(wxFileDirPickerEvent& event);
		//*)

		wxConfig* m_pConfig;

		DECLARE_EVENT_TABLE()
};

#endif
