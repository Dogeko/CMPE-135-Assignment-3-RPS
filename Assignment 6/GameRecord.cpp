#include "GameRecord.h"

//Facade pattern is used here. There are many differnt classes running inside this one class

void GameRecord::printRecord(){

	cout<<"You won:"<<humanWins<<"times\n"<<endl;
	cout<<"Bot won:"<<botWins<<"times\n"<<endl;
	cout<<"You tied:"<<humanWins<<"times\n"<<endl;
}

void GameRecord::recordHumanWin(){

	humanWins = humanWins + 1;
}
void GameRecord::RecordBotWin(){

	botWins = botWins + 1;
}
void GameRecord::RecordDraw(){

	Draws = Draws + 1;
}
