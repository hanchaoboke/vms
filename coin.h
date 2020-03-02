#ifndef COIN_H
#define COIN_H
#include<stdio.h>
/*
Coin商品信息结构体
coinValueOne面值1元，coinValueTwo面值2元，coinValueFive面值1元，coinValueTen面值1元，coinProfit盈利金额，conDeposit投币口金额
初始化为coin
*/
typedef struct 
{
    int coinValueOne;
    int coinValueTwo;
    int coinValueFive;
    int coinValueTen;
    int coinProfit;
    int conDeposit;
}Coin;

#endif