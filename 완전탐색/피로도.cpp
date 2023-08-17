#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
bool visited[9];
int DFS(int curK, vector<vector<int>>& dungeons,int curDungeon, int level){
    //최소피로도 보다 현재 피로도가 더 작다면 현재 레벨 -1 리턴
    if(curK<dungeons[curDungeon][0]) return level-1;
    //레벨이 던전 크기라면 다 돌았음
    if(level==dungeons.size()) return dungeons.size();

    int ret=0;
    for(int i=0;i<dungeons.size();i++){
        if(visited[i]) continue;
        visited[i]=true;
        ret=max(ret,DFS(curK-dungeons[curDungeon][1],dungeons,i,level+1));
        visited[i]=false;
    }
    
    return ret;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    for(int i=0;i<dungeons.size();++i){
        if(visited[i]) continue;
        visited[i]=true;
        answer=max(answer,DFS(k,dungeons,i,1));
        visited[i]=false;
    }
    return answer;
}