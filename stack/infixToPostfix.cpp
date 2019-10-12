#include<bits/stdc++.h>
using namespace std;
bool isCharacter(char c)
{
    if(c>=65 && c<=90 )
        return true;
    else if(c<=122 && c>=97)
        return true;
    else if(c>=48 && c<=57)
        return true;

    return false;
}
bool isOperator(char c)
{
    if(c=='+'||c=='-'||c=='/'||c=='*')
        return true;
    
    return false;
}
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
int main()
{
    string exp = "A*B-(C+D)+E";
    stack<char> s;
    string postfix="";

    for(int i=0;i<exp.length();i++)
    {
        if(isCharacter(exp[i]))
            {
                postfix = postfix + exp[i];
            }
        else if(isOperator(exp[i]))
        {
            if(s.empty())
                {
                    s.push(exp[i]);
                }
            else if(hasHigherPrecedence(s.top(),exp[i]))
            {
                postfix = postfix + s.top();
                s.pop();
                s.push(exp[i]);
            }
            else if(!hasHigherPrecedence(s.top(),exp[i]))
            {
                s.push(exp[i]);
            }
        } 
        else if(exp[i]=='(')
        {
            s.push(exp[i]);
        }  
        else if(exp[i]==')')
        {
            
            while(s.top()!= '(')
            {
                postfix = postfix + s.top();
                s.pop();
            }
            s.pop();
        } 
    }
    while(!s.empty())
    {
        postfix = postfix + s.top();
        s.pop();
    }
    cout<<postfix;

}
