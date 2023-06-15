#pragma region using Backtracking
// #include <vector>
// #include <unordered_set>
// #include <map>
// using namespace std;
// void Search(map<string,int>::iterator cursor, map<string,int>::iterator end, int& answer,int combine,int tmp) {
//     if (cursor == end) {
//         answer += combine;
//         return;
//     }

//     //각 태그의 
//     combine *= (*cursor).second;
//     Search(++cursor, end, answer,combine,tmp);
//     --cursor;

//     combine /= (*cursor).second;
//     Search(++cursor, end, answer,combine,tmp);
//     --cursor;
// }
// //굳이 모든 종류의 배열을 알필욘없다. 태그들의 갯수로 가짓수를 구한후 거기에 각 태그의 옷수만큼 곱하기
// int solution(vector<vector<string>> clothes) {
//     int answer = 0;
//     //입었던 모든 종류를 직렬화해서 저장
//     unordered_set<string> wear;
//     unordered_set<string> kind;
//     map<string, int> clothType;
//     for (auto iter = clothes.begin(); iter != clothes.end(); ++iter) {
//         clothType[(*iter)[1]]++;
//     }
//     Search(clothType.begin(), clothType.end(),  answer,1,0);
//     //combine을 1로잡아서 아무 태그도 방문 안했을때도 1을 더해준다. 따라서 1빼줘야함
//     return answer-1;
// }
#pragma endregion

#pragma region using Mathmatical combination
#include <string>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;


int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> clothType;
    for (auto iter = clothes.begin(); iter != clothes.end(); ++iter) {
        clothType[(*iter)[1]]++;
    }
    for (auto iter = clothType.begin(); iter != clothType.end(); ++iter) {
        answer *= (1+( * iter).second);
    }
    return answer-1;
}
#pragma endregion