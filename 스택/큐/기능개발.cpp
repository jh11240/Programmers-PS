#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int curLeftProgress=0,curWorkProgress=0,prevWorkProgress=0,curWorkDone=0;
    for(int i=0;i<progresses.size();i++){
        if(i!=0){
            curLeftProgress=100-progresses[i];
            curWorkProgress= ceil((float)curLeftProgress/speeds[i]);
            if(prevWorkProgress>=curWorkProgress){
                
                curWorkDone++;
            }
            else{
                answer.push_back(curWorkDone);
                prevWorkProgress=curWorkProgress;
                curWorkDone=1;
            }
        }
        else
        {
            curLeftProgress=100-progresses[i];
            prevWorkProgress= ceil((float)curLeftProgress/speeds[i]);
            curWorkDone=1;
        }
    }
    answer.push_back(curWorkDone);
    return answer;
}