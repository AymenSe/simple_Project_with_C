#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void game();

int main(){
    game();
    return 0;
}


void game(){
    srand(time(0));

    int s,x;
    printf("enter the size of your array: ");
    scanf("%d", &s);
    printf("\n");

    int *Garray = (int *)malloc(s);
    int *Gpointer = Garray;

    for(int i=0; i<s; i++,Garray++){
        *Garray = 1 + (rand() % 10);
    }
    Garray = Gpointer;
    for(int i=0; i<s; i++,Garray++){
        printf("--%d", *Garray);
    }
    printf("\n");
    Garray = Gpointer;
    printf("enter your number between 1-10 to get how it repeat in the array:");
    scanf("%d", &x);
    int r = 0;
    for(int j=0; j<s; j++,Garray++){
        if(x == *Garray)
            r++;
    }
    
    Garray = Gpointer;
    printf("your number repeat %d times\n", r);

    printf("Thank you for play this game :) ");
    free(Garray);
}
