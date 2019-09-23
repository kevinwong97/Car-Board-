/******************************************************************************
** Student name: Kevin Wong
** Student number: s3603055
** Course:          Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "game.h"

/*This is the play game menu, where you have 4 game commands including the quit command.  */
void  playGame(Player * player, Cell board[BOARD_HEIGHT][BOARD_WIDTH]) {

    while (TRUE) {

        char *option;

        do {

            option = validateString();

            if (strcmp(option, COMMAND_TURN_LEFT_SHORTCUT) == 0 || strcmp(option, COMMAND_TURN_LEFT) == 0) {

                turnDirection(player, TURN_LEFT);
                printf("\n");
                displayBoard(board, player);
                displayGameCommands();
                player->moves ++;

            }

            else if (strcmp(option, COMMAND_TURN_RIGHT_SHORTCUT) == 0 || strcmp(option, COMMAND_TURN_RIGHT) == 0) {

                turnDirection(player, TURN_RIGHT);
                printf("\n");
                displayBoard(board, player);
                displayGameCommands();
                player->moves ++;

            }

            else if (strcmp(option, COMMAND_FORWARD) == 0 || strcmp(option, COMMAND_FORWARD_SHORTCUT) == 0){

                movePlayerForward(board, player);
                printf("\n");
                displayBoard(board, player);
                displayGameCommands();
                player->moves ++;

            }

            else if (strcmp(option, COMMAND_QUIT) == 0) {

                printf("\n");
                printf("Total player moves: ");
                printf("%i\n\n", player->moves);
                return;

            }

            else {

                printf("\n");
                printf("Invalid entry!\n\n");
            }

        } 
           while (strcmp(option, COMMAND_QUIT) != 0);
    }
}


/*Initailisation menu pops up and the user inputs game functions to load and play*/
void initialiseGame()
{
    while(TRUE){
        
        Cell board[BOARD_HEIGHT][BOARD_WIDTH];
        char str1[] = {"load 1"};
        char str2[] = {"load 2"};
        Position position;
        Direction direction;
        char *endptr;
        char *token;
        char *option;
        int xCoord;
        int yCoord;
        Player *player;
        Player playerptr;
        player = &playerptr;
               
        do {
            
            option = validateString();
            
            /*Load board 1*/
            if (strcmp(option, str1) == 0) {

                printf("\n");
                loadBoard(board, BOARD_1);
                displayBoard(board, NULL);
                displayinitMenu();

            }
            /*Load board 2*/
            else if (strcmp(option, str2) == 0) {

                printf("\n");
                loadBoard(board, BOARD_2);
                displayBoard(board, NULL);
                displayinitMenu();

            }
            /*quit play game.*/
            else if (strcmp(option, COMMAND_QUIT) == 0) {

                return;

            }

            /*Checking user input when initialising game input*/
            else if((token = strtok(option, " ")) && strcmp(token, COMMAND_INIT) == 0){ 

              token = NULL;
               
               /*player's y coordinate can only be from 0 to 10 and place the player's y position*/
               if ((token = strtok(token, ",")) != NULL) {

                 yCoord = (int) strtol(token, &endptr, 10);
                  
                  if (yCoord>= 0 && yCoord <= 9) {

                     token = NULL;
                     position.y = yCoord; 
                         
                         /*player's x coordinate can only be from 0 to 10 and place the player's x position*/
                         if((token = strtok(token, ",")) != NULL){

                            xCoord = (int) strtol(token, &endptr, 10);

                             if(xCoord >= 0 && xCoord <= 9){

                               token = NULL;
                               position.x = xCoord;

                                if((token = strtok(token, ",")) != NULL){

                                    /*User input player's direction NORTH*/
                                    if(strcmp(token, DIRECTION_NORTH) == 0 && placePlayer(board, position) == TRUE){
                                        
                                        direction = NORTH;
                                        placePlayer(board, position);
                                        initialisePlayer(player, position, direction);
                                        printf("\n");
                                        displayBoard(board, player);
                                        displayGameCommands();
                                        playGame(player, board);
                                        break;
                                    }
                            
                                    /*User input player's direction SOUTH*/
                                    else if(strcmp(token, DIRECTION_SOUTH) == 0 && placePlayer(board, position) == TRUE){

                                        direction = SOUTH;
                                        placePlayer(board, position);
                                        initialisePlayer(player, position, direction);
                                        printf("\n");
                                        displayBoard(board, player);
                                        displayGameCommands();
                                        playGame(player, board);
                                        break;

                                    }

                                    /*User input player's direction WEST*/
                                    else if(strcmp(token, DIRECTION_WEST) == 0 && placePlayer(board, position) == TRUE){

                                        direction = WEST;
                                        placePlayer(board, position);
                                        initialisePlayer(player, position, direction);
                                        printf("\n");
                                        displayBoard(board, player);
                                        displayGameCommands();
                                        playGame(player, board);
                                        break;
                                    }

                                    /*User input player's direction EAST*/
                                    else if(strcmp(token, DIRECTION_EAST) == 0 && placePlayer(board, position) == TRUE){

                                        direction = EAST;
                                        placePlayer(board, position);
                                        initialisePlayer(player, position, direction);
                                        printf("\n");
                                        displayBoard(board, player);
                                        displayGameCommands();
                                        playGame(player, board);
                                        break;
                                    }

                                    /*Checking if the cell is blocked if so, then an error message will return via print line.*/
                                    else if((strcmp(token, DIRECTION_EAST) == 0 || strcmp(token, DIRECTION_WEST) == 0 || strcmp(token, DIRECTION_NORTH) == 0 || strcmp(token, DIRECTION_SOUTH) == 0) && placePlayer(board, position) == FALSE){

                                        printf("\n");
                                        printf("The cell is blocked!\n\n");

                                    }

                                    /*Checking if the user's input is a valid direction (i.e north,south,east,west) otherwise returns an error.*/
                                    else if(strcmp(token, DIRECTION_EAST) != 0 || strcmp(token, DIRECTION_WEST) != 0 || strcmp(token, DIRECTION_NORTH) != 0 || strcmp(token, DIRECTION_SOUTH) != 0) {

                                        printf("\n");
                                        printf("Invalid entry!\n\n");

                                    }
                                        
                                    }
                                
                                else {

                                    printf("\n");
                                    printf("Invalid entry!\n\n");

                                }

                                }

                            else {

                                printf("\n");
                                printf("Invalid entry!\n\n");

                            }

                            }

                        else {

                            printf("\n");
                            printf("Invalid entry!\n\n");

                        }

                        }

                    else {

                        printf("\n");
                        printf("Invalid entry!\n\n");

                    }

                    }

                else {

                    printf("\n");
                    printf("Invalid entry!\n\n");

                }

                }

            else {

                printf("\n");
                printf("Invalid entry!\n\n");

            }
        }
        while (strcmp(option, COMMAND_QUIT) != 0);
        break;
    }
}



void displayinitMenu(){
    printf("load <g>\n");
    printf("init <x>,<y>,<direction>\n");
    printf("quit\n\n");
}

void displayGameCommands(){
    printf("forward\n");
    printf("turn_left (or l)\n");
    printf("turn_right (or r)\n");
    printf("quit\n\n");
}