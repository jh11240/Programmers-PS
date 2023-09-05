#pragma region modified dijkstra algorithm
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include<algorithm>
using namespace std;

//시작섬, 도착섬 , 비용
vector<vector<pair<int,int>>> adj;
//비용, 섬
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int shortest[101];
bool visited[101];

void dijkstra(int startNode){
    pq.push({0,startNode});
    shortest[startNode]=0;
    
    pair<int,int> curNode;
    
    while(!pq.empty()){
        
        do
        {
            curNode=pq.top();
            pq.pop();
        } while(!pq.empty() && visited[curNode.second]);
        
        //모든 큐 다 방문하고 마지막 curNode가 방문된거면 그냥 종료
        if(visited[curNode.second]) return;
        visited[curNode.second]=true;
        
        for(auto elem : adj[curNode.second]){
            if(visited[elem.first]) continue;
            //각섬에 저장되어야하는 노드는 시작노드에서 시작해서 해당 노드로 갈때 
            //각섬에서 해당 섬으로 최소비용의 다리로만 갈수 있도록 해야함
            //이렇게 하기위해서 모든 섬은 다리중에서 최소비용으로 짓고, 방문을 한 섬은 다시 방문x
            if(shortest[elem.first] > elem.second)
            {
                shortest[elem.first]=elem.second;
                pq.push({ elem.second,elem.first });
            }
        }
        
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer=2'100'000'000;
    adj.resize(100);
    for(auto elem : costs){
        //양방향 그래프이다.
        adj[elem[0]].push_back({elem[1],elem[2]});
        adj[elem[1]].push_back({elem[0],elem[2]});
    }
    for(int i=0;i<n;i++){
        int tmpAnswer=0;
        fill(shortest,shortest+100,2'100'000'000);
        fill(visited,visited+100,false);
        dijkstra(i);
        for(int j=0;j<n;j++){
            if(!visited[i])continue;
            tmpAnswer+=shortest[j];
        }
        answer=min(answer,tmpAnswer);
    }
    return answer;
}
#pragma endregion

#pragma region Kruskals algorithm
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Union-Find 자료구조
class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = -1;
    }

    int find(int x) {
        if (-1 == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y)
            parent[x] = y;
    }
};

int solution(int n, vector<vector<int>> costs) {
    // 비용 순으로 정렬
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    UnionFind uf(n);
    int answer = 0;

    for (const auto& cost : costs) {
        int island1 = cost[0];
        int island2 = cost[1];
        int bridgeCost = cost[2];

        if (uf.find(island1) != uf.find(island2)) {
            uf.merge(island1, island2);
            answer += bridgeCost;
        }
    }

    return answer;
}
#pragma endregion