#pragma region first one

#include <string>
#include <vector>
#include<iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    while(k>0){
        bool erased=false;
        for(int i=0;i<number.length()-1;i++){
            if(number[i]<number[i+1]){
                if(i==0) number= number.substr(1,number.length());
                else number=number.substr(0,i)+number.substr(i+1,number.length());
                erased=true;
                break;
            }
        }
        //내부가 내림차순으로 정렬되어있다면 마지막 숫자 제거
        if(!erased)
            number.erase(number.length()-1);
        k--;
    }
    return answer=number;
}

#pragma endregion

#pragma region second one
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int answersize = number.size() - k; // return값의 길이는 number의 사이즈에서 k를 뺀 것
    int startidx = 0; // 시작 index
    for(int i = 0; i < answersize; ++i){ // answersize만큼 반복
        char maxint = number[startidx]; // 처음에는 startidx의 값이 최대값
        int maxidx = startidx; // 처음에는 maxidx가 startidx
        for(int j = startidx; j <= k+i; j++){ // startidx부터 k+i까지 확인해서 max값 찾음 -k
            if(maxint < number[j]){ // 더 큰 값이 나오면 그 값의 index와 number를 저장
                maxint = number[j];
                maxidx = j;
            }
        }
        startidx = maxidx + 1; // 다음번에는 maxindex + 1에서부터 시작
        answer += maxint; // answer에 가장 큰 수를 넣는다
    }
    
    return answer;
}
#pragma endregion