#include <string>
#include <vector>
#include <set>

using namespace std;
set<int> allNums[9];

void MakeSet(int nAmount,int calNum){
   int tmp=0;
   for(int i=0;i<nAmount;i++){
       tmp = tmp*10+calNum;
   }
   
   allNums[nAmount].insert(tmp);
   allNums[nAmount].insert(-tmp);
   
   for(int i=1;i< nAmount;i++){
       //kAmount개의 숫자가 필요하므로 i번째 set과 kAmount-1번째 set을 조합해야함
       for(int A : allNums[i]){
           for(int B : allNums[nAmount-i]){
               if(i<=nAmount/2){
               allNums[nAmount].insert(A+B);
               allNums[nAmount].insert(A-B);
               allNums[nAmount].insert(A*B);
               }
               if(B) allNums[nAmount].insert(A/B);
           }
       }
   }

}

int solution(int N, int number) {
   for(int i=1;i<=8;i++){
       MakeSet(i,N);
   }
   int i=1;
   for(i;i<9 && allNums[i].find(number) == allNums[i].end();i++){ }
   if(i>8)
       return -1;
   else 
       return i;
}