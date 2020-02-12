#include "qapi.h"

QAPI::QAPI(unsigned int nPort) :
    wxSocketClient()
{
    SetTimeout(1);
    wxIPV4address ipAddr;
    ipAddr.Hostname("127.0.0.1");
    ipAddr.Service(nPort);
    if(Connect(ipAddr))
    {
        Read(m_pRxBuffer, sizeof(m_pRxBuffer));
        m_pRxBuffer[sizeof(m_pRxBuffer) - 1] = 0;
        m_sLastRx = wxString(m_pRxBuffer);
    }
}

QAPI::~QAPI()
{
    Close();
}

wxString QAPI::GetLastRx()
{
    return m_sLastRx;
}

wxString QAPI::SendAPIMessage(wxJSONValue& msg)
{
    if(!IsConnected())
        return "";
    wxString sMsg;
    wxJSONWriter jsonWriter;
    jsonWriter.Write(msg, sMsg);
    Write(sMsg.c_str(), sMsg.Len());
    if(Error())
        return "";
    Read(m_pRxBuffer, sizeof(m_pRxBuffer));
    m_pRxBuffer[sizeof(m_pRxBuffer) - 1] = 0; //Ensure we have a null terminated buffer even if it corrupts message
    return wxString(m_pRxBuffer);
}

wxString QAPI::GetStatus()
{
    if(!IsConnected())
        return "unknown";
    wxJSONValue msg;
    msg["execute"] = wxString("query-status");
    wxString sResponse = SendAPIMessage(msg);
    wxJSONReader jsonReader;
    wxJSONValue root;
    if(jsonReader.Parse(sResponse.c_str(), &root))
        return ""; //Error parsing json
    return root["return"]["status"].AsString();
}
