#pragma region using set
// #include <string>
// #include <vector>
// #include <set>

// using namespace std;

// int solution(int n, vector<int> lost, vector<int> reserve) {
//     int answer = 0;
//     set<int> lostSet;
//     set<int> reserveSet;
//     for(auto iter=lost.begin(); iter!=lost.end();++iter){
//         lostSet.insert(*iter);
//     }
//     for(auto iter=reserve.begin();iter!=reserve.end();++iter){
//         reserveSet.insert(*iter);
//     }
//     //도난당한 체육복을 순회하며
//     for(auto iter = lostSet.begin();iter!=lostSet.end();){
//         //만약 도난당한 학생이 여벌 학생이라면, 여벌에서 해당 학생 삭제
//         if(reserveSet.find(*iter) != reserveSet.end()){
//             reserveSet.erase(reserveSet.find(*iter));
//             ++iter;
//             continue;
//         }
//         //+=1 차이의 번호의 여벌 학생이 존재하면 
//         if(reserveSet.find(*iter - 1) != reserveSet.end()){
//             reserveSet.erase(reserveSet.find(*iter - 1));
//             ++iter;
//             continue;
//         }
//         else if(reserveSet.find(*iter+1) != reserveSet.end()){
//             //+일때는 조심해야함
//             if(lostSet.find(*iter+1) != lostSet.end()){
//               ++iter;
//               n--;
//               continue;
//             } 
//             reserveSet.erase(reserveSet.find(*iter+1));
//             ++iter;
//             continue;
//         }
//         n--;
//         ++iter;
//     }
    
//     return answer=n;
// }
#pragma endregion

#pragma region using array
#include <string>
#include <vector>

using namespace std;
int student[35];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i : reserve) student[i] += 1;
    for(int i : lost) student[i] += -1;
    for(int i = 1; i <= n; i++) {
        if(student[i] == -1) {
            if(student[i-1] == 1) 
                student[i-1] = student[i] = 0;
            else if(student[i+1] == 1) 
                student[i] = student[i+1] = 0;
        }
    }
    for(int i  = 1; i <=n; i++)
        if(student[i] != -1) answer++;

    return answer;
}
#pragma endregion