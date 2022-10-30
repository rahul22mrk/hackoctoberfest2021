#include<stdio.h>
#include<conio.h>
#define MAXSIZE 3
struct stack
{
    int aiData[MAXSIZE];
    int iTop;
};
void fnPush(struct stack*s,int iData)
{
    if(s->iTop==MAXSIZE-1)
    {
        printf("stack is overflow");
        return;
    }
    else{
        s->aiData[++s->iTop]=iData;
    }
}
void fnPop(struct stack *s)
{
    int iPopData;
    {
        if(s->iTop==-1)
        {
            printf("\n stack is underflow");
            return;
        }
    }
    iPopData=s->aiData[s->iTop--];
    return iPopData;
}
void fnDisplay(struct stack*s)
{
    int iIndex;
    if(s->iTop==-1)
    {
        printf("stack is underflow");
        return;
    }
    printf("\n stack elements are:");
    for(iIndex=s->iTop;iIndex>=0;iIndex--)
    {
        printf("\n %d",s->aiData[iIndex]);
    }
}
int main()
{
    struct stack s;
    int iVal,iChoice,iPopData;
    s.iTop=-1;
    clrscr();
    while(1){
        printf("\n 1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\n Enter your choice:");
        scanf("%d",&iChoice);
        switch(iChoice)
        {
            case 1:
            printf("Enter the no. to push");
            scanf("%d",&iVal);
            fnPush(&s,iVal);
            break;
            case 2:
            if(s.iTop!=-1)
            {
                iPopData=fnPop(&s);
                printf("\n Popped element %d",iPopData);
            }
            else{
                fnPop(&s);
            }
            break;
            case 3:
            fnDisplay(&s);
            break;
            case 4:
            exit();
            case 5:
            printf("Invalid input");
        }
    }
    return 0;
} 
