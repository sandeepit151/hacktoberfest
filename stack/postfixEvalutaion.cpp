#include<bits/stdc++.h>
using namespace std;
int computeOper(int a,int b,char c)
{
    if(c=='+')
    return a+b;
    else if(c=='-')
    return a-b;
    else if(c=='*')
    return a*b;
    else if(c=='/')
    return a/b;
}
int main()
{
    string exp = "23+5*7+";
    stack<int> s;
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]>='0' && exp[i]<='9')
        {
            s.push(exp[i]-48);
        }
        else
        {
            int a= s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(computeOper(a,b,exp[i]));
        }
    }
    if(!s.empty())
    cout<<s.top();
}