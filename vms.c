/*
自动贩卖机主函数
*/
#include<stdio.h>
#include<string.h>
#include"product.h"
#include"coin.h"
#include"administrator.h"

// 调用product
Product A, B, C, D, E;

// 调用coin
Coin coin;

// 调用administrator
Administrator admin;

int main(int argc, char const *argv[])
{
    customerPage();
    int insertChoice = -1;
    while (insertChoice != 1 ||insertChoice != 2 ||insertChoice != 3 ||insertChoice != 4 ||insertChoice != 9 ||insertChoice != 0)
    {
        choicePage();
        printf("Your choice:");  scanf("%d",&insertChoice);
        if (insertChoice != 1 ||insertChoice != 2 ||insertChoice != 3 ||insertChoice != 4 ||insertChoice != 9 ||insertChoice != 0)
        {
            puts("Invalid choice!");
        }
        else
        {
            choiceResultPage(insertChoice);
        } 
    }
    return 0;
}
