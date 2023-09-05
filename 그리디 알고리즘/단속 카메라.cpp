#pragma region original solved way

#include <string>
#include <vector>
#include <set>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    bool isCameraInRange=false;
    set<int> cameraSet;
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b){return a.back()<b.back();});
    for(auto elem : routes){
        isCameraInRange=false;
        for(auto setElem : cameraSet){
            //카메라가 현재 차량의 진입/진출지점 사이에 있다면 패스 
            //진출지점기준으로 정렬되었으므로 카메라보다 진출지점이 무조건 크다.
            //따라서 카메라 위치가 진출지점보다 뒤인지만 조사하면된다.
            if(setElem>= elem.front()){
                isCameraInRange=true;
                break;
            }
        }
        if(!isCameraInRange)
        cameraSet.insert(elem.back());
    }
    
    return answer=cameraSet.size();
}
#pragma endregion

#pragma region more concise way
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0, lastCamera= - 30'001;
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b){return a.back()<b.back();});
    for(auto elem : routes){
            //카메라가 현재 차량의 진입/진출지점 사이에 있다면 패스 
        if(lastCamera>= elem.front()) continue;
        lastCamera= elem.back();
        answer++;
    }
    
    return answer;
}
#pragma endregion