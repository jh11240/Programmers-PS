#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> s;
    string answer = "";
    //completion의 선수들을 ++을 통해 s에 넣어준다.
    for (vector<string>::iterator iter = completion.begin(); iter != completion.end(); ++iter) {
        s[*iter]++;
    }
    for (vector<string>::iterator iter = participant.begin(); iter != participant.end(); ++iter) {
    	//s에 *iter key가 있는지 체크
        if (s.find(*iter) == s.end()) {
            answer = *iter;
            break;
        }
        //value값이 이미 다 감소된 상태라 0이라면 못 들어온거다.
        else if (s[*iter] == 0) {
            answer = *iter;
            break;
        }
        //찾았다면 value를 --를 해줘야한다,
        else {
            s[*iter]--;
        }
    }

    return answer;
}