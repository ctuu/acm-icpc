#include <stdio.h>
int array[5000+1];
int d[5000+1];
int m[5000+1];
int lds(int n)
{
    int max;
    int i, j;
    for(i=n-1; i>=0; --i)
    {
        for(j=i+1; j<n; ++j)
        {
            if(array[i] > array[j])
            {
                if(d[i] < d[j]+1)
                {
                    d[i] = d[j]+1;
                    m[i] = m[j];
                }
                else if(d[i] == d[j]+1)
                {
                    m[i] += m[j];
                }
            }
            else if(array[i] == array[j])
            {
                if(d[i] == 1)
                {
                    m[i] = 0;
                }
                break;//防止重复
            }
        }
    }
    for(i=0, max=0; i<n; ++i)
    {
        if(max < d[i])
        {
            max = d[i];
        }
    }
    int maxm;
    for(i=0, maxm=0; i<n; ++i)
    {
        if(d[i] == max)
        {
            maxm += m[i];
        }
    }
    printf("%d %d\n", max, maxm);
    return 0;
}
int main()
{
    int i=0;
    int nLastNum = -1;
    int nArrayLen;
    scanf("%d", &nArrayLen);
    i=0;
    while(i < nArrayLen)
    {
        scanf("%d", &array[i]);
        m[i] = 1;
        d[i] = 1;
        ++i;
    }
    while(i<5001)
    {
        m[i] = 1;
        d[i] = 1;
        ++i;
    }
    lds(nArrayLen);
    return 0;
}