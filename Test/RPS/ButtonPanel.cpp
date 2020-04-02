#include "ButtonPanel.h"

void ButtonPanel::init()
{
    wxSizer *main_panel_sizer = new wxBoxSizer(wxVERTICAL);

    //Round panel
    wxPanel *round_panel = new wxPanel(this, wxID_ANY);
    wxSizer *round_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *round_text = new wxStaticText(round_panel, wxID_ANY, "ROUND:");
    //code to retrieve round
    round_sizer->Add(round_text, 0, 0, 0);
    round_sizer->AddSpacer(5);

    round_panel ->SetSizer(round_sizer);

    //Human text panel
    wxPanel *human_panel = new wxPanel(this, wxID_ANY);
    wxSizer *human_sizer = new wxGridSizer(2, 0, 5);
    wxStaticText *human_text = new wxStaticText(human_panel, wxID_ANY,
                                                     "HUMAN");
    human_sizer->Add(human_text, 0, 0, 0);

    human_panel ->SetSizer(human_sizer);
    // Button panel

    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);


    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                                 "Choose:");
    wxButton *rock_button     = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(ROCK));
    wxButton *paper_button    = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(PAPER));
    wxButton *scissors_button = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(SCISSORS));

    rock_button->Bind    (wxEVT_BUTTON, &ButtonPanel::on_rock, this);
    paper_button->Bind   (wxEVT_BUTTON, &ButtonPanel::on_paper, this);
    scissors_button->Bind(wxEVT_BUTTON, &ButtonPanel::on_scissors, this);

    button_sizer->Add(human_text, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(choose_text, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(rock_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(paper_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(scissors_button, 0, 0, 0);
    button_panel->SetSizer(button_sizer);

    // Choice panel

    wxPanel *choice_panel = new wxPanel(this, wxID_ANY);
    wxSizer *choice_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *chosen_object_label =
            new wxStaticText(choice_panel, wxID_ANY, "Human chose:");
    chosen_button_name = new wxStaticText(choice_panel, wxID_ANY, "");
    chosen_button_name->SetFont(chosen_button_name->GetFont().Larger());

    choice_sizer->Add(chosen_object_label, 0, wxALIGN_RIGHT, 0);
    choice_sizer->Add(chosen_button_name, 0, 0, 0);
    choice_panel->SetSizer(choice_sizer);

    //Bot Panel
    wxPanel *bot_panel = new wxPanel(this, wxID_ANY);
    wxSizer *bot_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *bot_text = new wxStaticText(bot_panel, wxID_ANY,
                                                             "BOT");
    wxStaticText *bot_predict_text = new wxStaticText(bot_panel, wxID_ANY,
                                                         "Bot predicts:");
    wxStaticText *bot_choice_text = new wxStaticText(bot_panel, wxID_ANY, "Bot chose:");

    bot_sizer->Add(bot_text, 0, 0, 0);
    bot_sizer->AddSpacer(5);
    bot_sizer->Add(bot_predict_text, 0, 0, 0);
    bot_sizer->AddSpacer(5);
    bot_sizer->Add(bot_choice_text, 0, 0, 0);
    bot_sizer->AddSpacer(5);
    bot_panel ->SetSizer(bot_sizer);

    //Winner panel
    wxPanel *winner_panel = new wxPanel(this, wxID_ANY);
    wxSizer *winner_sizer = new wxGridSizer(2, 0, 5);

       wxStaticText *winner_text = new wxStaticText(winner_panel, wxID_ANY, "WINNER:");
       //code to retrieve round
       winner_sizer->Add(winner_text, 0, 0, 0);
       winner_sizer->AddSpacer(5);

       winner_panel ->SetSizer(winner_sizer);

       //Bot Panel
       wxPanel *stat_panel = new wxPanel(this, wxID_ANY);
       wxSizer *stat_sizer = new wxGridSizer(2, 0, 5);

       wxStaticText *stat_text = new wxStaticText(stat_panel, wxID_ANY,
                                                                    "STATISTICS");
       wxStaticText *stat_human_text = new wxStaticText(stat_panel, wxID_ANY,
                                                                "Human wins:");
       wxStaticText *stat_bot_text = new wxStaticText(stat_panel, wxID_ANY, "Bot wins:");

       wxStaticText *stat_ties_text = new wxStaticText(stat_panel, wxID_ANY, "Ties:");

       stat_sizer->Add(stat_text, 0, 0, 0);
       stat_sizer->AddSpacer(5);
       stat_sizer->Add(stat_human_text, 0, 0, 0);
       stat_sizer->AddSpacer(5);
       stat_sizer->Add(stat_bot_text, 0, 0, 0);
       stat_sizer->AddSpacer(5);
       stat_sizer->Add(stat_ties_text, 0, 0, 0);
       stat_sizer->AddSpacer(5);
       stat_panel ->SetSizer(stat_sizer);
    // Main panel
    main_panel_sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(human_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(5);
    main_panel_sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(choice_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(bot_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(winner_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(stat_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);

    SetSizer(main_panel_sizer);
}

void ButtonPanel::on_rock(wxCommandEvent& event)
{
    update_button_choice_text(ROCK);
}

void ButtonPanel::on_paper(wxCommandEvent& event)
{
    update_button_choice_text(PAPER);
}

void ButtonPanel::on_scissors(wxCommandEvent& event)
{
    update_button_choice_text(SCISSORS);
}

void ButtonPanel::update_button_choice_text(const Choice choice)
{
    chosen_button_name->SetLabelText(choice_to_wxString(choice));
}
