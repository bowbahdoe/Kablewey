//
//  Ship.cpp
//  Kablewey
//
//  Created by Ethan McCue on 5/24/14.
//
//

#include "Ship.h"
#include "Settings.h"

Ship::Ship()
{
    if(not(EASY_MODE) )
    {
        initWithFile("PLAYER_OLD_2.png");
    }
    else
    {
        initWithFile("EASY_MODE_PLAYER.png");
    }
}