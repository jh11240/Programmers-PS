#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool CanEnterWallet(int w, int h,int wMax,int hMax){
    //뒤집어서 들어갈 수만 있다면 true리턴
    if((w<= wMax && h<= hMax) || (w<=hMax && h<=wMax) ) return true;
    return false;
}


int solution(vector<vector<int>> sizes) {
    int answer = 0,wMax=0,hMax=0,tmpWidth=0,tmpWidth2=0;
    for(auto elemVec: sizes){
        if(CanEnterWallet(elemVec[0],elemVec[1],wMax,hMax)) continue;
        //지갑에 못들어간다면 눕히지 않았을때 명함과, 눕혔을 때 명함의크기를 비교
        tmpWidth= max(wMax,elemVec[0]) * max(hMax,elemVec[1]);
        tmpWidth2=max(wMax,elemVec[1]) * max(hMax,elemVec[0]);
        if(tmpWidth<tmpWidth2){
            wMax=max(wMax,elemVec[0]);
            hMax=max(hMax,elemVec[1]);
        }
        else{
            wMax=max(wMax,elemVec[1]);
            hMax=max(hMax,elemVec[0]);
        }
    }
    return answer=wMax*hMax;
}

/// more concise
/*
int solution(vector<vector<int>> sizes) {
    int answer = 0,wMax=0,hMax=0,tmpWidth=0,tmpWidth2=0;
    for(auto elemVec: sizes){
        wMax= max(wMax, max(elemVec[0],elemVec[1]));
        hMax= max(hMax, min(elemVec[0],elemVec[1]));
    }
    return answer=wMax*hMax;
}
*/