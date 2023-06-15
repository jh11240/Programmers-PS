#include <string>
#include <vector>
#include <set>
#include<algorithm>
#include<iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), [](string a, string b) {
        return a.length() < b.length();
        });
    set<string> s;
    vector<string>::iterator iter = phone_book.begin();
    s.insert(*iter);
    for (++iter; iter != phone_book.end(); ++iter) {

        //현재 문자열의 모든 접두어 검색
        string tmp = "";
        for (char elem : *iter) {
            tmp += elem;
            if (s.find(tmp) != s.end()) {
                return false;
            }
        }
        s.insert(*iter);
    }
    return answer;
}