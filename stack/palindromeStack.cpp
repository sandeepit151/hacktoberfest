#include<bits/stdc++.h>
using namespace std;
int main()
{
    string exp = "racecar";
    stack<char> s;
    for(int i=0;i<exp.length();i++)
    {
        s.push(exp[i]);
    }
    string newExp="";
    while(!s.empty())
       { newExp=newExp+s.top();
        s.pop();
       }
    

    if(exp==newExp)
        cout<<"Palindrome";
    else
    {
        cout<<"Not a palindrome";
    }
    
}