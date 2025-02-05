#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start;
    do
    {
        start = get_int("How many llamas do you have now?");
    }
    while (start < 9);

    int target;
    do
    {
        target = get_int("How many llamas do you want to have in the future?");
    }
    while (target < start);

    int years = 0;

    while (target >= start)
    {
        start = start + (start / 3) - (start / 4);
        years = years + 1;
    }

    printf("Years: %i\n", years);
}
