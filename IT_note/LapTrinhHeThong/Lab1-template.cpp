#include <stdio.h>
int bitAnd(int x, int y)
{
    x = ~(~x | ~y);
    return x;
}   

int negative(int x)
{
    x = ~x + 1;
    return x;
}

int getByte(int x, int n)
{
    n = ~n + 1;
    int t = (3+n) << 3;
    x = (x << t) >> (3 << 3);
    return x;
}

int setByte(int x, int n)
{
    int t = 255;
    t = t << (n << 3);
    return x | t;
}

int getnbit(int x, int n)
{

    int t = 1 << n;
    x = x & (t+ (~1+1)); 
    return x;
}

int isOpposite(int x, int y)
{

    return !(x+y); // Tổng 2 số đối nhau luôn bằng 0
}

int is16x(int x)
{
    int t = x & 15; // AND với 15 để lấy 4 bit cuối
    return !t;
} 

int isPositive(int x)
{
    return (x >> 31) + !!x; // ! 2 lần để ép kiểu sang bool
}

int isGE2n(int x, int n)
{
    n = 1 << n; // n lúc này = 2^n

    x = (x-n) >> 31;

    return !x;
}

int main()
{
    int score = 0;
    // 1.1
    printf("1.1 bitAnd");
    if (bitAnd(3, -9) == (3 & -9) && bitAnd(1, 8) == (1 & 8))
    {
        printf("\tPass.");
        score += 1;
    }
    else
        printf("\tFailed.");

    // 1.2
    printf("\n1.2 negative");
    if (negative(0) == 0 && negative(9) == -9 && negative(-5) == 5)
    {
        printf("\tPass.");
        score += 1;
    }
    else
        printf("\tFailed.");

    // 1.3
    printf("\n1.3 getByte");
    if (getByte(8, 0) == 8 && getByte(0x11223344, 1) == 0x33)
    {
        printf("\tPass.");
        score += 2;
    }
    else
        printf("\tFailed.");

    // 1.4
    printf("\n1.4 setByte");
    if (setByte(10, 0) == 255 && setByte(0, 1) == 65280 && setByte(0x5501, 2) == 0xFF5501)
    {
        printf("\tPass.");
        score += 2;
    }
    else
        printf("\tFailed.");

    // 1.5
    printf("\n1.5 getnbit");
    if (getnbit(15, 3) == 7 && getnbit(63, 6) == 63 && getnbit(30, 2) == 2)
    {
        if (getnbit(64, 32) == 64 && getnbit(-65000, 40) == -65000)
        {
            printf("\tAdvanced Pass.");
            score += 4;
        }
        else
        {
            printf("\tPass.");
            score += 3;
        }
    }
    else
        printf("\tFailed.");

    // 2.1
    printf("\n2.1 isOpposite");
    if (isOpposite(2, -2) == 1 && isOpposite(5, -1) == 0 && isOpposite(0, 16) == 0 && isOpposite(-4, 4) == 1)
    {
        printf("\tPass.");
        score += 2;
    }
    else
        printf("\tFailed.");

    // 2.2
    printf("\n2.2 is16x");
    if (is16x(16) == 1 && is16x(23) == 0 && is16x(0) == 1)
    {
        printf("\tPass.");
        score += 2;
    }
    else
        printf("\tFailed.");

    // 2.3
    printf("\n2.3 isPositive");
    if (isPositive(16) == 1 && isPositive(0) == 0 && isPositive(-8) == 0)
    {
        printf("\tPass.");
        score += 3;
    }
    else
        printf("\tFailed.");

    // 2.4
    printf("\n2.4 isGE2n");
    if (isGE2n(12, 4) == 0 && isGE2n(8, 3) == 1 && isGE2n(15, 2) == 1)
    {
        printf("\tPass.");
        score += 3;
    }
    else
        printf("\tFailed.");

    printf("\n------\nYour score: %.1f", (float)score / 2);
    return 0;
}