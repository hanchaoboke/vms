//模拟售货机项目
#include <stdio.h>

int money;
char sale = '=';
//int choice;
//char *goods[] = {"Juice", "Cola", "Tea", "Water", "Coffee"};
char goodsnum[5] = {'A', 'B', 'C', 'D', 'E'};
int price[5] = {10, 6, 5, 8, 7};
int stock[5] = {5, 1, 2, 1, 9};
char lights_up[5] = {' ', ' ', ' ', ' ', ' '};
int pwd = 1110;
int income;

void mainPage()
{
    printf("*---------------------------*\n");
    printf("|     Vending   Machine     |\n");
    printf("*---------------------------*\n");
    printf("|   %c    %c    %c    %c    %c   |\n", goodsnum[0], goodsnum[1], goodsnum[2], goodsnum[3], goodsnum[4]);
    printf("|  ¥%d  ¥ %d  ¥ %d  ¥ %d  ¥ %d  |\n", price[0], price[1], price[2], price[3], price[4]);
    printf("|  [%c]  [%c]  [%c]  [%c]  [%c]  |\n", lights_up[0], lights_up[1], lights_up[2], lights_up[3], lights_up[4]);
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
int main()
{
    int choice;
    int choice2;
    int choice3;
    int choice4;
    int choice9;
    int choice9_3;
    int choice9_4;

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
            scanf("%d", &choice2);
            if (choice2 == 0)
            {
                printf("Going back!\n");
                break;
            }
            switch (choice2)
            {
            case 1:
                money = money + 1;
                printf("You have inserted ¥1.\n");
                break;
            case 2:
                money = money + 2;
                printf("You have inserted ¥2.\n");
                break;
            case 3:
                money = money + 5;
                printf("You have inserted ¥5.\n");
                break;
            case 4:
                money = money + 10;
                printf("You have inserted ¥10.\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
            }
            mainPage();
            /*if(stock <= 0){
    printf("X");
   }
      else if(money >= price){
    printf("O");
   }
   else{
    printf(" ");
   }*/

            break;

        case 3:
            printf("(3) Which product button would you like to press?\n");
            printf("1. A\n");
            printf("2. B\n");
            printf("3. C\n");
            printf("4. D\n");
            printf("5. E\n");
            printf("0. Go back\n\n");
            printf("Your choice:");
            scanf("%d", &choice3);
            if (choice3 == 0)
            {
                printf("Going back!\n");
                break;
            }
            switch (choice3)
            {
            case 1:
                money = money - price[0];
                sale = goodsnum[0];
                printf("You have pressed button A.\n");
                if (money < goodsnum[0])
                {
                    printf("invalid choice\n");
                }
                break;
            case 2:
                money = money - price[1];
                sale = goodsnum[1];
                printf("You have pressed button B.\n");
                if (money < goodsnum[1])
                {
                    printf("invalid choice\n");
                }
                break;
            case 3:
                money = money - price[2];
                sale = goodsnum[2];
                printf("You have pressed button C.\n");
                if (money < goodsnum[2])
                {
                    printf("invalid choice\n");
                }
                break;
            case 4:
                money = money - price[3];
                sale = goodsnum[3];
                printf("You have pressed button D.\n");
                if (money < goodsnum[3])
                {
                    printf("invalid choice\n");
                }
                break;
            case 5:
                money = money - price[4];
                sale = goodsnum[4];
                printf("You have pressed button E.\n");
                if (money < goodsnum[4])
                {
                    printf("invalid choice\n");
                }
                break;
            default:
                printf("Invalid choice!\n");
                break;
            }
            mainPage();
            break;
        case 4:
            printf("(4) Return button is pressed.\n");
            printf("¥%2d has been returned.\n", money);
            money = 0;
            mainPage();
            break;
        case 9:
            printf("(9) Opening service menu. Access code is required.\n");
            printf("Enter access code:");
            scanf("%d", &pwd);
            if (pwd != 1110)
            {
                printf("Incorrect code!\n");
            }
            else
            {
                printf("Correct code!\n");
                printf("(9) What would you like to do?\n");
                printf("1. Inspect machine status\n");
                printf("2. Withdraw all money\n");
                printf("3. Refill product\n");
                printf("4. Change product\n");
                printf("0. Go back\n\n");
                printf("Your choice:");
                scanf("%d", &choice9);
                if (choice9 == 0)
                {
                    printf("Going back!\n");
                    break;
                }
                switch (choice9)
                {
                case 1:
                    printf("(9-1)Machine status\n");
                    printf("Amount of revenue: ¥%d\n", income);
                    printf("Amount of inserted coins: ¥%d\n", money);
                    printf("A. Juice ($10) (%d left)\n", stock[0]);
                    printf("B. Cola ($6) (%d left)\n", stock[1]);
                    printf("C. Tea ($5) (%d left)\n", stock[2]);
                    printf("D. Water ($8) (%d left)\n", stock[3]);
                    printf("E. Coffee ($7) (%d left)\n", stock[4]);
                    break;
                case 2:
                    printf("(9-2)All money is being withdrawn\n");
                    printf("¥%d is withdrawn\n", income + money);
                    break;
                case 3:
                    printf("(9-3) Which product would you like to refill?\n");
                    printf("1. A\n");
                    printf("2. B\n");
                    printf("3. C\n");
                    printf("4. D\n");
                    printf("5. E\n");
                    printf("0. Go back\n");
                    printf("Your choice:\n");
                    scanf("%d", &choice9_3);
                    if (choice9_3 == 0)
                    {
                        break;
                    }
                    switch (choice9_3)
                    {
                    case 1:
                        printf("You have refilled product A to full.\n");
                        break;
                    case 2:
                        printf("You have refilled product B to full.\n");
                        break;
                    case 3:
                        printf("You have refilled product C to full.\n");
                        break;
                    case 4:
                        printf("You have refilled product D to full.\n");
                        break;
                    case 5:
                        printf("You have refilled product E to full.\n");
                        break;
                    default:
                        break;
                    }
                    break;
                case 4:
                    printf("(9-4) Which product would you like to change?\n");
                    printf("1. A\n");
                    printf("2. B\n");
                    printf("3. C\n");
                    printf("4. D\n");
                    printf("5. E\n");
                    printf("0. Go back\n");
                    printf("Your choice:\n");
                    scanf("%d", &choice9_4);
                    if (choice9_4 == 0)
                    {
                        break;
                    }
                    switch (choice9_4)
                    {
                    case 1:
                        printf("You are changing product A.\n");
                        break;
                    case 2:
                        printf("You are changing product B.\n");
                        break;
                    case 3:
                        printf("You are changing product C.\n");
                        break;
                    case 4:
                        printf("You are changing product D.\n");
                        break;
                    case 5:
                        printf("You are changing product E.\n");
                        break;
                    default:
                        break;
                    }
                default:
                    printf("Invalid choice!\n");
                    break;
                }
                mainPage();
            }

            break;
        case 0:
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}