/*
自动售货机项目
*/
#include<stdio.h>
#include<string.h>
/*
Product商品结构体
name存储最多20个字符的商品名称,price存储价格，number存储商品库存
初始化为A，B，C，D，E
*/
typedef struct
{
    char name[20];
    int price;
    int number;
}Product;
// 商品初始化为A，B，C，D，E
Product A = {"Juice", 10, 5};
Product B = {"Cola", 6, 1};
Product C = {"Tea", 5, 2};
Product D = {"Water", 8, 1};
Product E = {"Coffee", 7, 9};


int main(int argc, char const *argv[])
{
    
    //printf("%s %d %d",B.name,B.number,B.price);商品信息输出测试
    return 0;
}
