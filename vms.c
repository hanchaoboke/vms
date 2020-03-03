/*
自动贩卖机主函数
*/
#include<stdio.h>
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
    int insertChoice = -1;
    while (insertChoice != 1 ||insertChoice != 2 ||insertChoice != 3 ||insertChoice != 4 ||insertChoice != 9 ||insertChoice != 0)
    {
        choicePage();
        printf("Your choice:");  scanf("%d",&insertChoice);
        if (insertChoice != 1 ||insertChoice != 2 ||insertChoice != 3 ||insertChoice != 4 ||insertChoice != 9 ||insertChoice != 0)
        {
            printf("end of insertChoice is %d\n",insertChoice);
            puts("Invalid choice!\n");
        }
        else
        {
            choiceResultPage(insertChoice);
        } 
    }
    return 0;
}
