#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

bool comp(int a, int b) {

    string strA = to_string(a);
    string strB = to_string(b);
    string strAB= strA+strB;
    string strBA = strB+strA;
    
    int A=0,B=0;
    for(char elem : strAB){
        A=A*10+elem-'0';
    }
    for(char elem : strBA){
        B=B*10 + elem-'0';
    }
    if(A!=B)
        return A>B;
    else
        return false;
}
//more concise
/*bool comp(int a, int b) {
    string strA = to_string(a);
    string strB = to_string(b);
    string strAB= strA+strB;
    string strBA = strB+strA;
    
    if(strAB!=strBA)
        return strAB>strBA;
    else
        return false;
}
*/

string solution(vector<int> numbers) {
    string answer = "";
    bool isZero=true;
    sort(numbers.begin(), numbers.end(), comp);
    for (int elem : numbers) {
        if(elem!=0) isZero=false;
        answer += to_string(elem);
    }
    //다0일때 0000이따구로 뜸
    if(isZero) return "0";
    return answer;
}

