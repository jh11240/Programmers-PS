#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string target, const char moum[], int& answer, string word) {
    if (word == target)
            return true;
    if(word.length()==5)
        return false;;
    for (int i = 0; i < 5; i++) {
        string tmp = word+moum[i];
        answer++;
        bool ret = dfs(target,moum,answer, tmp);
        if(ret)
            return true;
    }
    return false;
}

int solution(string word) {
    int answer = 0;
    char moum[] = { 'A', 'E', 'I', 'O', 'U' };
    dfs(word, moum, answer, "");
    return answer;
}