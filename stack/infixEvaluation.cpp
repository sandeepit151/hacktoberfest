#include<bits/stdc++.h>
using namespace std;
bool hasHigherPrecedence(char a,char b)
{
    map<char,int> oper;
    oper.insert({'+',1});
    oper.insert({'-',1});
    oper.insert({'*',2});
    oper.insert({'/',2});
    oper.insert({'(',0});
    if((oper.find(a)->second - oper.find(b)->second) >= 0)
    {
        return true;
    }
    else 
    {
        return false;
    }

}
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
    stack<int> operands;
    stack<char> operators;
    string exp = "9*4+5-2+6";
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]>='0' && exp[i]<='9')
        {
            operands.push(exp[i]-48);
        }
        else
        {
            if(operators.empty())
            {
                operators.push(exp[i]);
            }
            else if(hasHigherPrecedence(operators.top(),exp[i]))
            {
                int a = operands.top();
                operands.pop();
                int b = operands.top();
                operands.pop();
                operands.push(computeOper(b,a,operators.top()));
                operators.pop();
                operators.push(exp[i]); 
            }
            else if(!hasHigherPrecedence(operators.top(),exp[i]))
            {
                operators.push(exp[i]);
            }
        }
        cout<<operands.top()<<endl;
    }
    while(!operators.empty())
    {
        int a = operands.top();
        operands.pop();
        int b = operands.top();
        operands.pop();
        operands.push(computeOper(b,a,operators.top()));
        operators.pop();
    }
    cout<<operands.top();
}