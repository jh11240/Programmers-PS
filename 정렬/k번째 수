#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;

    for(auto elem : commands){
        tmp.clear();
        for(int i= elem[0];i<=elem[1];++i){
            tmp.push_back(array[i-1]);
        }
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[elem[2]-1]);

    }
    return answer;
}