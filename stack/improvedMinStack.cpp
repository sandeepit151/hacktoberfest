#include<bits/stdc++.h>
using namespace std;
stack<int> one,auxilary;
int main()
{
    int i=1;
    int ctr=0;
    while(i!=0)
    {   
        cout<<"Enter the operation you want to perform\n1)Push\n2)Pop\n3)Min ele\n0)Exit"<<endl;
        cin>>i;
        switch(i)
        {
            case 1:
            int ele;
            int min;
            ctr++;
            cout<<"Enter the element to be pushed into the stack"<<endl;
            cin>>ele;
            if(ctr==1)
                min=ele;
            one.push(ele);
            if(ele<min)
            {
                min=ele;
                auxilary.push(min);
            }
            break;
            case 2:
            cout<<"Popped element is "<<one.top()<<endl;
            one.pop();
            if(auxilary.top()==min)
            {
                auxilary.pop();
            }
            break;
            case 3:
            cout<<"Minimum element is "<<auxilary.top()<<endl;
            break;
            case 0:break;


        }
    }
}