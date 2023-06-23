#pragma region using variant 'curTime'
// #include <string>
// #include <vector>
// #include <stack>
// #include <set>
// #include<iostream>
// using namespace std;
// struct stock{
//     int index;
//     int price;
//     int enteredTime;
// };


// vector<int> solution(vector<int> prices) {
//     vector<int> answer;
//     stack<stock> tmpStack;
//     //first는 초기 인덱스, second는 스택에 올라있던 시간 
//     set<pair<int,int>> tmpSet;
//     int curTime=0;
    
//     for(int i=0;i<prices.size();i++){
//         //i와 curTime은 값이 동일하지만 나중에 이해하기 쉽게하기 위해 변수를 분리해둠
//         curTime++;
//         //스택의 top price값이 현재 price값보다 크면 
//         while(!tmpStack.empty()&& tmpStack.top().price>prices[i]){
//             tmpSet.insert({tmpStack.top().index, curTime-tmpStack.top().enteredTime});
//             tmpStack.pop();
//         }
//         tmpStack.push({i,prices[i],curTime});
//     }
//     //반복문이 끝났는데 스택이 차있다면
//     while(!tmpStack.empty()){
//         tmpSet.insert({tmpStack.top().index,curTime-tmpStack.top().enteredTime});
//         tmpStack.pop();
//     }
//     for(auto iter=tmpSet.begin();iter!=tmpSet.end();++iter){
//         answer.push_back((*iter).second);
//     }
//     return answer;
// }
#pragma endregion

#pragma region not using variant 'curTime'
#include <string>
#include <vector>
#include <stack>
#include <set>
#include<iostream>
using namespace std;


vector<int> solution(vector<int> prices) {
    vector<int> answer;
    //first는 초기인덱스 및 시간, second는 값
    stack<pair<int,int>> tmpStack;
    //first는 초기 인덱스, second는 스택에 올라있던 시간 
    set<pair<int,int>> tmpSet;
    
    for(int i=0;i<prices.size();i++){
        //스택의 top price값이 현재 price값보다 크면 
        while(!tmpStack.empty()&& tmpStack.top().second>prices[i]){
            tmpSet.insert({tmpStack.top().first, i-tmpStack.top().first});
            tmpStack.pop();
        }
        tmpStack.push({i,prices[i]});
    }
    //반복문이 끝났는데 스택이 차있다면
    while(!tmpStack.empty()){
        tmpSet.insert({tmpStack.top().first,prices.size()-1-tmpStack.top().first});
        tmpStack.pop();
    }
    for(auto iter=tmpSet.begin();iter!=tmpSet.end();++iter){
        answer.push_back((*iter).second);
    }
    return answer;
}

#pragma endregion