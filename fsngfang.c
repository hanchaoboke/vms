//模拟售货机项目
#include <stdio.h>

int money;
char sale = '=';
//int choice;
//char *goods[] = {"Juice", "Cola", "Tea", "Water", "Coffee"};
//char goodsnum[5] = {'A', 'B', 'C', 'D', 'E'};
int price[5] = {10, 6, 5, 8, 7};
int stock[5] = {5, 1, 2, 1, 9}; 

void mainPage();
void choicePage();
char productStatus(int stock,int price,int money);

void mainPage()
{
    printf("*---------------------------*\n");
    printf("|     Vending   Machine     |\n");
    printf("*---------------------------*\n");
    printf("|   A    B    C    D    E   |\n");
    printf("|  ¥10  ¥ 6  ¥ 5  ¥ 8  ¥ 7  |\n");
    printf("|  [ ]  [ ]  [ ]  [ ]  [ ]  |\n");
    printf("*---------------------------*\n");
    printf("|                    [¥%2d]  |\n", money);
    printf("|                           |\n");
    printf("|           [=%c=]           |\n", sale);
    printf("*---------------------------*\n");
}
void choicePage()
{
    printf("What would you like to do?\n");
    printf(" 1. Read product information\n");
    printf(" 2. Insert coin\n");
    printf(" 3. Press product button\n");
    printf(" 4. Press return button\n");
    printf(" 9. Open service menu (code required)\n");
    printf(" 0. Quit\n\n");
}
// 亮灯O，没库存 X ，否则 空格
char productStatus(int stock,int price,int money){
    char status;
    if(stock == 0){
    status = 'X';
   }else if(money >= price){
    status = 'O';
   }else{
    status = ' ';
   }
   return status;
}
int main()
{
    int choice;
 int choice2;

    mainPage();
    while (1)
    {
        choicePage();
        printf("Your choice:");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
        switch (choice)
        {
        case 1:
            printf("(1) The displayed products are:\n");
            printf("A. Juice (¥10)\n");
            printf("B. Cola (¥6)\n");
            printf("C. Tea (¥5)\n");
            printf("D. Water (¥8)\n");
            printf("E. Coffee (¥7)\n");
            break;
        case 2:
   printf("(2) Which coin would you like to insert?\n");
            printf("1. ¥1\n");
            printf("2. ¥2\n");
            printf("3. ¥5\n");
            printf("4. ¥10\n");
            printf("0. Go back\n\n");
   printf("Your choice:");
   scanf("%d",&choice2);
   if (choice2 == 0)
   {
    printf("Going back!\n");
    break;
   }
   switch (choice2)
   {
   case 1:money = money + 1;printf("You have inserted ¥1.\n");break;
   case 2:money = money + 2;printf("You have inserted ¥2.\n");break;
   case 3:money = money + 5;printf("You have inserted ¥5.\n");break;
   case 4:money = money + 10;printf("You have inserted ¥10.\n");break;
   default:printf("Invalid choice!\n");break;
   }
   mainPage();

//    if(stock <= 0){
//     printf("X");
//    }
//       else if(money >= price){
//     printf("O");
//    }
//    else{
//     printf(" ");
//    }

            break;





        case 3:
            break;
        case 4:
            break;
        case 9:
            break;
        case 0:
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}