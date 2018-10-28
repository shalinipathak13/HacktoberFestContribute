#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str,reverse_string;
    int i;
    #take input from the user
    cin>>str;
    
    #stack is a type of container in C++
    stack<char> stk;
    
    #Push all the character of the Input String(str) into the stack(stk)
    for(i=0;i<str.length();i++)
        stk.push(str[i]);
        
    #store the string in reverse order
    while(!stk.empty())
    {
        reverse_string += stk.top();
        stk.pop();
    }
    
    #print the reverse string
    cout<<reverse_string;
    return 0;

}
