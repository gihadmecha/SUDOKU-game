
#include "SUDOKU.h"

static signed int SUDOKU_element[9][3][3];
static signed int SUDOKU_fixedElement[9][3][3] = {0};

void SUDOKU_initialize ()
{
    SUDOKU_element[0][0][0] = 0; SUDOKU_element[0][0][1] = 0; SUDOKU_element[0][0][2] = 5; SUDOKU_element[1][0][0] = 0; SUDOKU_element[1][0][1] = 0; SUDOKU_element[1][0][2] = 0; SUDOKU_element[2][0][0] = 8; SUDOKU_element[2][0][1] = 0; SUDOKU_element[2][0][2] = 0;
    SUDOKU_element[0][1][0] = 8; SUDOKU_element[0][1][1] = 1; SUDOKU_element[0][1][2] = 6; SUDOKU_element[1][1][0] = 0; SUDOKU_element[1][1][1] = 0; SUDOKU_element[1][1][2] = 5; SUDOKU_element[2][1][0] = 4; SUDOKU_element[2][1][1] = 2; SUDOKU_element[2][1][2] = 7;
    SUDOKU_element[0][2][0] = 7; SUDOKU_element[0][2][1] = 0; SUDOKU_element[0][2][2] = 2; SUDOKU_element[1][2][0] = 6; SUDOKU_element[1][2][1] = 0; SUDOKU_element[1][2][2] = 0; SUDOKU_element[2][2][0] = 0; SUDOKU_element[2][2][1] = 1; SUDOKU_element[2][2][2] = 9;
    SUDOKU_element[3][0][0] = 2; SUDOKU_element[3][0][1] = 0; SUDOKU_element[3][0][2] = 0; SUDOKU_element[4][0][0] = 0; SUDOKU_element[4][0][1] = 0; SUDOKU_element[4][0][2] = 7; SUDOKU_element[5][0][0] = 3; SUDOKU_element[5][0][1] = 0; SUDOKU_element[5][0][2] = 1;
    SUDOKU_element[3][1][0] = 6; SUDOKU_element[3][1][1] = 9; SUDOKU_element[3][1][2] = 0; SUDOKU_element[4][1][0] = 1; SUDOKU_element[4][1][1] = 0; SUDOKU_element[4][1][2] = 8; SUDOKU_element[5][1][0] = 7; SUDOKU_element[5][1][1] = 0; SUDOKU_element[5][1][2] = 0;
    SUDOKU_element[3][2][0] = 3; SUDOKU_element[3][2][1] = 7; SUDOKU_element[3][2][2] = 1; SUDOKU_element[4][2][0] = 5; SUDOKU_element[4][2][1] = 0; SUDOKU_element[4][2][2] = 0; SUDOKU_element[5][2][0] = 0; SUDOKU_element[5][2][1] = 4; SUDOKU_element[5][2][2] = 0;
    SUDOKU_element[6][0][0] = 0; SUDOKU_element[6][0][1] = 6; SUDOKU_element[6][0][2] = 0; SUDOKU_element[7][0][0] = 9; SUDOKU_element[7][0][1] = 0; SUDOKU_element[7][0][2] = 2; SUDOKU_element[8][0][0] = 0; SUDOKU_element[8][0][1] = 0; SUDOKU_element[8][0][2] = 0;
    SUDOKU_element[6][1][0] = 1; SUDOKU_element[6][1][1] = 0; SUDOKU_element[6][1][2] = 3; SUDOKU_element[7][1][0] = 0; SUDOKU_element[7][1][1] = 4; SUDOKU_element[7][1][2] = 0; SUDOKU_element[8][1][0] = 9; SUDOKU_element[8][1][1] = 7; SUDOKU_element[8][1][2] = 0;
    SUDOKU_element[6][2][0] = 5; SUDOKU_element[6][2][1] = 8; SUDOKU_element[6][2][2] = 0; SUDOKU_element[7][2][0] = 7; SUDOKU_element[7][2][1] = 0; SUDOKU_element[7][2][2] = 0; SUDOKU_element[8][2][0] = 2; SUDOKU_element[8][2][1] = 6; SUDOKU_element[8][2][2] = 4;
}

void SUDOKU_original ()
{
    for (u32 squareIndex = 0; squareIndex < 9; squareIndex++)
    {
        for (u32 rowIndex = 0; rowIndex < 3; rowIndex++)
        {
            for (u32 columnIndex = 0; columnIndex < 3; columnIndex++)
            {
                SUDOKU_fixedElement[squareIndex][rowIndex][columnIndex] = SUDOKU_element[squareIndex][rowIndex][columnIndex];
            }
        }
    }
}

