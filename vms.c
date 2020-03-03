/*
自动贩卖机主函数
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"product.h"
#include"coin.h"
#include"administrator.h"

// 调用product
extern Product A, B, C, D, E;

// 调用coin
extern Coin coin;

// 调用administrator
extern Administrator admin;

int main(int argc, char const *argv[])
{
    customerPage();
    int insertChoice;
    while(1){
        choicePage();
        printf("Your choice:");  scanf("%d",&insertChoice);
        if (insertChoice != 1 &&insertChoice != 2 &&insertChoice != 3 &&insertChoice != 4 &&insertChoice != 9 &&insertChoice != 0)
        {
            puts("Invalid choice!\n");
        }
        else
        {
            choiceResultPage(insertChoice);
        } 
        if(insertChoice == 0)
            exit(0);
    }
    return 0;
}
