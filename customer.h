#include<stdio.h>
#include"product.h"
#include"coin.h"

// 调用product和coin

extern Product A, B, C, D, E;

/*
完整的显示贩卖机页面
可以根据库存显示商品状态
无库存显示 X
投入硬币金额等于物品单价显示 O
*/
void customerPage();

/*
商品状态函数，可以购买亮O，无库存亮X
*/
char productStatus(Product product);

/*
显示顾客看到的选项菜单
1. Read product information
2. Insert coin
3. Press product button
4. Press return button
9. Open service menu (code required)
0. Quit
*/
void choicePage();

/*
显示系统提前设定好的选项，接收选项对应的数字
1 void Readproductinformation();  查看商品信息
2 void InsertCoin();  投入硬币
3 void PressProductButton();  购买商品
4 void PressReturnButton();  退币
9 void OpenServiceMenu();  进入管理员选项（需要密码）
0 void Quit();  退出系统
*/
void choiceResultPage(int insertChoice);

/*
商品信息展示，包括商品名称和商品价格
*/
void Readproductinformation();

/*
用户只能投入给定面值的硬币，贩卖机的商品状态，投币口金额会发生变化
*/
void InsertCoin();

/*
购买商品的业务逻辑
*/
void outProduct(Product product,char code,char* producCode);

/*
用户输入商品代号，购买商品
*/
void PressProductButton();

/*
用户退币
*/
void PressReturnButton(){
    coin.conDeposit = 0;
}
