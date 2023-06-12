#pragma region using Set

// #include <vector>
// #include <set>
// using namespace std;

// int solution(vector<int> nums)
// {
//     int totalSize = nums.size();
//     set<int> s;
//     int answer = 0;
//     for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
//         s.insert(*iter);
//     }
//     answer = s.size()>totalSize/2 ? totalSize/2:s.size();
//     return answer;
// }
#pragma endregion

#pragma region using Unique(vector.begin(),vector.end())

// #include <vector>
// #include <algorithm>
// using namespace std;

// int solution(vector<int> nums)
// {
//     int totalSize = nums.size();
//     int answer = 0;
//     sort(nums.begin(),nums.end());
//     nums.erase(unique(nums.begin(), nums.end()),nums.end());
 
//     answer = nums.size() > totalSize / 2 ? totalSize / 2 : nums.size();
//     return answer;
// }
#pragma endregion

#pragma region using Unique() & Erase using iterator

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int totalSize = nums.size();
    int answer = 0;
    sort(nums.begin(), nums.end());
    auto iter = unique(nums.begin(), nums.end());
    for (auto it = iter; it != nums.end();) {
        it = nums.erase(it);
    }
    answer = nums.size() > totalSize / 2 ? totalSize / 2 : nums.size();
    return answer;
} 
#pragma endregion 