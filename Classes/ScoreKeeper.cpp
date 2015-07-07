//
//  ScoreKeeper.cpp
//  Rabbits
//
//  Created by Ethan McCue on 5/17/14.
//
//

#include "ScoreKeeper.h"
#include <cocos2d.h>
USING_NS_CC;
ScoreKeeper::ScoreKeeper()
{
    this->score=0;
    this->lastScore = 0;
    this->lives = defaultAmountOfLives;
    this->paused = false;
    this->_death = greenMissile;
}

void ScoreKeeper::addToScore(int x)
{
    this->score+=x;
}
void ScoreKeeper::subtractFromScore(int x)
{
    this->score-=x;
    
}
int ScoreKeeper::getScore(void)
{
    return this->score;
}
void ScoreKeeper::setScore(int x)
{
    this->score = x;
    
}
void ScoreKeeper::setLives(int x)
{
    this->lives = x;
}
int ScoreKeeper::getLives(void)
{
    return this->lives;
}
bool ScoreKeeper::isPaused(void)
{
    return paused;
}
void ScoreKeeper::setPaused(void)
{
    this->paused = true;
}
void ScoreKeeper::setUnPaused(void)
{
    this->paused = false;
}

int ScoreKeeper::getHighScore(void)
{
    auto def= UserDefault::getInstance();;
    int high_score=def->getIntegerForKey("HIGH_SCORE");
    printf("%d\n",high_score);
    return high_score;
}
void ScoreKeeper::setHighScore(int score)
{
    auto def=UserDefault::getInstance();
    def->setIntegerForKey("HIGH_SCORE", score);
    def->flush();
}
int ScoreKeeper::getLastScore(void)
{
    return lastScore;
}
void ScoreKeeper::setLastScore(int score)
{
    this->lastScore = score;
}
PossibleCauseOfDeath ScoreKeeper::getDeathCause(void)
{
    return this->_death;
}
void ScoreKeeper::setCauseOfDeath(PossibleCauseOfDeath death)
{
    this->_death = death;
}