void SUDOKU_set ()
{
   c_textbackground(WHITE);

   printf ("\n");

   for (u32 rowIndex = 0; rowIndex < 3; rowIndex++)
   {
        c_textcolor(DARKGRAY);
        printf ("+-----+-----+-----");
        c_textcolor(BLACK);
        printf ("+");
        c_textcolor(DARKGRAY);
        printf ("-----+-----+-----");
        c_textcolor(BLACK);
        printf ("+");
        c_textcolor(DARKGRAY);
        printf ("-----+-----+-----+");
        printf ("\n");
        printf ("|");
        for (u32 squareIndex = 0; squareIndex < 3; squareIndex++)
        {
            for (u32 columnIndex = 0; columnIndex < 3; columnIndex++)
            {
                printf ("  ");
                if(SUDOKU_element[squareIndex][rowIndex][columnIndex] == 0)
                {
                    printf (" ");
                }
                else
                {
                    if (SUDOKU_fixedElement[squareIndex][rowIndex][columnIndex] != 0)
                        c_textcolor(BLACK);
                    else
                        c_textcolor(DARKGRAY);

                    printf ("%c", SUDOKU_element[squareIndex][rowIndex][columnIndex]+'0');

                }

                if (columnIndex == 2 && (squareIndex == 0 || squareIndex == 1))
                    c_textcolor(BLACK);
                else
                    c_textcolor(DARKGRAY);
                    
                printf ("  |");  
            } 
        }
        printf ("\n");
   }

   for (u32 rowIndex = 0; rowIndex < 3; rowIndex++)
   {
        if (rowIndex == 0)
        {
            c_textcolor(BLACK);
            printf ("+-----+-----+-----+-----+-----+-----+-----+-----+-----+");
            c_textcolor(DARKGRAY);
        }
        else
        {
            printf ("+-----+-----+-----");
            c_textcolor(BLACK);
            printf ("+");
            c_textcolor(DARKGRAY);
            printf ("-----+-----+-----");
            c_textcolor(BLACK);
            printf ("+");
            c_textcolor(DARKGRAY);
            printf ("-----+-----+-----+");
        }
        printf ("\n");
        printf ("|");
        for (u32 squareIndex = 3; squareIndex < 6; squareIndex++)
        {
            for (u32 columnIndex = 0; columnIndex < 3; columnIndex++)
            {
                printf ("  ");
                if(SUDOKU_element[squareIndex][rowIndex][columnIndex] == 0)
                {
                    printf (" ");
                }
                else
                {
                    if (SUDOKU_fixedElement[squareIndex][rowIndex][columnIndex] != 0)
                        c_textcolor(BLACK);
                    else
                        c_textcolor(DARKGRAY);

                    printf ("%c", SUDOKU_element[squareIndex][rowIndex][columnIndex]+'0');
                }

                if (columnIndex == 2 && (squareIndex == 3 || squareIndex == 4))
                    c_textcolor(BLACK);
                else
                    c_textcolor(DARKGRAY);

                printf ("  |");  
            } 
        }
        printf ("\n");
   }

   for (u32 rowIndex = 0; rowIndex < 3; rowIndex++)
   {
        if (rowIndex == 0)
        {
            c_textcolor(BLACK);
            printf ("+-----+-----+-----+-----+-----+-----+-----+-----+-----+");
            c_textcolor(DARKGRAY);
        }
        else
        {
            printf ("+-----+-----+-----");
            c_textcolor(BLACK);
            printf ("+");
            c_textcolor(DARKGRAY);
            printf ("-----+-----+-----");
            c_textcolor(BLACK);
            printf ("+");
            c_textcolor(DARKGRAY);
            printf ("-----+-----+-----+");
        }
        printf ("\n");
        printf ("|");
        for (u32 squareIndex = 6; squareIndex < 9; squareIndex++)
        {
            for (u32 columnIndex = 0; columnIndex < 3; columnIndex++)
            {
                printf ("  ");
                if(SUDOKU_element[squareIndex][rowIndex][columnIndex] == 0)
                {
                    printf (" ");
                }
                else
                {
                    if (SUDOKU_fixedElement[squareIndex][rowIndex][columnIndex] != 0)
                        c_textcolor(BLACK);
                    else
                        c_textcolor(DARKGRAY);

                    printf ("%c", SUDOKU_element[squareIndex][rowIndex][columnIndex]+'0');
                }

                if (columnIndex == 2 && (squareIndex == 6 || squareIndex == 7))
                    c_textcolor(BLACK);
                else
                    c_textcolor(DARKGRAY);
                    
                printf ("  |"); 
            } 
        }
        printf ("\n");
   }
   printf ("+-----+-----+-----");
   c_textcolor(BLACK);
   printf ("+");
   c_textcolor(DARKGRAY);
   printf ("-----+-----+-----");
   c_textcolor(BLACK);
   printf ("+");
   c_textcolor(DARKGRAY);
   printf ("-----+-----+-----+");

   printf ("\n");
   printf ("\n");
}

