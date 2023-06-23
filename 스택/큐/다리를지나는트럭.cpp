#include <string>
#include <vector>
#include<queue>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    //first는 무게 second는 road체류시간
    queue<pair<int,int>> road;
    int curWeight=0,curTime=0;
    
    for(auto iter=truck_weights.begin();iter!= truck_weights.end();++iter){
        curTime++;
        //도로가 꽉찬 경우라면
        if(road.size()==bridge_length){
            //현재 시간을 맨앞차량이 나올예정인 시간으로 설정
            curTime=road.front().second;
            curWeight-=road.front().first;
            road.pop();
        }
        //도로의 무게가 꽉찬 경우라면
        if(curWeight+(*iter)> weight) {
            while(curWeight+(*iter) > weight ){
                //위와 동일하게 처리
                curTime=max(curTime,road.front().second);
                curWeight-=road.front().first;
                road.pop();
            }
        }
        curWeight+= (*iter);
        road.push({(*iter),curTime+bridge_length});
        
    }

    while(!road.empty()){
        curTime=max(curTime,road.front().second);
        road.pop();
    }
    return answer=curTime;
}