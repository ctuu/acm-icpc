#include <stdio.h>
#include <stdlib.h>
int main()
{
   // freopen("data1.txt","r",stdin);
    int cnt;
    scanf("%d",&cnt);

    int array[5] = {0};

    int i;
    int num,temp,temp1=1,cnt3=0,max = 0;
    int flag1 = 0, flag2 = 0, flag3= 0,flag4 = 0, flag5 = 0;
    for(i = 1; i <= cnt; i++){
        scanf("%d",&num);
        temp = num % 5;
        if(temp == 0 && num % 2 == 0)
            {flag1 = 1; array[0] += num;}
        if(temp == 1) {
            flag2 = 1;
            array[1] += ((temp1 % 2 != 0)? num:(-1*num));
            temp1++;
        }
        if( temp == 2){
            flag3 = 1;
            array[2]++;
        }
        if( temp == 3){
            flag4 = 1;
			printf("%d\n", num);
            cnt3++;
            array[3]+=num;
        }
        if( temp == 4){
            flag5 = 1;
            if(num > max) max = num;
        }
    }

    int h;
    if(flag1) printf("%d ",array[0]); else printf("%c ",'N');
    if(flag2) printf("%d ",array[1]); else printf("%c ",'N');
    if(flag3) printf("%d ",array[2]); else printf("%c ",'N');
    if(flag4) printf("%.1f ",1.0*array[3]/cnt3); else printf("%c ",'N');
    if(flag5) printf("%d",max);else printf("%c",'N');


    return 0;
}
