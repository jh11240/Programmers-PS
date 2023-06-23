#pragma region  using map
// #include <string>
// #include <vector>
// #include <map>
// #include<queue>
// #include<iostream>

// using namespace std;

// int solution(vector<int> priorities, int location) {
//     int answer = 1;
//     //key에 해당하는 우선순위가 몇개인지 저장하는 map
//     map<int, int, greater<int>> m;
//     //first는 우선순위, second는 원래 인덱스
//     queue<pair<int, int>> q;
//     for (int i = 0; i < priorities.size(); i++) {
//         m[priorities[i]]++;
//         q.push({ priorities[i],i });
//     }
//     while (!q.empty()) {
//         //제일큰 우선순위보다 현재 우선순위가 작으면 뒤로
//         if (q.front().first < (*m.begin()).first) {
//             q.push(q.front());
//             q.pop();
//         }
//         //제일큰 우선순위면 해당 우선순위 갯수 제거하고 map에서도 해당 우선순위 제거
//         else if (q.front().first == (*m.begin()).first) {
//             //location인덱스라면 탈출
//             if (q.front().second == location) {
//                 break;
//             }
//             //아니면 제거후, 우선순위의 갯수정보 업데이트
//             q.pop();
//             answer++;
//             if ((*m.begin()).second > 1) (*m.begin()).second--;
//             else m.erase(m.begin());
//         }

//     }
//     return answer;
// }
#pragma endregion

#pragma region  using priority_queue
#include <string>
#include <vector>
#include <map>
#include<queue>
#include<iostream>

using namespace std;
//정렬을 할 이유가 없음
int solution(vector<int> priorities, int location) {
    int answer = 1;
    priority_queue<int, vector<int>, less<int>> pq;
    //first는 우선순위, second는 원래 인덱스
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push({ priorities[i],i });
    }
    while (!q.empty()) {
        //제일큰 우선순위보다 현재 우선순위가 작으면 뒤로
        if (q.front().first < pq.top()) {
            q.push(q.front());
            q.pop();
        }
        //제일큰 우선순위면 해당 우선순위 갯수 제거하고 map에서도 해당 우선순위 제거
        else if (q.front().first == pq.top()) {
            //location인덱스라면 탈출
            if (q.front().second == location) {
                break;
            }
            //아니면 제거후, 우선순위의 갯수정보 업데이트
            pq.pop();
            q.pop();
            answer++;
        }

    }
    return answer;
}
#pragma endregion