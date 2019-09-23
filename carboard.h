/******************************************************************************
** Student name: Kevin Wong
** Student number: s3603055
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#ifndef CARBOARD_H
#define CARBOARD_H

#include "helpers.h"
#include "game.h"

#define STUDENT_NAME "Kevin Wong"
#define STUDENT_ID "s3603055"
#define STUDENT_EMAIL "s3603055@student.rmit.edu.au"

typedef struct choice
{
    char choice;

} Choice;

/**
 * Main menu option 2 - show your student information as per the specification.
 *
 * You should change the defines above related to student information and use
 * them when printing.
 */

void displayMenu();
void displayCommands();
void displayStudentInformation();


#endif
