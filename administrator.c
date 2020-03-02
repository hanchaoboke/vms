#include<stdio.h>
#include"product.h"
#include"coin.h"
#include"administrator.h"

#define ADMINPASSWORD 1110

/*
初始化管理员结构体admin，默认密码为ADMINPASSWORD
*/
Administrator admin = {ADMINPASSWORD};


// 调用product和coin

Product A, B, C, D, E;
Coin coin;