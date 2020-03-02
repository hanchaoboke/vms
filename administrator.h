#include<stdio.h>
#include"product.h"
#include"coin.h"

/*
管理员结构体，初始化为admin
*/
typedef struct
{
    int adminLoginPassword;
} Administrator;

// 调用product和coin

Product A, B, C, D, E;
Coin coin;

/*
管理员界面
*/
void administratorPage();

/*
显示管理员看到的选项
(9) What would you like to do?
1. Inspect machine status
2. Withdraw all money
3. Refill product
4. Change product
0. Go back
*/
void adminChoicePage();

/*
显示系统提前设定好的选项，接收选项对应的数字
1 void InspectMachineStatus();  查看商品信息
2 void WithdrawAllMoney();  投入硬币
3 void RefillProduct();  购买商品
4 void ChangeProduct();  退币
0 void GoBack();  进入管理员选项（需要密码）
*/
void adminChoiceResultPage(int adminChoiceCode);

/*
查看机器状态
*/
void InspectMachineStatus();

/*
取出盈利的硬币
*/
void WithdrawAllMoney();

/*
moveProductNumber 商品库存修改函数
*/
void moveProductNumber(int productCode);

/*
补充商品库存
*/
void RefillProduct();

/*
商品添加函数
*/
void alterProduct(Product product, char productName[20], int productPrice);

/*
更新商品
*/
void ChangeProduct();

/*
返回顾客主页
*/
void GoBack();

/*
用户退出系统
*/
void Quit();