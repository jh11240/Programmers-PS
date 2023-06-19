#pragma region using queue
// #include <vector>
// #include <iostream>
// #include<queue>

// using namespace std;

// vector<int> solution(vector<int> arr) 
// {
//     vector<int> answer;
//     queue<int> q;
//     for(auto iter= arr.begin();iter!=arr.end();++iter){
//         q.push(*iter);
//     }
//     while(!q.empty()){
//         int curTop=q.front();
//         while(!q.empty()&&curTop==q.front()){
//             q.pop();
//         }
//         answer.push_back(curTop);
//     }
    
//     return answer;
// }

#pragma endregion

#pragma region using unique()function
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    answer=arr;
    return answer;
}
#pragma endregion

