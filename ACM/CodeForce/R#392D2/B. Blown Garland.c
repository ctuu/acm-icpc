#include <stdio.h>
#include <string.h>
int main(void)
{
    _Bool isR, isB, isG, isY;
    int num, ct, temp;
    int kr, kb, ky, kg;
    char blub[100];
    int a, b, c, d;
    char A, B, C, D;
    kr = kb = ky = kg = 0;
    a = b = c = d = 0;
    scanf("%s", blub);
    num = strlen(blub);
    for (temp = 1, ct = 0; ct < num; ++ct, ++temp)
    {
        if (temp == 4)
        {
            if (blub[ct] != '!')
                D = blub[ct];
            else
                d += 1;
            temp = 0;
        }
        else if (temp == 3)

        {
            if (blub[ct] != '!')
                C = blub[ct];
            else
                c += 1;
        }
        else if (temp == 2)
        {
            if (blub[ct] != '!')
                B = blub[ct];
            else
                b += 1;
        }
        else if (temp == 1)
        {
            if (blub[ct] != '!')
                A = blub[ct];
            else
                a += 1;
        }
    }   
    if (D == 'R' || C == 'R' || B == 'R' || A == 'R')
        isR = 1;
    if (D == 'G' || C == 'G' || B == 'G' || A == 'G')
        isG = 1;
    if (D == 'Y' || C == 'Y' || B == 'Y' || A == 'Y')
        isY = 1;
    if (D == 'B' || C == 'B' || B == 'B' || A == 'B')
        isB = 1;

    if (strchr("RGBY", D) == NULL)
        if (!isR)
            D = 'R';
        else if (!isG)
            D = 'G';
        else if (!isR)
            D = 'B';
        else if (!isR)
            D = 'Y';

    if (strchr("RGBY", C) == NULL)
        if (!isR)
            C = 'R';
        else if (!isG)
            C = 'G';
        else if (!isR)
            C = 'B';
        else if (!isR)
            C = 'Y';

    if (strchr("RGBY", B) == NULL)
        if (!isR)
            B = 'R';
        else if (!isG)
            B = 'G';
        else if (!isR)
            B = 'B';
        else if (!isR)
            B = 'Y';

    if (strchr("RGBY", A) == NULL)
        if (!isR)
            A = 'R';
        else if (!isG)
            A = 'G';
        else if (!isR)
            A = 'B';
        else if (!isR)
            A = 'Y';

    if (D == 'R')
        kr = d;
    else if (D == 'G')
        kg = d;
    else if (D == 'Y')
        ky = d;
    else if (D == 'B')
        kb = d;

    if (C == 'R')
        kr = c;
    else if (C == 'G')
        kg = c;
    else if (C == 'Y')
        ky = c;
    else if (C == 'B')
        kb = c;

    if (B == 'R')
        kr = b;
    else if (B == 'G')
        kg = b;
    else if (B == 'Y')
        ky = b;
    else if (B == 'B')
        kb = b;

    if (A == 'R')
        kr = a;
    else if (A == 'G')
        kg = a;
    else if (A == 'Y')
        ky = a;
    else if (A == 'B')
        kb = a;
    printf("%d %d %d %d", kr, kb, ky, kg);
    return 0;
}