#include<stdio.h>


char lights_up(int money,int price[],int stock[]){
    char status = ' ';
    if(money == *price)
        status = 'O';
    if(*stock == 0)
        status = 'X';
    return status;
}

int main(){

int price[5] = {1,2,3,4,5};
int stock[5] = {0,2,3,4,5};

printf("%ca \n",lights_up(3,&price[1],&stock[1]));

    return 0;
}