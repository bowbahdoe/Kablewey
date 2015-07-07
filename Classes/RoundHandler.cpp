//
//  RoundHandler.cpp
//  Kablewey
//
//  Created by John McCue on 6/26/14.
//
//

#include "RoundHandler.h"
#include <cocos2d.h>
RoundHandler::RoundHandler()
{
    this->_timePassed = 0;
    this->_round = round_1;
}
void RoundHandler::subtractTime(float dt)
{
    this->_timePassed-=dt;
}
void RoundHandler::addTime(float dt)
{
    //Boring, repetitive code
    this->_timePassed+=dt;
    switch (_round) {
        case round_1:
            if(_timePassed>round_1_length)
            {
                _timePassed = 0;
                _round = round_1_delay;
                CCLOG("Round 1 Over");
            }
            break;
        case round_1_delay:
            if(_timePassed>round_1_delay_length)
            {
                _timePassed = 0;
                _round = round_2;
                CCLOG("Round 2 Started");
            }
            break;
        case round_2:
            
            if(_timePassed>round_2_length)
            {
                _timePassed = 0;
                _round = round_2_delay;
                CCLOG("Round 2 Over");
            }
            break;
        case round_2_delay:
            if(_timePassed>round_2_delay_length)
            {
                _timePassed = 0;
                _round = round_3;
                CCLOG("Round 3 Started");
            }
            break;
        case round_3:
            
            if(_timePassed>round_3_length)
            {
                _timePassed = 0;
                _round = round_3_delay;
                
                CCLOG("Round 3 Over");
            }
            break;
        case round_3_delay:
            
            if(_timePassed>round_3_delay_length)
            {
                _timePassed = 0;
                _round = round_4;
                CCLOG("Round 4 Started");
            }
            break;
        case round_4:
            if(_timePassed>round_4_length)
            {
                _timePassed = 0;
                _round = round_4_delay;
                CCLOG("Round 4 Over");
            }
            
            break;
        case round_4_delay:
            if(_timePassed>round_4_delay_length)
            {
                _timePassed= 0;
                _round = round_5;
                CCLOG("Round 5 Started");
            }
            
            break;
        case round_5:
            if(_timePassed>round_5_length)
            {
                _timePassed = 0;
                _round = round_5_delay;
                CCLOG("Round 5 Over");
            }
            break;
        case round_5_delay:
        //loop on Round 5 until I think of something to do after that
            if(_timePassed>round_5_delay_length)
            {
                _timePassed = 0;
                _round = round_5;
                CCLOG("Round 5 Started");
            }
            break;
        default:
            CCLOG("Round System Messed Up");
            break;
    }

}
float RoundHandler::getTimePassedInRound(void)
{
    return this->_timePassed;
}

Round RoundHandler::getRound(void)
{
    return this->_round;
}