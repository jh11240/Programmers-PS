#include <string>
#include <vector>
#include <set>
#include <iostream>
#include<algorithm>
#include<math.h>

using namespace std;
set<int> totalNumbers;

void BackTracking(string curNum,string numbers){
    if(curNum!="") 
        totalNumbers.insert(stoi(curNum));
    if(curNum.length() ==numbers.length()) return;
    string tmpNumbers=numbers;
    for(char elem : curNum){
        tmpNumbers.erase(find(tmpNumbers.begin(),tmpNumbers.end(),elem));
    }
    for(char elem : tmpNumbers){
        BackTracking(curNum+elem,numbers);
    }
}
//more concise way

// void DFS(string curNum, string numbers)
// {
//     if (curNum != "")
//         totalNumbers.insert(stoi(curNum));

//     for (int i = 0; i < numbers.size(); i++)
//         DFS(curNum + numbers[i], numbers.substr(0, i) + numbers.substr(i + 1));
// }

bool IsPrime(int num){
    if(num<2) return false;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int GetPrimeNumberAmount(){
    int Ret=0;
    for(auto num : totalNumbers){
        if(IsPrime(num)){
         cout<<num<<" ";   
        Ret++;
        }
    }
    return Ret;
}

int solution(string numbers) {
    int answer = 0;
    string curNum="";
    BackTracking(curNum,numbers);
    answer=GetPrimeNumberAmount();
    return answer;
}