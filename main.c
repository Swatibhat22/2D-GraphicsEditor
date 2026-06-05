#include <stdio.h>
#include <stdlib.h>
#define ROWS 20
#define COLS 60

char canvas[ROWS][COLS];
void initializeCanvas();
void displayCanvas();
void clearCanvas();

void initializeCanvas(){
    int i,j;
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            canvas[i][j]=' ';
        }
    }
}

void displayCanvas(){
    int i,j;
    printf("\n");
    printf("  ");
    for(j=0; j<COLS; j++){
        printf("%d",j%10);

    }
    printf("\n");
    for(int i=0; i<ROWS; i++){
        printf("%2d",i);
        for(j=0; j<COLS;j++){
            printf("%c",canvas[i][j]);

        }
        printf("\n");
    }
    printf("\n");
}

void clearCanvas(){
    initializeCanvas();
    printf("\nCanvas Cleared Successfully!\n");
}

void plotPoint(int x, int y);
void drawLine(int x1, int y1, int x2, int y2);

int main()
{
    int choice;

    initializeCanvas();

    while(1)
    {
        printf("\n");
        printf("===================================\n");
        printf("       ASCII GRAPHICS EDITOR\n");
        printf("===================================\n");
        printf("1. Draw Line\n");
        printf("2. Display Canvas\n");
        printf("3. Clear Canvas\n");
        printf("4. Exit\n");
        printf("Enter Choice : ");

        scanf("%d", &choice);

        switch(choice)
    {
    case 1:
    {
        int x1, y1, x2, y2;

        printf("Enter Starting Point (row col): ");
        scanf("%d %d", &x1, &y1);

        printf("Enter Ending Point (row col): ");
        scanf("%d %d", &x2, &y2);

        drawLine(x1, y1, x2, y2);

        printf("Line Drawn Successfully!\n");
        break;
    }

    case 2:
        displayCanvas();
        break;

    case 3:
        clearCanvas();
        break;

    case 4:
        printf("Program Closed.\n");
        return 0;

    default:
        printf("Invalid Choice!\n");
       }
    }

    return 0;
}

void plotPoint(int x, int y)
{
    if(x >= 0 && x < ROWS && y >= 0 && y < COLS)
    {
        canvas[x][y] = '*';
    }
}

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    int i;

    for(i = 0; i <= steps; i++)
    {
        plotPoint((int)x, (int)y);

        x += xIncrement;
        y += yIncrement;
    }
}
