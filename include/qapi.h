#include <wx/socket.h>
#include "wx/jsonreader.h"
#include "wx/jsonwriter.h"


class QAPI : public wxSocketClient
{
    public:
        QAPI(unsigned int nPort);
        virtual ~QAPI();

        /** @brief  Get status
        *   @retval wxString Status
        */
        wxString GetStatus();

        /** @brief  Get the last received message
        *   @retval wxString Last received message
        */
        wxString GetLastRx();

        /** @brief  Send API message
        *   @param  sMessage API message to send
        *   @retval wxString API reply
        */
        wxString SendAPIMessage(wxJSONValue& msg);

    protected:

    private:
        char m_pRxBuffer[1024];
        wxString m_sLastRx;

};