coordinate SUDOKU_scanCoordinate ()
{
    coordinate coordinate;
    s32 square = -1, row = -1, column = -1; 
    
    while (square < 1 || square > 9)
    {
        c_textcolor(LIGHTCYAN);
        printf ("Enter Square NO. from 1 to 9: ");
        c_textcolor(LIGHTMAGENTA);
        scanf ("%d", &square);
    }

    while (row < 1 || row > 3)
    {
        c_textcolor(LIGHTCYAN);
        printf ("Enter Row NO. from 1 to 3: ");
        c_textcolor(LIGHTMAGENTA);
        scanf ("%d", &row);
    }

    while (column < 1 || column > 3)
    {
        c_textcolor(LIGHTCYAN);
        printf ("Enter Column NO. from 1 to 3: ");
        c_textcolor(LIGHTMAGENTA);
        scanf ("%d", &column);
    }

    coordinate.square = square - 1;
    coordinate.row = row - 1;
    coordinate.column = column - 1;

    return coordinate;
}

s32 SUDOKU_scanNumber ()
{
    s32 number = -1;
    while (number < 0 || number > 9)
    {
        c_textcolor(LIGHTCYAN);
        printf ("Enter Number from 1 to 9: ");
        c_textcolor(LIGHTMAGENTA);
        scanf ("%d", &number);
    }

    return number;
}

coordinate SUDOKU_check ( coordinate desiredCoordinate, s32 number)
{
    coordinate similarCoordinate;

    //check square
    for (u32 row = 0; row < 3; row++)
    {
        for (u32 column = 0; column < 3; column++)
        {
            if (SUDOKU_element[desiredCoordinate.square][row][column] == number)
            {
                similarCoordinate.ack = 0;
                similarCoordinate.square = desiredCoordinate.square;
                similarCoordinate.row = row;
                similarCoordinate.column = column;

                return similarCoordinate;
            }
            else
            {
                similarCoordinate.ack = 1;
            }
        }
    }

    //check the big Row
    if (desiredCoordinate.square == 0 || desiredCoordinate.square == 1 || desiredCoordinate.square == 2)
    {
        for (u32 square = 0; square < 3; square++)
        {
            for (u32 column = 0; column < 3; column++)
            {
                if (SUDOKU_element[square][desiredCoordinate.row][column] == number)
                {
                    similarCoordinate.ack = 0;
                    similarCoordinate.square = square;
                    similarCoordinate.row = desiredCoordinate.row;
                    similarCoordinate.column = column;

                    return similarCoordinate;
                }
                else
                {
                    similarCoordinate.ack = 1;
                }
            }
        }
    }
    else if (desiredCoordinate.square == 3 || desiredCoordinate.square == 4 || desiredCoordinate.square == 5)
    {
        for (u32 square = 3; square < 6; square++)
        {
            for (u32 column = 0; column < 3; column++)
            {
                if (SUDOKU_element[square][desiredCoordinate.row][column] == number)
                {
                    similarCoordinate.ack = 0;
                    similarCoordinate.square = square;
                    similarCoordinate.row = desiredCoordinate.row;
                    similarCoordinate.column = column;

                    return similarCoordinate;
                }
                else
                {
                    similarCoordinate.ack = 1;
                }
            }
        }
    }
    else if (desiredCoordinate.square == 6 || desiredCoordinate.square == 7 || desiredCoordinate.square == 8)
    {
        for (u32 square = 6; square < 9; square++)
        {
            for (u32 column = 0; column < 3; column++)
            {
                if (SUDOKU_element[square][desiredCoordinate.row][column] == number)
                {
                    similarCoordinate.ack = 0;
                    similarCoordinate.square = square;
                    similarCoordinate.row = desiredCoordinate.row;
                    similarCoordinate.column = column;

                    return similarCoordinate;
                }
                else
                {
                    similarCoordinate.ack = 1;
                }
            }
        }
    }

    //check the big Column
    if (desiredCoordinate.square == 0 || desiredCoordinate.square == 3 || desiredCoordinate.square == 6)
    {
        for (u32 square = 0; square < 3; square+=3)
        {
            for (u32 row = 0; row < 3; row++)
            {
                if (SUDOKU_element[square][row][desiredCoordinate.column] == number)
                {
                    similarCoordinate.ack = 0;
                    similarCoordinate.square = square;
                    similarCoordinate.row = row;
                    similarCoordinate.column = desiredCoordinate.column;

                    return similarCoordinate;
                }
                else
                {
                    similarCoordinate.ack = 1;
                }
            }
        }
    }
    else if (desiredCoordinate.square == 1 || desiredCoordinate.square == 4 || desiredCoordinate.square == 7)
    {
        for (u32 square = 3; square < 6; square+=3)
        {
            for (u32 row = 0; row < 3; row++)
            {
                if (SUDOKU_element[square][row][desiredCoordinate.column] == number)
                {
                    similarCoordinate.ack = 0;
                    similarCoordinate.square = square;
                    similarCoordinate.row = row;
                    similarCoordinate.column = desiredCoordinate.column;

                    return similarCoordinate;
                }
                else
                {
                    similarCoordinate.ack = 1;
                }
            }
        }
    }
    else if (desiredCoordinate.square == 2 || desiredCoordinate.square == 5 || desiredCoordinate.square == 8)
    {
        for (u32 square = 6; square < 9; square+=3)
        {
            for (u32 row = 0; row < 3; row++)
            {
                if (SUDOKU_element[square][row][desiredCoordinate.column] == number)
                {
                    similarCoordinate.ack = 0;
                    similarCoordinate.square = square;
                    similarCoordinate.row = row;
                    similarCoordinate.column = desiredCoordinate.column;

                    return similarCoordinate;
                }
                else
                {
                    similarCoordinate.ack = 1;
                }
            }
        }
    }

    return similarCoordinate;  
}

