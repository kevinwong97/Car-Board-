/******************************************************************************
** Student name: Kevin Wong
** Student number: s3603055
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "player.h"

/*Places player into position based on what the user inputs*/
void initialisePlayer(Player * player, Position position, Direction direction)
{
    player->position = position;
    player->direction = direction;
    player->moves = 0;
}

/*Checking player's direction and turns the direction based on user input*/
void turnDirection(Player * player, TurnDirection turnDirection)
{
    if(turnDirection == TURN_RIGHT){

        if(player->direction == NORTH){

            player->direction = EAST;
        }

        else if(player->direction == EAST){

            player->direction = SOUTH;
        }

        else if(player->direction == SOUTH){

            player->direction = WEST;
        }

        else if(player->direction == WEST){

            player->direction = NORTH;
        }
    }

    if(turnDirection == TURN_LEFT){

        if(player->direction == NORTH){

            player->direction = WEST;
        }

        else if(player->direction == WEST){

            player->direction = SOUTH;
        }

        else if(player->direction == SOUTH){

            player->direction = EAST;
        }

        else if(player->direction == EAST){

            player->direction = NORTH;
        }
    }
}

/*Finds out the next cell position from the player's direction*/
Position getNextForwardPosition(const Player * player)
{
    Position position;

    if(player->direction == NORTH){

        position = player->position;
        position.x --;
    }

    else if(player->direction == SOUTH){

        position = player->position;
        position.x ++;
    }

    else if(player->direction == WEST){

        position = player->position;
        position.y --;
    }

    else if(player->direction == EAST){

        position = player->position;
        position.y ++;
    }

    return position;
}

/*Updating the position of the player to the next position*/
void updatePosition(Player * player, Position position)
{
    player->position = position;
}

/*Places direction of the player's car at initialisation stage*/
void displayDirection(Direction direction) {
    if (direction == NORTH) {

        printf("%s|", DIRECTION_ARROW_OUTPUT_NORTH);
    }
    if (direction == SOUTH) {

        printf("%s|", DIRECTION_ARROW_OUTPUT_SOUTH);
    }
    if (direction == WEST) {

        printf("%s|", DIRECTION_ARROW_OUTPUT_WEST);
    }
    if (direction == EAST) {

        printf("%s|", DIRECTION_ARROW_OUTPUT_EAST);
    }
}
