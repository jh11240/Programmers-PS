#include <string>
#include <vector>
#include<queue>
#include<set>
#include<iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> mulSet; 
    int inputNum=0;
    for(string elem : operations){
        switch(elem[0])
        {
            case 'I':
                inputNum=0;
                for(int i=2;i<elem.length();i++){
                    if(elem[i]=='-') {
                        continue;
                    }
                    inputNum=inputNum*10+ (elem[i] -'0');
                }
                if(elem[2]=='-'){
                     inputNum *= -1;
                }
                mulSet.insert(inputNum);

                break;
            case 'D':
                if(mulSet.empty()) break;
                if(elem.find("-") != string::npos){
                    mulSet.erase(mulSet.begin());
                }
                else{
                    mulSet.erase(--mulSet.end());
                }
                break;
        }
    }
    if(mulSet.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(*(--mulSet.end()));
        answer.push_back(*(mulSet.begin()));
    }
    
    return answer;
}