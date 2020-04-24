#include "Game.h"

//Facade pattern is used here. There are many differnt classes running inside this one class
void Game::play()
{
    //Strategy pattern is used here.
    char algo_type;
    char check = 'a';
    cout << "Choose BOT algorithm:" << endl;
    cout << "Type 'R' for random AI or 'S' for state AI" << endl;
    cin >> algo_type;

    bot = BotFactory::pickAlgo(algo_type);
    
    //gameplay starts here
    while(!gameOver){
        human.playerPick();
        bot->pick(human.getChoice());
        printResult(result(human.getChoice(), bot->getChoice()));
        if({/*ONE CHOICE ENDS THE GAME*/}){
            gameover = true;
        }
    }
}