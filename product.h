#ifndef PRODUCT_H
#define PRODUCT_H
#include<stdio.h>
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

#endif