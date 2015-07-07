//
//  RoundHandler.h
//  Kablewey
//
//  Created by John McCue on 6/26/14.
//
//

#ifndef __Kablewey__RoundHandler__
#define __Kablewey__RoundHandler__

typedef enum
{
    round_1,
    round_1_delay,
    round_2,
    round_2_delay,
    round_3,
    round_3_delay,
    round_4,
    round_4_delay,
    round_5,
    round_5_delay
}Round;
#define round_1_length 4
#define round_1_delay_length 6
#define round_2_length 40
#define round_2_delay_length 6
#define round_3_length 25
#define round_3_delay_length 4
#define round_4_length 30
#define round_4_delay_length 6
#define round_5_length 35
#define round_5_delay_length 6
class RoundHandler
{
public:
    RoundHandler();
    void addTime(float dt);
    void subtractTime(float dt);
    float getTimePassedInRound(void);
    
    Round getRound(void);
private:
    Round _round;
    float _timePassed;
    
};

#endif /* defined(__Kablewey__RoundHandler__) */
