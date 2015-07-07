//
//  ScoreKeeper.h
//  Rabbits
//
//  Created by Ethan McCue on 5/17/14.
//
//

#ifndef __Rabbits__ScoreKeeper__
#define __Rabbits__ScoreKeeper__

#define defaultAmountOfLives 3
typedef enum
{
    pinkMissile,
    greenMissile,
    eitherMissile
}PossibleCauseOfDeath;
class ScoreKeeper
{
public:
    ScoreKeeper();
    void addToScore(int x);
    void subtractFromScore(int x);
    int getScore(void);
    void setScore(int x);
    
    void setLives(int x);
    int getLives(void);
    
    bool isPaused(void);
    void setPaused(void);
    void setUnPaused(void);
    
    int getHighScore(void);
    void setHighScore(int score);
    
    int getLastScore(void);
    void setLastScore(int score);
    
    PossibleCauseOfDeath getDeathCause(void);
    void setCauseOfDeath(PossibleCauseOfDeath death);
private:
    int score;
    int lives;
    bool paused;
    int highScore;
    int lastScore;
    PossibleCauseOfDeath  _death;
};



#endif /* defined(__Rabbits__ScoreKeeper__) */
