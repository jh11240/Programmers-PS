#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),greater<int>());
    for(int i=citations.size()-1;i>=0;i--){
        //
        if(citations[i]<i+1) continue;
        answer=i+1;
        break;
    }
    return answer;
}