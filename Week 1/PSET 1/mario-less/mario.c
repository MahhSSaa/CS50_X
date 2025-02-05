#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int Hight;
    do
    {
        Hight = get_int("Hight:");
    }
    while (Hight < 1 || Hight > 8);

    for (int i = 0; i < Hight; i++)
    {
        for (int k = 0; k < Hight - (i + 1); k++)
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}