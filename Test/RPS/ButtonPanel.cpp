#include "ButtonPanel.h"

void ButtonPanel::init()
{
    wxSizer *main_panel_sizer = new wxBoxSizer(wxVERTICAL);

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
            new wxStaticText(choice_panel, wxID_ANY, "Chosen object:");
    chosen_button_name = new wxStaticText(choice_panel, wxID_ANY, "");
    chosen_button_name->SetFont(chosen_button_name->GetFont().Larger());

    choice_sizer->Add(chosen_object_label, 0, wxALIGN_RIGHT, 0);
    choice_sizer->Add(chosen_button_name, 0, 0, 0);
    choice_panel->SetSizer(choice_sizer);

    // Main panel

    main_panel_sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    main_panel_sizer->AddSpacer(20);
    main_panel_sizer->Add(choice_panel, 0, wxALIGN_CENTER, 0);
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
