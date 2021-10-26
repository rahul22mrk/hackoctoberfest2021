#include<stdio.h>
int main()
{
    long int T;
    int a, b, c, d;
    scanf("%ld",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if((a+c==180) && (d+b==180))  
        {
            printf("Yes\n");
        }
        else 
        {
            printf("No\n");
        }
    }
    return 0;
}
