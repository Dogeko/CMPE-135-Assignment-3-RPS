#include "Game.h"

void Game::play()
{
    char algo_type;
    char check = 'a';
    cout << "Choose BOT algorithm:" << endl;
    cout << "Type 'R' for random OR 'S' for smart" << endl;
    cin >> algo_type;
    round = 20;

    bot = BotFactory::pickAlgo(algo_type);
    while (check != 'n') {
        for (int i = 0; i < round; i++) {
            cout << "Round " << i + 1 << endl;
            human.playerPick();
            bot->pick(human.getChoice());
            printResult(result(human.getChoice(), bot->getChoice()));
        }
        cout << "Game Over!" << endl;
        cout << "Would you like to play another game? (y/n): ";
        while (check != 'n')
        {
            cin >> check;
            if (check == 'y')
            {
                break;
            }
        }
    }
}

int Game::result(int humanChoice, int botChoice)
{
    if (humanChoice == botChoice)
    {
        return 0;
    }
    else if ((humanChoice == 0) && (botChoice == 2))
    {
        return 1;
    }
    else if ((humanChoice == 1) && (botChoice == 0))
    {
        return 1;
    }
    else if ((humanChoice == 2) && (botChoice == 1))
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

void Game::printResult(int result)
{
    if (result == 0)
    {
        cout << "Draw!" << endl;
    }
    else if (result == 1)
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "You lose!" << endl;
    }
}