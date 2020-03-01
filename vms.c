/*
自动售货机项目
*/
#include<stdio.h>
#include<string.h>

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
}Product;
// 商品初始化为A，B，C，D，E
Product A = {"Juice", 10, 5};
Product B = {"Cola", 6, 1};
Product C = {"Tea", 5, 2};
Product D = {"Water", 8, 1};
Product E = {"Coffee", 7, 9};

typedef struct 
{
    int conDeposit;
}Coin;

Coin coin;

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

void mainPage(){
    
}
int main(int argc, char const *argv[])
{
    
    //printf("%s %d %d",B.name,B.number,B.price);商品信息输出测试
    //printf("["); productStatus(A); printf("]"); 
    //productStatus(A,&status);

    int insertChoice;

    sacnf("%d",&insertChoice);
    
    printf("[%c]",productStatus(A)); 
    return 0;
}
