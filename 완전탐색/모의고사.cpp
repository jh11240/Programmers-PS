#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int firstGaveUp[5]={1,2,3,4,5};
    int secondGaveUp[8]={2,1,2,3,2,4,2,5};
    int thirdGaveUp[10]={3,3,1,1,2,2,4,4,5,5};
    int firstManPoint=0,secondManPoint=0,thirdManPoint=0;
    for(int i=0;i<answers.size();i++){
        if(answers[i]==firstGaveUp[i%5]) firstManPoint++;
        if(answers[i]==secondGaveUp[i%8]) secondManPoint++;
        if(answers[i]==thirdGaveUp[i%10]) thirdManPoint++;
    }
    int maxPoint= max(firstManPoint,max(secondManPoint,thirdManPoint));
    if(maxPoint==firstManPoint) answer.push_back(1);
    if(maxPoint==secondManPoint) answer.push_back(2);
    if(maxPoint==thirdManPoint) answer.push_back(3);
    return answer;
}