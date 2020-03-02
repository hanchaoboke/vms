#include<stdio.h>
#define ADMINPASSWORD 1110
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
int main(int argc, char const *argv[])
{
    administratorPage();
    return 0;
}
