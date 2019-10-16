#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
#define max 10
int a[max];
int top1=-1;
int top2=max;
void push1(int data)
{
    if(top1==top2)
    {
        cout<<"Overflow";
    }
    else
    {
        top1++;
        a[top1]=data;
    }
}
void push2(int data)
{
    if(top1==top2)
    {
        cout<<"Overflow";
    }
    else
    {
        top2--;
        a[top2]=data;
    }
}
void pop1()
{
    if(top1==-1)
    {
        cout<<"Underflow";
    }
    else
    {
        top1--;
    }
}
void pop2()
{
    if(top2==max)
    {
        cout<<"Underflow";
    }
    else
    {
        top2++;
    }
}
int main()
{
    int i=1;
    int data;
    while(i!=0)
    {
        cin>>i;
        cin>>data;
        switch (i)
        {
            case 1:push1(data);
            break;
            case 3:pop1();
            break;
            case 3:push2(data);
            break;
            case 4:pop2();
            break;
            case 0:break;
        }
    }
}