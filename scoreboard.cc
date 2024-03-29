#include "scoreboard.h"

ScoreBoard::ScoreBoard() :
    score(0),
    levelScore(0),
    movesMade(0)
    { }

void ScoreBoard::addPoints(int n) {
    levelScore += n;
    score += n;
}

int ScoreBoard::getMoves(){
    return movesMade;
}

void ScoreBoard::addMoves(int n){
    movesMade += n;
}
void ScoreBoard::resetMoves(){
    movesMade = 0;
}

int ScoreBoard::getLevelScore() {
    return levelScore;
}
int ScoreBoard::getScore() {
    
    return score;
}

void ScoreBoard::resetScore() {
    score = 0;
}

void ScoreBoard::resetLevel(){
  levelScore = 0;
  movesMade = 0;
}
