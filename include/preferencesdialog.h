#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

//(*Headers(PreferencesDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)
#include <wx/config.h>

class PreferencesDialog: public wxDialog
{
	public:

		PreferencesDialog(wxWindow* parent, wxConfig* pConfig);
		virtual ~PreferencesDialog();

		//(*Declarations(PreferencesDialog)
		wxButton* Button1;
		wxButton* m_pBtnQemuPath;
		wxStaticText* StaticText1;
		wxTextCtrl* m_pTxtQemuPath;
		//*)

	protected:

		//(*Identifiers(PreferencesDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(PreferencesDialog)
		void OnButtonClose(wxCommandEvent& event);
		void OnQemuPathChange(wxCommandEvent& event);
		void OnQemuPathButton(wxCommandEvent& event);
		//*)

		wxConfig* m_pConfig;

		DECLARE_EVENT_TABLE()
};

#endif
