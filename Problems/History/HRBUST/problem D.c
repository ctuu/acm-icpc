#include <stdio.h>
typedef struct a
{
    int min;
    int p;
    double k;
} pair;

int main(void)
{
    int T, total, time, count, ct, temp, temp2;
    int mmins = 50000;
    int part[11];
    pair skill[100];
    pair tempair;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &total, &time, &count);

        for (temp2 = 0, ct = 0; ct < time; ct++)
        {
            scanf("%d", &temp);
            part[ct] = temp - temp2;
            temp2 = temp;
        }
        part[time] = total - temp;
       /* for (ct = 0; ct <= time; ct++)
            printf("%d ", part[ct]);*/
            //ok.
        for (ct = 0; ct < count; ct++)
        {
            
            scanf("%d%d", &skill[ct].min, &skill[ct].p);
            skill[ct].k = (double)skill[ct].p / skill[ct].min;
            mmins = (mmins < skill[ct].min) ? mmins : skill[ct].min;
            
        }

        //sort
        for (ct = 0; ct < count; ct++)
            for (temp = ct; temp < count; temp++)
            {
                if (skill[temp].k > skill[ct].k)
                {
                    tempair = skill[temp];
                    skill[temp] = skill[ct];
                    skill[ct] = tempair;
                }
            }
        /*
        for (ct = 0; ct < count; ct++)
            printf("%d / %d = %f\n", skill[ct].p, skill[ct].min, skill[ct].k);
        */
        total = 0;
        for (ct = 0; ct <= time; ct++)
        {
            while (part[ct] >= mmins)
            {
                for (temp = 0; temp < count; temp++)
                {
                    if (part[ct] >= skill[temp].min)
                    {
                        total += skill[temp].p;
                        part[ct] -= skill[temp].min;
                    }
                }
            }
        }
        printf("%d\n",total);
    }
    return 0;
}