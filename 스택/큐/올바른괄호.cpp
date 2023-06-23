#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> pStack;
    for(char elem : s){
        if(elem=='(') pStack.push(elem);
        else if(pStack.empty()) return false;
        else if(pStack.top()=='(') pStack.pop();
        else return false;
    }
    if(pStack.size()) return false;


    return answer;
}