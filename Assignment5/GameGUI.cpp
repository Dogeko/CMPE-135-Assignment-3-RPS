#include <wx/wx.h>

class Simple : public wxFrame
{
public:
    Simple(const wxString &title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250 * 3, 150 * 3))
    {
        Centre();
    }
    // wxButton *button
};

class RPSApp : public wxApp
{
public:
    bool OnInit()
    {
        Simple *simple = new Simple(wxT("Rock Paper Scissors"));
        // Hello = new wxButton(this, _T "BUTTON");
        simple->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(RPSApp);