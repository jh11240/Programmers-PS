#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
int leastMove=2'100'000'000;
bool visited[21];
using namespace std;

int AtoTarget(char target){
    int cnt=target-'A';
   
    if(cnt>=13){
      return 26-cnt;  
    } 
    else{ 
    return cnt;
    }
}
// prevCharIndex의 원소 다음 curCharIndex원소를 들림
void FindLocationWithLittleMove(string& origin,string& withoutA,string cur ,int prevCharIndex ,int curCharIndex, int curMoveCnt){
    if(origin[curCharIndex]=='A') return;
    
    int Move=21;
    //origin에서 prevChar에서 curChar으로 쭉 이동했을 때 거리
    Move= min(Move,abs(curCharIndex-prevCharIndex));
    //origin에서 마지막 문자로 향해서 돌아갈때의 거리
    if(prevCharIndex<curCharIndex){
        Move=min(Move,abs(prevCharIndex + (int)origin.length()-curCharIndex));
    }
    else if(curCharIndex<prevCharIndex){
        Move= min(Move,abs(curCharIndex + (int)origin.length()-prevCharIndex)); 
    }
    else 
        Move=0;
    Move+=AtoTarget(origin[curCharIndex]);
    visited[curCharIndex]=true;    
    curMoveCnt+=Move;
    cur+=origin[curCharIndex];
    //가지치기
    if(leastMove<curMoveCnt) return;
    if(cur.size()==withoutA.size()){
        leastMove=curMoveCnt;
        return;
    }
    for(int i=1;i<origin.length();i++){
        if(visited[i]) continue;
        FindLocationWithLittleMove(origin,withoutA,cur,curCharIndex,i,curMoveCnt);
        visited[i]=false;
    }
    
}

int solution(string name) {
    int answer = 0;
    string withoutA="";
    for(char elem : name){
        if(elem!='A')
        withoutA+=elem;
    }
    string start="";
    if(name[0]!='A')
     start+=name[0];
    //여기에 visited[i]=false를 안해주면 첫번째 방문한곳은 false되는 부분이 findloc함수내부에 없다
    for(int i=1;i<name.length();i++){
        visited[i]=true;   
        FindLocationWithLittleMove(name,withoutA,start,0,i,AtoTarget(name[0]));
        visited[i]=false;
    }
    //초기값이 나오면 첫글자만 있는 상태
    if(leastMove==2100000000) return name[0]-'A';
    return answer=leastMove;
}