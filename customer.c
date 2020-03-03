#include<stdio.h>
#include<stdlib.h>
#include"product.h"
#include"coin.h"
#include"customer.h"
#include"administrator.h"

// 调用product和coin

extern Product A, B, C, D, E;

extern Coin coin;

// 调用administrator

extern Administrator admin;

/*
商品代码,A,B,C,D,E
*/
char producCode;

/*
商品状态函数，可以购买亮O，无库存亮X
*/
char productStatus(Product product){
    char status;
    if (product.productNumber == 0)
    {
        return status = 'X';
    }
    if (product.productPrice == coin.conDeposit)
    {
       return  status = 'O';
    }
    if (product.productNumber > 0)
    {
        return status = ' ';
    }  
}



/*
完整的显示贩卖机页面
可以根据库存显示商品状态
无库存显示 X
投入硬币金额等于物品单价显示 O
*/
void customerPage(){
    puts("*---------------------------*");
    puts("|     Vending   Machine     |");
    puts("*---------------------------*");
    puts("|   A    B    C    D    E   |");
    printf("|  $%2d  $%2d  $%2d  $%2d  $%2d  |\n",A.productPrice, B.productPrice, C.productPrice, D.productPrice, E.productPrice);
    printf("|  [%c]  [%c]  [%c]  [%c]  [%c]  |\n",productStatus(A), productStatus(B), productStatus(C), productStatus(D));
    puts("*---------------------------*");
    printf("|                    [$%2d]  |\n",coin.conDeposit);
    puts("|                           |");
    printf("|           [=%c=]           |\n",producCode);
    puts("*---------------------------*");

}

/*
显示顾客看到的选项菜单
1. Read product information
2. Insert coin
3. Press product button
4. Press return button
9. Open service menu (code required)
0. Quit
*/
void choicePage(){
    puts("1. Read product information");
    puts("2. Insert coin");
    puts("3. Press product button");
    puts("4. Press return button");
    puts("9. Open service menu (code required)");
    puts("0. Quit");
}

/*
显示系统提前设定好的选项，接收选项对应的数字
1 void Readproductinformation();  查看商品信息
2 void InsertCoin();  投入硬币
3 void PressProductButton();  购买商品
4 void PressReturnButton();  退币
9 void OpenServiceMenu();  进入管理员选项（需要密码）
0 void Quit();  退出系统
*/
void choiceResultPage(int insertChoice){
    switch (insertChoice)
    {
    case 1:
        Readproductinformation();
        break;
    case 2:
        InsertCoin();
        break;
    case 3:
        PressProductButton();
        break;
    case 4:
        PressReturnButton(); 
        break;
    case 9:
        OpenServiceMenu();
        break;
    case 0:
        Quit();
        break;
    }
}

/*
商品信息展示，包括商品名称和商品价格
*/
void Readproductinformation(){
    puts("(1) The displayed products are:");
    printf("A. %s ($%d)\n",A.productName, A.productPrice);
    printf("B. %s ($%d)\n",B.productName, B.productPrice);
    printf("C. %s ($%d)\n",C.productName, C.productPrice);
    printf("D. %s ($%d)\n",D.productName, D.productPrice);
    printf("E. %s ($%d)\n",E.productName, E.productPrice);
    puts("\n");
}

/*
用户只能投入给定面值的硬币，贩卖机的商品状态，投币口金额会发生变化
*/
void InsertCoin()
{
    int InsertCoin = -1;
    while (InsertCoin != 0)
    {
        // 贩卖机页面
        customerPage();
        // 投入硬币页面
        puts("(2) Which coin would you like to insert?");
        puts("1. $1");
        puts("2. $2");
        puts("3. $5");
        puts("4. $10");
        puts("0. Go back\n");
        printf("Your choice:");
        scanf("%d", &InsertCoin);
        switch (InsertCoin)
        {
        case 1:
            coin.conDeposit += coin.coinValueOne;
            break;
        case 2:
            coin.conDeposit += coin.coinValueTwo;
            break;
        case 3:
            coin.conDeposit += coin.coinValueFive;
            break;
        case 4:
            coin.conDeposit += coin.coinValueTen;
            break;
        case 0:
            puts("Going back!");
            break;
        default:
            puts("insert wrong coin");
            break;
        }
    }
}

/*
购买商品的业务逻辑
*/
void outProduct(Product product,char code,char* producCode){
    product.productNumber -= 1;
    *producCode = code;
    coin.coinProfit += product.productPrice;
}
/*
用户输入商品代号，购买商品
*/
void PressProductButton(){
    int productButton;
    puts("(3) Which product button would you like to press?");
    puts("1. A");
    puts("2. B");
    puts("3. C");
    puts("4. D");
    puts("5. E");
    puts("0. Go back\n");
    printf("Your choice:"); scanf("%d",&productButton);
    switch (productButton)
    {
    case 1:
        puts("You have pressed button A.");
        outProduct(A,'A',&producCode);
        break;
    case 2:
        puts("You have pressed button B.");
        outProduct(B,'B',&producCode);
        break;
    case 3:
        puts("You have pressed button C.");
        outProduct(C,'C',&producCode);
        break;
    case 4:
        puts("You have pressed button D.");
        outProduct(D,'D',&producCode);
        break;
    case 5:
        puts("You have pressed button E.");
        outProduct(E,'E',&producCode);
        break;
    case 0:
        puts("Going back!");
        break;
    default:
        puts("wrong choice!");
        break;
    }
    
}

/*
用户退币
*/
void PressReturnButton(){
    coin.conDeposit = 0;
}

/*
进入管理员选项（需要密码）
*/
void OpenServiceMenu(){
    administratorPage();
}

/*
用户退出系统
*/
void Quit(){
    exit(0);
}