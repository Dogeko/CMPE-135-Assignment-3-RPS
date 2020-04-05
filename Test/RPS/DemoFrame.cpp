#include "DemoFrame.h"

// The event table.
wxBEGIN_EVENT_TABLE(DemoFrame, wxFrame)
    EVT_MENU(RPS_About, DemoFrame::on_about)
    EVT_MENU(RPS_Quit,  DemoFrame::on_quit)
	EVT_MENU(RPS_NewGame,  DemoFrame::on_new_game)
wxEND_EVENT_TABLE()

const int SIDE_MARGINS = 40;

DemoFrame::DemoFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title),
      button_panel(new ButtonPanel(this))
{
    init();

    wxSize size = GetSize();
    size.SetWidth (size.GetWidth() + SIDE_MARGINS);
    SetSize(size);
}

DemoFrame::~DemoFrame()
{
    delete button_panel;
}

void DemoFrame::init()
{
    init_menu_bar();
    init_sizer();

    wxSize size = GetBestSize();
    SetMinClientSize(size);
}

void DemoFrame::init_sizer()
{
    wxSizer *frame_sizer = new wxBoxSizer(wxVERTICAL);

    frame_sizer->AddSpacer(20);
    frame_sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);

    SetSizerAndFit(frame_sizer);
}

void DemoFrame::init_menu_bar()
{
    wxMenu *fileMenu = new wxMenu;
    wxMenu *startMenu = new wxMenu;

//    startMenu->Append(RPS_NewGame, "&1 Round",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&2 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&3 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&4 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&5 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&6 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&7 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&8 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&9 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&10 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&11 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&12 Round",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&13 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&14 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&15 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&16 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&17 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&18 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&19 Rounds",   "Start a new game");
//    startMenu->Append(RPS_NewGame, "&20 Rounds",   "Start a new game");



    fileMenu->Append(RPS_About, "&About\tF1",   "Show about dialog");
    fileMenu->Append(RPS_Quit,  "E&xit\tAlt-X", "Quit program");
    startMenu->Append(RPS_NewGame, "&New Game");
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(startMenu,"Start");
    //menuBar->Append(helpMenu, "&Help");
    SetMenuBar(menuBar);
}

void DemoFrame::on_about(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format(
                    "This is a Rock Paper Scissors Simulator\n"
                    "built with %s\n"
                    "and running under %s.",
                    wxVERSION_STRING,
                    wxGetOsDescription()
                ),
                "About the button demo",
                wxOK | wxICON_INFORMATION,
                this);
}

void DemoFrame::on_quit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);  // true is to force the frame to close
}
void DemoFrame::on_new_game(wxCommandEvent& WXUNUSED(event))
{
	wxString roundsString;
	wxTextEntryDialog roundsEntered;


	roundsEntered.Create(this,"Enter number of rounds");
	roundsEntered.ShowModal();
	roundsString = roundsEntered.GetValue();
	int rounds = wxAtoi(roundsString);
    //Close(true);  // true is to force the frame to close
	wxMessageBox(wxString::Format("A new game has started"));

	button_panel->new_game();
	button_panel->setRPSRounds(rounds);
	button_panel->update_new_game_screen();
	//consider functionality if user clicks on "new game" ask how many rounds
}
