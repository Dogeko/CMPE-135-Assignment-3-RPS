#ifndef BUTTONPANEL_H_
#define BUTTONPANEL_H_

#include "ButtonDemo.h"
#include "Choice.h"
#include "Game.h"

/**
 * The button panel of the application frame.
 */
class ButtonPanel : public wxPanel
{
public:
    /**
     * Constructor.
     * @param parent the parent frame.
     */
    ButtonPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {
    	RPS = new Game;
        init();
    }

    void new_game()
    {

        delete RPS;
        RPS = new Game;

    }

    /**
     * Event handler for the rock button.
     * @param event the button click event.
     */
    void on_rock(wxCommandEvent &event);

    /**
     * Event handler for the paper button.
     * @param event the button click event.
     */
    void on_paper(wxCommandEvent &event);

    /**
     * Event handler for the scissors button.
     * @param event the button click event.
     */
    void on_scissors(wxCommandEvent &event);

    ~ButtonPanel()
    {
        delete RPS;
        cout << "deleting rps...\n";
    }

    void setRPSRounds(int roundCount);
    void update_new_game_screen();

private:
    Game *RPS;
    wxStaticText *round_count_text;
    wxStaticText *button_chosen_text;
    wxStaticText *computer_chosen_text;
    wxStaticText *winner_result_text;
    wxStaticText *human_win_text;
    wxStaticText *computer_win_text;
    wxStaticText *draw_count_text;
    wxStaticText *human_prediction_text;
    bool firstGame = true;

    /**
     * Initialize the panel contents.
     */
    void init();

    /**
     * Update the displayed button choice object.
     * @param choice the chosen object.
     */
    void update_button_choice_text(const Choice choice);
    void update_computer_choice_text(int humanChoice);
    void update_computer_prediction_choice_text(int humanChoice);
//    void update_winner_result_text(const std::string winner);
    void update_winner_result_text();
    void update_statistics();
    void update_round();
    void update_human_prediction_text(const Choice choice);



};

#endif /* BUTTONPANEL_H_ */
