#include "game.h"
#include <stdio.h>  // this is for the standard input and output functions.
#include <time.h>   // this is for all the time() related functions.
#include <stdlib.h> // this is for the system() function, srand() function and rand() function.
char box[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player1[50], player2[50] = {'c', 'o', 'm'}, mark;
void intro()
{
    printf("0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0\n");
    printf("\n\t\t\t\t\t\t || Welcome To The TIC TAC TOE Game ||\t\t\t\t\t\n");
}
void gameChoice()
{
    int twoChoices = 0;
    do
    {   if (twoChoices != 0)
        {
            printf("\nInvalid choice... Enter Again!\n");
        }
        printf("\n\n--> 1 Player Game (PRESS 1)\n");
        printf("\n--> 2 Player Game (PRESS 2)\n");
        printf("\nYour choice:\n");
        scanf("%d", &twoChoices);
    } while (twoChoices != 1 && twoChoices != 2);
    intro();
    if (twoChoices == 1)
    {
        printf("\nLet's start the game between You and Computer.\n");
        gameBuildForOnePlayer();
    }
    else
    {
        printf("\nLet's start the game between You and Your Friend.\n");
        gameBuildForTwoPlayers();
    }
}
void greet()
{
    time_t t;
    time(&t);
    printf("\n\n\t\t\t\t\t\t\t%s", ctime(&t));
    time_t s;
    struct tm *current_time;
    s = time(NULL);                     // time in seconds
    current_time = localtime(&s);          // to get current time
    if (current_time->tm_hour >= 5 && current_time->tm_hour < 12)
        printf("\n\nA Very GOOD MORNING %s and %s.\n", player1, player2);
    else if (current_time->tm_hour >= 12 && current_time->tm_hour < 17)
        printf("\n\nGOOD AFTERNOON %s and %s.\n", player1, player2);
    else if (current_time->tm_hour >= 17 && current_time->tm_hour < 21)
        printf("\n\nGOOD EVENING %s and %s.\n", player1, player2);
    else
        printf("\n\nGOOD NIGHT %s and %s. \n",player1,player2);
}
int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}
void gameBoard()  //*************************  FUNCTION 5 --> For the game board   *************************
{
    intro();
    greet();
    printf("\n\t\n%s [O] & ", player1);
    printf("%s [X]", player2);
    printf("\n\n\n");
    printf("  %c |  %c |  %c \n", box[1], box[2], box[3]);
    printf(" ___|____|____\n");
    printf("    |    |     \n");
    printf("  %c |  %c |  %c \n", box[4], box[5], box[6]);
    printf(" ___|____|____\n");
    printf("    |    |     \n");
    printf("  %c |  %c |  %c \n", box[7], box[8], box[9]);
    printf("\n\n\n");
}
int checkWinner() //*************************  FUNCTION 6 --> For calculating the winner   *************************
{

    if (box[1] != '1' && box[2] != '2' && box[3] != '3' && box[4] != '4' && box[5] != '5' && box[6] != '6' && box[7] != '7' && box[8] != '8' && box[9] != '9')
        return 0;
    else if (box[1] == box[2] && box[2] == box[3])
        return 1;
    else if (box[1] == box[4] && box[4] == box[7])
        return 1;
    else if (box[3] == box[6] && box[6] == box[9])
        return 1;
    else if (box[4] == box[5] && box[5] == box[6])
        return 1;
    else if (box[7] == box[8] && box[8] == box[9])
        return 1;
    else if (box[1] == box[5] && box[5] == box[9])
        return 1;
    else if (box[3] == box[5] && box[5] == box[7])
        return 1;
    else
        return -1;
}
void gameBuildForOnePlayer()  //*************************  FUNCTION 7 -->  game build for one player Game   ***************
{   int winValue = 0, playersChoice, playerValue = 1;
    printf("\n\nPlayer 1 please enter your name:\n");
    fflush(stdin);
    gets(player1);
    fflush(stdin);
    do
    {   gameBoard();
        playerValue = (playerValue % 2) ? 1 : 2;
        printf("\n------------------------------\n");
        mark = (playerValue == 1) ? 'O' : 'X';
        if (playerValue == 1)
        {   printf("%s, please enter your choice:\n", player1);
            scanf("%d", &playersChoice);}
        else
        {   playersChoice = generateRandomNumber(9) + 1;
            printf("Computer Choose :\n%d\n", playersChoice);}
        markplay(playersChoice,playerValue);
        //getchar();
        winValue = checkWinner();
        playerValue++;
    } while (winValue == -1);
    gameBoard();
    if (winValue == 1)
    {   if (playerValue - 1 == 1)
            printf("\nCONGRATS %s! You won the game.\n", player1);
        else
            printf("\nOops! Computer won the game.\n");}
    else
    {    printf("Game is draw.\n");}
    thanks();
}
void gameBuildForTwoPlayers()  //*************************  FUNCTION 8 -->  game build for two player Game   *************************
{   int winValue = 0, playersChoice, playerValue = 1;
    printf("\n\nPlayer 1 please enter your name:\n");
    fflush(stdin);
    gets(player1);
    printf("\n\nPlayer 2 please enter your name:\n");
    gets(player2);
    fflush(stdin);
    do
    {   gameBoard();
        playerValue = (playerValue % 2) ? 1 : 2;
        (playerValue == 1) ? printf("%s, please enter your choice:\n", player1) : printf("%s, please enter your choice:\n", player2);
        scanf("%d", &playersChoice);
        mark = (playerValue == 1) ? 'O' : 'X';
        markplay(playersChoice,playerValue);
        //getchar();
        winValue = checkWinner();
        playerValue++;
    } while (winValue == -1);
    gameBoard();
    if (winValue == 1){
        printf(" CONGRATS ");
        (playerValue - 1 == 1) ? printf("%s!", player1) : printf("%s!", player2);
        printf(" You won the game.\n"); }
    else
    {printf("Game is draw.\n");}
    thanks();
}
void markplay(int playersChoice ,int playerValue )
{   
         if (playersChoice == 1 && box[1] == '1')
            box[1] = mark;
        else if (playersChoice == 2 && box[2] == '2')
            box[2] = mark;
        else if (playersChoice == 3 && box[3] == '3')
            box[3] = mark;
        else if (playersChoice == 4 && box[4] == '4')
            box[4] = mark;
        else if (playersChoice == 5 && box[5] == '5')
            box[5] = mark;
        else if (playersChoice == 6 && box[6] == '6')
            box[6] = mark;
        else if (playersChoice == 7 && box[7] == '7')
            box[7] = mark;
        else if (playersChoice == 8 && box[8] == '8')
            box[8] = mark;
        else if (playersChoice == 9 && box[9] == '9')
            box[9] = mark;
        else
        {   printf("Invalid Option!\n");
            playerValue--;
            //getchar(); 
            }

}
//*************************  FUNCTION 9 --> For thanks the user for playing the game   *************************
void thanks()
{
    printf("\n\t\t\t\t\t\t || THANKS FOR PLAYING OUR GAME %s and %s. ||\t\t\t\t\t", player1, player2);
    printf("\n0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0X0\n");
}

//*************************  FUNCTION 10 --> Driver Function   *************************
