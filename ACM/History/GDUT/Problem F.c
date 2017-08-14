#include <stdio.h>
int main(void)
{
    int nu[26] = {0};
    char temp;
    while ((temp = getchar()) != '\n')
    {
        switch (temp)
        {
        case 'a':
            nu[0]++;
            break;
        case 'b':
            nu[1]++;
            break;
        case 'c':
            nu[2]++;
            break;
        case 'd':
            nu[3]++;
            break;
        case 'e':
            nu[4]++;
            break;
        case 'f':
            nu[5]++;
            break;
        case 'g':
            nu[6]++;
            break;
        case 'h':
            nu[7]++;
            break;
        case 'i':
            nu[8]++;
            break;
        case 'j':
            nu[9]++;
            break;
        case 'k':
            nu[10]++;
            break;
        case 'l':
            nu[11]++;
            break;
        case 'm':
            nu[12]++;
            break;
        case 'n':
            nu[13]++;
            break;
        case 'o':
            nu[14]++;
            break;
        case 'p':
            nu[15]++;
            break;
        case 'q':
            nu[16]++;
            break;
        case 'r':
            nu[17]++;
            break;
        case 's':
            nu[18]++;
            break;
        case 't':
            nu[19]++;
            break;
        case 'u':
            nu[20]++;
            break;
        case 'v':
            nu[21]++;
            break;
        case 'w':
            nu[22]++;
            break;
        case 'x':
            nu[23]++;
            break;
        case 'y':
            nu[24]++;
            break;
        case 'z':
            nu[25]++;
            break;
        }
    }
    int i;

    for (i = 0; i < 26; i++)
        printf("%d: %d\n", i, nu[i]);
}