#pragma region first Implement
// #include <string>
// #include <vector>

// using namespace std;

// vector<int> solution(int brown, int yellow) {
//     vector<int> answer;
//     int width=0, height=0;
//     for(int i=1;i*i<=yellow;i++){
//         //yellow가 i로 안나눠떨어지면 continue해야함
//         if(yellow%i!=0) continue;
//         width=i;
//         height=yellow/i;
//         if(width*2 + height*2 + 4 == brown){
//             if(width>height){
//                 answer.push_back(width+2);
//                 answer.push_back(height+2);
//             }
//             else{
//                 answer.push_back(height+2);
//                 answer.push_back(width+2);
//             }
//             break;
//         }
        
//     }
//     return answer;
// }

#pragma endregion

#pragma region using quadratic formula
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int x, y;  
    x= 0.5*((2+brown/2)+sqrt((2+brown/2)*(2+brown/2)-4*brown-4*yellow));
    y=  0.5*brown-x+2;
    return {x,y};
}
#pragma endregion