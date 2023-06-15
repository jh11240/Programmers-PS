#include <string>
#include <vector>
#include<map>

using namespace std;
struct Genre {
    int totalPlayed=0;
    int mostPlayedAmount=0;
    int secondMostPlayedAmount=0;
    int mostPlayedNum=0;
    int secondMostPlayedNum=0;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
	map<string, Genre> MostPlayed;
	map<int, Genre, greater<int>> SortGenre;
    for (int i = 0; i < genres.size(); i++) {
        MostPlayed[genres[i]].totalPlayed += plays[i];
        if (MostPlayed[genres[i]].mostPlayedAmount < plays[i]) {
            //첫곡 갱신전에 바꿔줘야함
            MostPlayed[genres[i]].secondMostPlayedAmount = MostPlayed[genres[i]].mostPlayedAmount;
            MostPlayed[genres[i]].secondMostPlayedNum= MostPlayed[genres[i]].mostPlayedNum;
            MostPlayed[genres[i]].mostPlayedAmount = plays[i];
            MostPlayed[genres[i]].mostPlayedNum = i;
        }
        else if (MostPlayed[genres[i]].secondMostPlayedAmount<plays[i] && MostPlayed[genres[i]].mostPlayedAmount >= plays[i]) {
            MostPlayed[genres[i]].secondMostPlayedAmount = plays[i];
            MostPlayed[genres[i]].secondMostPlayedNum = i;
        }
    }
    for (auto iter = MostPlayed.begin(); iter != MostPlayed.end(); ++iter) {
        SortGenre[(*iter).second.totalPlayed] = (*iter).second;
    }
    for (auto iter = SortGenre.begin(); iter != SortGenre.end(); ++iter) {
        answer.push_back((*iter).second.mostPlayedNum);
        //한개일수도있음
        if((*iter).second.secondMostPlayedAmount!=0)
        answer.push_back((*iter).second.secondMostPlayedNum);
    }
    return answer;
}