#include <stdio.h>
#include <stdbool.h>

bool isPrime(int x)
{
    if (x < 2)
    {
        return false;
    }

    int i;

    for (i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }

    return true;
}

void printBin(int x)
{
    int bitmask = 0x40000000;
    bool oneFound = false;
    while (bitmask > 0)
    {
        if (x & bitmask)
        {
            printf("1");
            oneFound = true;
        }
        else
        {
            if(oneFound){
                printf("0");
            }
        }
        bitmask = (bitmask >> 1);
    }

    if(!oneFound){
        printf("0");
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: %s <positive integer>", argv[0]);
        return 0;
    }

    int x;
    sscanf(argv[1], "%d", &x);

    printf("isPrime: %d\n", isPrime(x));
    printf("hex: 0x%x\n", x);

    printf("bin: 0b");
    printBin(x);
    puts("");

    return 0;
}

