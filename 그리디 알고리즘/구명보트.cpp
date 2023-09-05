#pragma region first Solved

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0,boatWeight=0;
    vector<int>:: iterator startIter=people.begin(),endIter=people.end()-1;
    sort(people.begin(),people.end());

    while(startIter<=endIter){
        //제일 무거운 친구 일단 태움
        boatWeight+=(*endIter);
        //제일 가벼운 친구 태워봄
        boatWeight+=(*startIter);
        
        //가벼운 친구 태웠을 때 무게가 총합 넘어가면
        if(limit<boatWeight || people.size()==1) {
            answer++;
            //무거운놈 한명 보냄
            endIter--;
            boatWeight=0;
            continue;
        }
        //둘다 보냄
        answer++;
        boatWeight=0;
        endIter--;
        startIter++;
    }
    return answer;
}
#pragma endregion

#pragma region more concise way
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0,peopleAmount=people.size();
    sort(people.begin(),people.end(),greater<int>());
    
    //매 반복문당 무거운녀석 한명씩 보냄
    for(int i=0,j=peopleAmount-1; i<=j;i++){
        //가벼운녀석과 무거운녀석을 더했을 때 limit안넘기면
        if(people[i]+people[j]<=limit){
            //가벼운녀석 보냄
            j--;
        }
        answer++;
    }
    return answer;
}

#pragma endregion