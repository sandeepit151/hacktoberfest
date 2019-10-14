/*First pop all the elements of the stack till it becomes empty.
• For each upward step in recursion, insert the element at the bottom of the stack.*/
#include<bits/stdc++.h>
using namespace std;
stack<int> s;
void insertAtBottom(int data)
{
    if(s.empty())
    {
        s.push(data);
    }
    else
    {
        int temp = s.top();
        s.pop();
        insertAtBottom(data);
        s.push(temp);

    }
}
void reverse()
{
    if(s.empty())
    {
        return ;
    }
    else
    {
        int data = s.top();
        s.pop();
        reverse();
        insertAtBottom(data);
    }
    
}

int main()
{
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    reverse();
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}