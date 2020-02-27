#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(int argc, char const *argv[])
{
    int randNum[7];
    int n = 0;
    time_t ts;
    srand(time(&ts));
    for (int i = 0; i < 7; i++){
        n = rand() % 7;
        randNum[i] = n;
        for (int j = 0; j < i; j++){
            if (randNum[i] == randNum[j]){
                i--;
                break;
            }
        }
    }
    for (int i = 0; i < 7; i++){
        printf("%d ",randNum[i]);
    }
    putchar('\n');
    return 0;
}
