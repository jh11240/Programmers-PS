#include <string>
#include <vector>
#include<algorithm>
#include<math.h>
using namespace std;
vector<vector<int>> edges;

int DFS(bool* visited, int curNode){
    visited[curNode]=true;
    //현재 노드에 들어왔으니까 1로 시작
    int Sum=1;
    for(auto elem : edges[curNode]){
        if(visited[elem]) continue;
        Sum+=DFS(visited,elem);
    }
    return Sum;
}

int CutTree(int n, vector<vector<int>>& wires){
    bool visited[101];
    int firstNet=0,secondNet=0,ret=10000;
    for(auto elem : wires){
        fill(visited,visited+101,false);
        visited[(elem)[0]]=true;
        firstNet=DFS(visited,(elem)[1]);
        secondNet=n-firstNet;
        
        ret=min(ret,abs(firstNet-secondNet));
    }
    return ret;
}

//n이 100개 밖에 안되므로 다 하나씩 끊어봐서 갯수 세는 방식
int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    edges.resize(n+1);
    for(auto elem : wires){
        edges[(elem)[0]].push_back((elem)[1]);
        edges[(elem)[1]].push_back((elem)[0]);
    }
    answer=CutTree(n,wires);
    return answer;
}