s32 SUDOKU_youAreTheWinner ()
{
    coordinate coordinate;
    for (u32 square = 0; square < 9; square++)
    {
        for (u32 row = 0; row < 3; row++)
        {
            for (u32 column = 0; column < 9; column++)
            {
                coordinate.square = square;
                coordinate.row = row;
                coordinate.column = column;
                if (SUDOKU_element[square][row][column] == 0 || SUDOKU_check (coordinate, SUDOKU_element[square][row][column]).ack == 0)
                    return 0;
            }
        }
    }
    return 1;
}

void SUDOKU_play ()
{
    while (SUDOKU_youAreTheWinner () == 0)
    {
        SUDOKU_set ();

        coordinate desiredCoordinate = SUDOKU_scanCoordinate ();

        while (SUDOKU_fixedElement[desiredCoordinate.square][desiredCoordinate.row][desiredCoordinate.column] != 0)
        {
            c_textcolor(RED);
            printf ("\nit's not available space !!\n");
            printf ("please, choose another allowed space !!\n\n");

            desiredCoordinate = SUDOKU_scanCoordinate ();
        }

        s32 number = SUDOKU_scanNumber ();

        coordinate similarCoordinate = SUDOKU_check (desiredCoordinate, number);

        if (number == 0)
        {
            SUDOKU_element[desiredCoordinate.square][desiredCoordinate.row][desiredCoordinate.column] = number;
            c_textcolor(LIGHTRED);
            printf ("\n\n(%d, %d, %d) deleted !!\n\n", similarCoordinate.square+1, similarCoordinate.row+1, similarCoordinate.column+1);
        }
        else if (similarCoordinate.ack)
        {
            SUDOKU_element[desiredCoordinate.square][desiredCoordinate.row][desiredCoordinate.column] = number;
            c_textcolor(LIGHTGREEN);
            printf ("\nWell Done !!\n\n");
        }
        else
        {
            c_textcolor(LIGHTRED);
            printf ("\n\nit's Exist at (%d, %d, %d) !!\n", similarCoordinate.square+1, similarCoordinate.row+1, similarCoordinate.column+1);
            printf ("\n");
            printf ("please, Try again !!\n\n");
        }
    }

    printf ("                               Congratulations                                  \n");
    printf ("                            Your're The Winner !!                               \n");
}

void SUDOKU ()
{
    SUDOKU_initialize ();
    SUDOKU_original ();
    SUDOKU_play ();
}