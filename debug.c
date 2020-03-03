#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char productName[20];
    int productPrice;
    int productNumber;
}Product;
Product A = {"Juice", 10, 5};
/*
商品添加函数
*/
// void alterProduct(Product product, char productName[], int productPrice)
// {
//     //strcpy(product.productName, productName);
//     product.productNumber = productName;
//     product.productPrice = productPrice;
//     product.productNumber = 10;
// }

int main(){
    // char ChangProductName[20] = "";
    // int ChangProductPrice;

    // scanf("%s",ChangProductName);
    // scanf("%d",&ChangProductPrice);

    // alterProduct(A, ChangProductName, ChangProductPrice);

    // printf("%s\n%d\n",A.productName,A.productPrice);

    scanf("%s",A.productName);
    printf("%s",A.productName);

    return 0;
}