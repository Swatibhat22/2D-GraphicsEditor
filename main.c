#include <stdio.h>
#include <stdlib.h>
#define ROWS 20
#define COLS 60

char canvas[ROWS][COLS];

void initializeCanvas(){
    int i,j;
    for(int i=0; i<ROWS; i++){
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
        printf("1. Display Canvas\n");
        printf("2. Clear Canvas\n");
        printf("3. Exit\n");
        printf("Enter Choice : ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayCanvas();
                break;

            case 2:
                clearCanvas();
                break;

            case 3:
                printf("\nProgram Closed.\n");
                return 0;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    }

    return 0;
}

