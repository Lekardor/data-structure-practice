#include <stdio.h>
#include <stdlib.h>
#define Maxlenth 100
typedef int ElemType;

typedef struct list{
ElemType elem[Maxlenth];
int lenth;
}LIST;

int End(LIST L)
{
    return L.lenth;
}
//返回表中最后一个元素的位置
int MakeNull(LIST *L)
{
    int i;
    for(i=0;i<Maxlenth;i++)
    {
        (*L).elem[i]=0;
    }
    (*L).lenth=0;
    return End(*L);
}

void Insert(ElemType elem,int position,LIST *list)
{
    int i;
    ElemType temp;
    if((*list).lenth>=Maxlenth)
    {
        printf("list is full");
    }
    else if(position==(*list).lenth)
    {
        (*list).elem[position]=elem;
        (*list).lenth++;
    }
    else if(position>(*list).lenth||position<0)
    {
        printf("position does not exit");
    }
    else
    {
        for(i=(*list).lenth-1;i>=position;i--)
        {
            temp=(*list).elem[i];
            (*list).elem[i+1]=temp;
        }
        (*list).elem[position]=elem;
        (*list).lenth++;
    }

}
int main()
{
    LIST R;
    MakeNull(&R);
    Insert(2,0,&R);
    Insert(1,1,&R);
    Insert(3,0,&R);
    printf("%d %d %d",R.elem[0],R.elem[1],R.elem[2]);
    return 0;
}
