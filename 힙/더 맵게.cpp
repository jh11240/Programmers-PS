#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0,newFood=0;
    priority_queue<int,vector<int>, greater<int>> q;
    for(int elem : scoville){
        q.push(elem);
    }
    while(!q.empty() && q.top()<K){
        if(q.size()==1) break;
        answer++;
        newFood=q.top();
        q.pop();
        newFood+=q.top()*2;
        q.pop();
        q.push(newFood);
    }
    //q가 비었다면
    if(q.empty()) 
        return answer;
    else if(q.top()<K)
        return -1;
    else
        return answer;
}