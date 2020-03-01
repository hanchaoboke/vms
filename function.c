#include <stdio.h>
#include <string.h>

#define ADMINPASSWORD 1110
#define PRODUCTNUMBERMAX 10
/*
Product商品信息结构体
productName存储最多20个字符的商品名称,productPrice存储价格，productNumber存储商品库存
初始化为A，B，C，D，E
*/
typedef struct
{
    char productName[20];
    int productPrice;
    int productNumber;
} Product;
// 商品初始化为A，B，C，D，E
Product A = {"Juice", 10, 5};
Product B = {"Cola", 6, 1};
Product C = {"Tea", 5, 2};
Product D = {"Water", 8, 1};
Product E = {"Coffee", 7, 9};

typedef struct
{
    int coinValueOne;
    int coinValueTwo;
    int coinValueFive;
    int coinValueTen;
    int coinProfit;
    int conDeposit;
} Coin;

Coin coin = {1, 2, 5, 10, 0, 0};

typedef struct
{
    int adminLoginPassword;
} Administrator;

Administrator admin = {ADMINPASSWORD};

void adminChoicePage()
{
    puts("(9) What would you like to do?");
    puts("1. Inspect machine status");
    puts("2. Withdraw all money");
    puts("3. Refill product");
    puts("4. Change product");
    puts("0. Go back\n");
}
/*
显示系统提前设定好的选项，接收选项对应的数字
1 void InspectMachineStatus();  查看机器状态
2 void WithdrawAllMoney();  取出盈利的硬币
3 void RefillProduct();  补充商品库存
4 void ChangeProduct();  更新商品
0 void GoBack();  返回顾客主页
*/
void adminChoiceResultPage(int adminChoiceCode);

/*
查看机器状态
*/
void InspectMachineStatus(){
    puts("(9-1) Machine status");
    printf("Amount of revenue: $ %d",coin.coinProfit);
    printf("Amount of inserted coins: $ %d",coin.conDeposit);
    printf("A. %s ($ %d) ( %d left)",A.productName,A.productPrice,A.productNumber);
    printf("B. %s ($ %d) ( %d left)",B.productName,B.productPrice,B.productNumber);
    printf("C. %s ($ %d) ( %d left)",C.productName,C.productPrice,C.productNumber);
    printf("D. %s ($ %d) ( %d left)",D.productName,D.productPrice,D.productNumber);
    printf("E. %s ($ %d) ( %d left)",E.productName,E.productPrice,E.productNumber);
    puts("\n");
}

/*
取出盈利的硬币
*/
void WithdrawAllMoney(){
    coin.coinProfit = 0;
    coin.conDeposit = 0;
}
/*
moveProductNumber 商品库存修改函数
*/
void moveProductNumber(int productCode){
    switch (productCode)
    {
    case 1:
        A.productNumber = PRODUCTNUMBERMAX;
        puts("You have refilled product A to full.\n");
        break;
    case 2:
        B.productNumber = PRODUCTNUMBERMAX;
        puts("You have refilled product B to full.\n");
        break;
    case 3:
        C.productNumber = PRODUCTNUMBERMAX;
        puts("You have refilled product C to full.\n");
        break;
    case 4:
        D.productNumber = PRODUCTNUMBERMAX;
        puts("You have refilled product D to full.\n");
        break;
    case 5:
        E.productNumber = PRODUCTNUMBERMAX;
        puts("You have refilled product E to full.\n");
        break;
    }
}
/*
补充商品库存
*/
void RefillProduct(){
    int RefillProductCode;
    puts("(9-3) Which product would you like to refill?");
    puts("1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\n");
    printf("Your choice:"); scanf("%d",&RefillProductCode);
    moveProductNumber(RefillProductCode);
}
/*
商品添加函数
*/
void alterProduct(Product product, char productName[20], int productPrice){
    strcpy(product.productName,productName);
    product.productPrice = productPrice;
    product.productNumber = PRODUCTNUMBERMAX;
}
/*
更新商品
*/
void ChangeProduct(){
    int ChangProductCode;
    char ChangProductName[20];
    int ChangProductPrice;
    puts("(4-4) Which product would you like to change?");
    puts("1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\n");
    printf("Your choice:"); scanf("%d",&ChangProductCode);
    puts("You are changing product\n");
    printf("Enter new product name:");  scanf("%s",ChangProductName);
    printf("Enter new product price:"); scanf("%d",&ChangProductPrice);
    switch (ChangProductCode)
    {
    case 1:
        alterProduct(A,ChangProductName,ChangProductPrice);
        break;
    case 2:
        alterProduct(B,ChangProductName,ChangProductPrice);
        break;
    case 3:
        alterProduct(C,ChangProductName,ChangProductPrice);
        break;
    case 4:
        alterProduct(D,ChangProductName,ChangProductPrice);
        break;
    case 5:
        alterProduct(E,ChangProductName,ChangProductPrice);
        break;
    }
    puts("The new product has been filled to full.");


}
/*
返回顾客主页
*/
void GoBack(){
    
}

void administratorPage()
{
    int adminPassword;
    puts("(9) Opening service menu. Access code is required.");
    printf("Enter access code:");
    scanf("%d", &adminPassword);
    if (adminPassword == ADMINPASSWORD)
    {
        int adminChoiceCode = 1;
        puts("Correct code!\n");
        while (adminChoiceCode == 1 || adminChoiceCode == 2 || adminChoiceCode == 3 || adminChoiceCode == 4 || adminChoiceCode == 0)
        {
            adminChoicePage();
            printf("Your choice:");
            scanf("%d", &adminChoiceCode);
            adminChoiceResultPage(adminChoiceCode);
        }
    }
    else
    {
        puts("password is wrong");
    }
}

char producCode;

int main(int argc, char const *argv[])
{

    //printf("%s \n", productName);
    return 0;
}
