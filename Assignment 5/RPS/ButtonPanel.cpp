#include "ButtonPanel.h"

void ButtonPanel::init()
{
	//sizer for the main panel
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);


    //round panel
    wxPanel *round_panel = new wxPanel(this, wxID_ANY);
    wxSizer *round_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *round_text = new wxStaticText(round_panel, wxID_ANY, "Round:");
    round_text->SetFont(round_text->GetFont().Larger());

    round_count_text = new wxStaticText(round_panel, wxID_ANY, "20");
    round_count_text->SetFont(round_count_text->GetFont().Larger());

    round_sizer->Add(round_text, 0, wxALIGN_RIGHT, 0);
    round_sizer->AddSpacer(10);
    round_sizer->Add(round_count_text, 0, 0, 0);
    round_sizer->AddSpacer(20);

    round_panel->SetSizer(round_sizer);


    //human panel
    wxPanel *human_panel = new wxPanel(this, wxID_ANY);
    wxSizer *human_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *human_text = new wxStaticText(human_panel, wxID_ANY,
                                                "HUMAN");
    human_text->SetFont(human_text->GetFont().Larger());

    human_sizer->Add(human_text, 0, 0, 0);
    human_sizer->AddSpacer(5);

    human_panel->SetSizer(human_sizer);


    //button panel
    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                                 "Choose:");
    wxButton *rock_button = new wxButton(button_panel, wxID_ANY,
                                         choice_to_wxString(ROCK));
    wxButton *paper_button = new wxButton(button_panel, wxID_ANY,
                                          choice_to_wxString(PAPER));
    wxButton *scissors_button = new wxButton(button_panel, wxID_ANY,
                                             choice_to_wxString(SCISSORS));

    rock_button->Bind(wxEVT_BUTTON, &ButtonPanel::on_rock, this);
    paper_button->Bind(wxEVT_BUTTON, &ButtonPanel::on_paper, this);
    scissors_button->Bind(wxEVT_BUTTON, &ButtonPanel::on_scissors, this);

    button_sizer->Add(choose_text, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(rock_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(paper_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(scissors_button, 0, 0, 0);

    button_panel->SetSizer(button_sizer);


    //chosen panel
    wxPanel *chosen_panel = new wxPanel(this, wxID_ANY);
    wxSizer *chosen_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *chosen_text = new wxStaticText(chosen_panel, wxID_ANY,
                                                 "Human chooses:");
    button_chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "");
    button_chosen_text->SetFont(button_chosen_text->GetFont().Larger());

    chosen_sizer->Add(chosen_text, 0, wxALIGN_RIGHT, 0);
    chosen_sizer->Add(button_chosen_text, 0, 0, 0);

    chosen_panel->SetSizer(chosen_sizer);


    //bot panel
    wxPanel *bot_panel = new wxPanel(this, wxID_ANY);
    wxSizer *bot_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *bot_text = new wxStaticText(bot_panel, wxID_ANY, "Bot chooses:");
    bot_chosen_text = new wxStaticText(bot_panel, wxID_ANY, "");
    bot_chosen_text->SetFont(bot_chosen_text->GetFont().Larger());

    bot_sizer->Add(bot_text, 0, wxALIGN_RIGHT, 0);
    bot_sizer->Add(bot_chosen_text, 0, 0, 0);

    bot_panel->SetSizer(bot_sizer);


    //human choice panel
    wxPanel *human_choice_panel = new wxPanel(this, wxID_ANY);
    wxSizer *human_choice_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *human_choice_text = new wxStaticText(human_choice_panel, wxID_ANY,
                                                       "Predicted human choice: ");
    human_prediction_text = new wxStaticText(human_choice_panel, wxID_ANY, "");
    human_prediction_text->SetFont(human_prediction_text->GetFont().Larger());

    human_choice_sizer->Add(human_choice_text, 0, wxALIGN_RIGHT, 0);
    human_choice_sizer->Add(human_prediction_text, 0, 0, 0);

    human_choice_panel->SetSizer(human_choice_sizer);


    //winner panel
    wxPanel *winner_panel = new wxPanel(this, wxID_ANY);
    wxSizer *winner_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *winner_text = new wxStaticText(winner_panel, wxID_ANY, "WINNER: ");
    winner_text->SetFont(winner_text->GetFont().Larger());
    winner_result_text = new wxStaticText(winner_panel, wxID_ANY, "");
    winner_result_text->SetFont(winner_result_text->GetFont().Larger());

    winner_sizer->Add(winner_text, 0, wxALIGN_RIGHT, 0);
    winner_sizer->Add(winner_result_text, 0, 0, 0);

    winner_panel->SetSizer(winner_sizer);


    //statistics panel
    wxPanel *statistic_panel = new wxPanel(this, wxID_ANY);
    wxSizer *statistic_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *statistic_text = new wxStaticText(statistic_panel, wxID_ANY,
                                                    "STATISTICS");
    statistic_text->SetFont(statistic_text->GetFont().Larger());
    wxStaticText *human_wins_text = new wxStaticText(statistic_panel, wxID_ANY,
                                                     "Human wins: ");
    human_win_text = new wxStaticText(statistic_panel, wxID_ANY, "");
    wxStaticText *bot_wins_text = new wxStaticText(statistic_panel, wxID_ANY, "Bot wins: ");
    bot_win_text = new wxStaticText(statistic_panel, wxID_ANY, "");
    wxStaticText *draw_text = new wxStaticText(statistic_panel, wxID_ANY, "Draws: ");
    draw_count_text = new wxStaticText(statistic_panel, wxID_ANY, "");

    statistic_sizer->Add(statistic_text, 0, wxALIGN_RIGHT, 0);
    statistic_sizer->AddSpacer(20);
    statistic_sizer->Add(human_wins_text, 0, wxALIGN_RIGHT, 0);
    statistic_sizer->Add(human_win_text, 0, 0, 0);
    statistic_sizer->Add(bot_wins_text, 0, wxALIGN_RIGHT, 0);
    statistic_sizer->Add(bot_win_text, 0, 0, 0);
    statistic_sizer->Add(draw_text, 0, wxALIGN_RIGHT, 0);
    statistic_sizer->Add(draw_count_text, 0, 0, 0);

    statistic_panel->SetSizer(statistic_sizer);


    //set up sizer for the main panel
    sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(human_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(chosen_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(human_choice_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(bot_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(winner_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(statistic_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);

    SetSizer(sizer);
}

void ButtonPanel::on_rock(wxCommandEvent &event)
{
    if (RPS->getRound() >= 1)
    {
    	update_button_choice_text(ROCK);

    	update_bot_choice_text(RPS->human.getChoice());

        update_winner_result_text();

        update_statistics();

        RPS->setRound(RPS->getRound() - 1);

    	update_round();
    }
    else
    {
    	game_over_screen();
    }
}

void ButtonPanel::on_paper(wxCommandEvent &event)
{
    if (RPS->getRound() >= 1)
    {
       update_button_choice_text(PAPER);

       update_bot_choice_text(RPS->human.getChoice());

       update_winner_result_text();

       update_statistics();

       RPS->setRound(RPS->getRound() - 1);

       update_round();

    }
    else
    {
    	game_over_screen();
    }
}

void ButtonPanel::on_scissors(wxCommandEvent &event)
{
    if (RPS->getRound() >= 1)
    {
        update_button_choice_text(SCISSORS);

        update_bot_choice_text(RPS->human.getChoice());

        update_winner_result_text();

        update_statistics();

        RPS->setRound(RPS->getRound() - 1);

        update_round();
    }
    else
    {
    	game_over_screen();
    }
}

void ButtonPanel::update_button_choice_text(const Choice choice)
{
    button_chosen_text->SetLabelText(choice_to_wxString(choice));

    switch(choice){

    	case PAPER: RPS->human.setChoice(0); break;

    	case SCISSORS: RPS->human.setChoice(1); break;

    	case ROCK: RPS->human.setChoice(2); break;
    }

}

void ButtonPanel::update_bot_choice_text(int humanChoice)
{
	int botChoice;

	wxString botString;

	RPS->bot->pick(humanChoice);

	update_bot_prediction_choice_text(RPS->human.getChoice());
	botChoice = RPS->bot->getChoice();
	cout<< "botChoice : "<<botChoice<<endl;
	if(botChoice == 0){
		botString = "Paper"; //paper
	}
	else if(botChoice == 1){ //rock
		botString = "Scissors";
	}
	else{
		botString = "Rock"; // scissors
	}


    bot_chosen_text->SetLabelText(botString);
}

void ButtonPanel::update_bot_prediction_choice_text(int humanChoice)
{
	int prediction;
	wxString predictionString;
	RPS->bot->pick(humanChoice);
	prediction = RPS->bot->getChoice();
	if(prediction == 0){// 0 paper bot choose and prediction is rock
		cout << "the prediction is: Rock, Choice is : Paper"<< endl;
		predictionString = "Rock";
	}
	else if(prediction == 1){//1 scissors choose and prediction is paper
		cout << "the prediction is: Paper, Choice is : Scissors "<< endl;
		predictionString = "Paper";
	}
	else{//2 rock choose and prediction is scissors
		cout << "the prediction is: Scissors, Choice is : Rock " << endl;
		predictionString = "Scissors";
	}

    human_prediction_text->SetLabelText(predictionString);
}

void ButtonPanel::update_winner_result_text()
{
	int result;
	wxString winnerString;

	result = RPS->result(RPS->human.getChoice(), RPS->bot->getChoice());
	if (result == 0)
	    {
	     	 winnerString = "Draw";
	     	 RPS->addDraw();
	    }
	    else if (result == 1)
	    {
	    	winnerString = "Human";
	    	RPS->addHumanWin();
	    }
	    else
	    {
	       winnerString = "Bot";
	       RPS->addBotWin();
	    }
	 winner_result_text->SetLabelText(winnerString);

}

void ButtonPanel::update_statistics()
{

   human_win_text->SetLabelText(wxString::Format(wxT("%i"),RPS->getHumanWins()));
   bot_win_text->SetLabelText(wxString::Format(wxT("%i"),RPS->getBotWins()));
   draw_count_text->SetLabelText(wxString::Format(wxT("%i"),RPS->getDraws()));
}

void ButtonPanel::update_round()
{

	round_count_text->SetLabelText(wxString::Format(wxT("%i"),RPS->getRound()));

}

void ButtonPanel::update_new_game_screen(){

	round_count_text->SetLabelText(wxString::Format(wxT("%i"),RPS->getRound()));


	button_chosen_text->SetLabelText("");

	human_prediction_text->SetLabelText("");

	bot_chosen_text->SetLabelText("");

	winner_result_text->SetLabelText("");

	human_win_text->SetLabelText("0");
	bot_win_text->SetLabelText("0");
	draw_count_text->SetLabelText("0");

}

void ButtonPanel::setRPSRounds(int roundCount){

	RPS->setRound(roundCount);

}

void ButtonPanel::game_over_screen(){

	cout << "End of game!\n" << endl;
	wxMessageBox(wxString::Format(
	    	        "Game Over!\n"
	    	        "To start a new game click the 'New Game' menu \n"
	    	        "then click 'Start'\n" ));
}
