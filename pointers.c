#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void course();
void exp1();
void exp2();
void exp3();
void sizeofdata();
void pointerArray();
void memoireAndPointer();
void game();

int main(){

    //course();
    //exp1();
    //exp2();
    //exp3();
    //sizeofdata();
    //pointerArray();
    //memoireAndPointer();
    game();


    return 0;
}


void course(){
    printf("This is the pointers course:\n");
    int x =10;
    printf(" x value = %d\n", x);
    printf(" x address = %p\n", &x); // طبع عنوان المتغير في الذاكرة

    int *xPointer = &x; // تخزين عنوان متخير في متغير مؤشر
    printf(" x pointer = %p\n", xPointer);
    printf("x address = %p and x value = %d\n", xPointer,*xPointer); // للوصول ليقمة المتغير عن طريق المؤشر

    *xPointer = 15; //تعديل قيمة المتغير بواسطة المؤشر
    printf("%p and %d \n", xPointer, *xPointer);
    printf("x value = %d\n", x);

}


void exp1(){
    printf("This is the pointers example 01 :\n ");
    int x = 10;
    int *p = &x;
    x++;
    printf("%d\n", *p);
}

void exp2(){
    printf("This is the pointers example 02:\n ");
    int x = 50;
    int y = 70;

    int *p1 = &x;
    x+=10;
    p1 = &y;
    printf("%d\n", *p1);

}

void exp3(){
    printf("This is the pointers example 03:\n ");
    int x = 5, *ptr = &x;
    printf("%d\n", *ptr**ptr); // *ptr**ptr = x*x because *ptr = x !
    printf("%d\n", *&x); // &x = address and *&x = x and we can't put &*x because *x not pointer !
    printf("%p\n", &*ptr); // *ptr = x and &*ptr = &x = address x !
    printf("%p\n", *&ptr);
}

void sizeofdata() {
    printf("This is the pointers course sizeof\n ");
    int a = 5;
    float b = 2.1;
    double c = 5.11254;
    char d = 'a';
    int arrayE[4] = {15, 48, 93, 100};

    printf("size of a is : %d\n", sizeof(a));
    printf("size of b is : %d\n", sizeof(b));
    printf("size of c is : %d\n", sizeof(c));
    printf("size of d is : %d\n", sizeof(d));
    printf("size of arrayE is : %d\n", sizeof(arrayE));

}

void pointerArray(){
    printf("this is the pointers course - the operations in pointers array\n");
    int array[4] = {10, 20, 30, 40};
    int *arPtr = &array[0];

    printf("Array is just pointer! \n");
    printf("the value of the array is : %p\n", array);
    printf("the address of the array is : %p\n", &array);
    printf("the address of the first element in the array is : %p\n", &array[0]);
    printf("\n so the value and the address of array == the address of the first element in the array\n!");
    for(int i=0; i<4; i++) {
        printf("Address of the %d position is : %p and the value of the second is : %d\n", i, arPtr + i, *(arPtr + i));
    }
}

void memoireAndPointer() {

    int s;
    printf("Please enter the size of your array: ");
    scanf("%d", &s);

    int *array = (int *)malloc(s); // create array == array[s]
    int *pointer = array;

    for(int i=0; i<s; i++,array++){
        *array = 10;
    }
    array = pointer;
    for(int i=0; i<s; i++,array++) {
        printf("--%d", *array);
    }
    array = pointer;
    free(array);
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
