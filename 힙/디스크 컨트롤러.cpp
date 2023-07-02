#include <vector>
#include <queue>
#include <set>
#include <map>
#include<iostream>

using namespace std;


int solution(vector<vector<int>> jobs) {
    //답, 각 작업의 요청부터 종료까지 걸린 시간들의 합 , 각 작업이 끝났을때 총 시간,
    int answer = 0, sumOfRequestProcessTime = 0, curOffset = 0, jobsSize = jobs.size();


    //작업 들어온 목록 순서 first는 시작시간, second는 소요시간
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> diskWorkQueue;
    //first는 소요시간, second는 시작시간, value는 완료되었는지 안되었는지
    map<pair<int, int>, bool> timePriorityMap;


    //시작은 무조건 처음 들어온 요청을 처리해야한다. -> 최소값으로 안해도됨

    //순서대로 하기위해서 큐에 푸시
    for (int i = 0; i < jobsSize; ++i) {
        diskWorkQueue.push({ jobs[i][0], jobs[i][1] });
        timePriorityMap[{jobs[i][1], jobs[i][0]}] = false;
    }
    curOffset = diskWorkQueue.top().first + diskWorkQueue.top().second;
    sumOfRequestProcessTime = diskWorkQueue.top().second;
    timePriorityMap[{diskWorkQueue.top().second, diskWorkQueue.top().first}] = true;
    
    //시작시간~curOffset+소요시간 값을 우선순위 큐를 이용해 제일 작은 값찾기 -> 소요시간이 제일 짧은거로 가면 된다
    while (!diskWorkQueue.empty()) {
        bool didWork = false;
        //제일 먼저 요청한작업이 이미 완료된 작업이라면 pop연산
        if (timePriorityMap[{diskWorkQueue.top().second, diskWorkQueue.top().first}]) {
            diskWorkQueue.pop();
            continue;
        }
        for (auto iter = timePriorityMap.begin(); iter != timePriorityMap.end(); ++iter) {
            //이미 방문했다면
            if ((*iter).second) continue;
            //현재 curOffset보다 시작시간이 더 작은값이나올때까지 
            if ((*iter).first.second > curOffset) continue;

            didWork = true;
            curOffset += (*iter).first.first;
            sumOfRequestProcessTime += (curOffset - (*iter).first.second);
            (*iter).second = true;
            break;
        }

        //curOffset보다 작은 시작시간값이 없다면 하드가 쉬고있을 때다
        if (!didWork) {

            curOffset = diskWorkQueue.top().first + diskWorkQueue.top().second;
            sumOfRequestProcessTime += diskWorkQueue.top().second;
            timePriorityMap[{diskWorkQueue.top().second, diskWorkQueue.top().first}] = true;
            

            diskWorkQueue.pop();
        }
    }

    return answer = sumOfRequestProcessTime / jobsSize;
}