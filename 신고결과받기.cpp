#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size());
    //각 이용자마다 신고당한 횟수
    unordered_map<string, int> id_reported;
    //각 이용자가 신고한 사람들(set을 통해 중복 제거)
    unordered_map<string, unordered_set<string>> reportList;

    //map에 id마다 기본적으로 0으로 초기화
    for (auto iter = id_list.begin(); iter != id_list.end(); ++iter) {
        id_reported[*iter] = 0;
    }
    //report에 들어온 문자열 공백 기준으로 나눠서 reportList에 넣어주기
    for (auto iter = report.begin(); iter != report.end(); ++iter) {
        string tmp = "", reporter = "";
        //각 report의 char마다
        for (char elem : *iter) {
            //공백이 나올때까지 임시 string형 변수 tmp에 더해줌 
            if (elem != ' ') tmp += elem;
            //공백이면
            else {
                //지금 시점에서 tmp변수는 신고자이므로 reporter변수에 저장
                reporter = tmp;
                //tmp초기화하고 반복하면 tmp에 피신고자 저장됨
                tmp = "";
            }
        }
        //신고자가 자신이 아니면서, 신고자 set에 피신고자가 없을때만
        if (reporter != tmp && reportList[reporter].find(tmp) == reportList[reporter].end()) {
            //신고당한 횟수 ++
            id_reported[tmp]++;
            //신고자가 key인 map의 set value에 tmp값 insert해줌
            reportList[reporter].insert(tmp);
        }
    }
        //각 이용자마다 
        for (auto Iter = id_list.begin(); Iter != id_list.end(); ++Iter) {
            //해당 이용자에 key에 맞는 set value값 순회하며 
            for (auto setIter = reportList[*Iter].begin(); setIter != reportList[*Iter].end(); setIter++) {
                //각 set의 피신고자가 제제 먹었다면
                if (id_reported[*setIter] >= k) {
                    //answer벡터 +1해줌
                    answer[Iter - id_list.begin()] ++;
                }
            }
        }

    return answer;
}