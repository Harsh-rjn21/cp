/*
Problem
Read problems statements in Mandarin chinese, Russian and Vietnamese as well.
Minion Chef likes to eat bananas a lot. There are N piles of bananas in front of Chef; for each i (1 ≤ i ≤ N), the i-th pile contains Ai bananas.

Chef's mother wants her to eat the bananas and be healthy. She has gone to the office right now and will come back in H hours. Chef would like to make sure that she can finish eating all bananas by that time.

Suppose Chef has an eating speed of K bananas per hour. Each hour, she will choose some pile of bananas. If this pile contains at least K bananas, then she will eat K bananas from it. Otherwise, she will simply eat the whole pile (and won't eat any more bananas during this hour).

Chef likes to eat slowly, but still wants to finish eating all the bananas on time. Therefore, she would like to choose the minimum K such that she is able to eat all the bananas in H hours. Help Chef find that value of K.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and H denoting the number of piles and the number of hours after which Chef's mom will come home.
The second line contains N space-separated integers A1, A2, ..., AN.
Output
For each test case, print a single line containing one integer — the minimum possible value of K.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 105
N ≤ H ≤ 109
1 ≤ Ai ≤ 109 for each valid i
Subtasks
Subtask #1 (30 points):

1 ≤ N ≤ 100
Ai ≤ 103 for each valid i
Subtask #2 (70 points): original constraints

Sample 1:
Input
3
3 3
1 2 3
3 4
1 2 3
4 5
4 3 2 7
Output
3
2
4
Explanation:
Test case 11: Chef can choose K = 3K=3 bananas per hour. This way,

In the first hour, Chef eats the pile 11 as the number of bananas in the pile is less than equal to 33.
In the second hour, Chef eats the pile 22 as the number of bananas in the pile is less than equal to 33.
In the third hour, Chef eats the pile 33 as the number of bananas in the pile is less than equal to 33.
Chef can finish eating all the bananas in 33 hours. It can be shown that 33 bananas per hour is the minimum possible speed with which Chef can finish all bananas in 33 hours.

Test case 22: Chef can choose K = 2K=2 bananas per hour. This way,

In the first hour, Chef eats the pile 11 as the number of bananas in the pile is less than equal to 22.
In the second hour, Chef eats the pile 22 as the number of bananas in the pile is less than equal to 22.
In the third hour, Chef eats the 22 bananas from pile 33. 11 banana is left in pile 33.
In the fourth hour, Chef eats the remaining banana from pile 33 as the number of bananas in the pile is less than equal to 22.
Chef can finish eating all the bananas in 44 hours. It can be shown that 22 bananas per hour is the minimum possible speed with which Chef can finish all bananas in 44 hours.

Test case 33: Chef can choose K = 4K=4 bananas per hour. This way,

In the first hour, Chef eats the pile 11 as the number of bananas in the pile is less than equal to 44.
In the second hour, Chef eats the pile 22 as the number of bananas in the pile is less than equal to 44.
In the third hour, Chef eats the pile 33 as the number of bananas in the pile is less than equal to 44.
In the fourth hour, Chef eats the 44 bananas from pile 44. 33 bananas are left in pile 44.
In the fifth hour, Chef eats the remaining bananas from pile 44 as the number of bananas in the pile is less than equal to 44.
Chef can finish eating all the bananas in 55 hours. It can be shown that 44 bananas per hour is the minimum possible speed with which Chef can finish all bananas in 55 hours.

*/

#include<bits/stdc++.h>
#define ll long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

int n,H;
int arr[100];

bool can_eat(int k){
    int t = 0;

    for(int i = 0; i < n; i++){
        if(arr[i]<=k){++t;}
        else{
           t+= (arr[i]%k) == 0 ? arr[i]/k : (arr[i]/k)+1;
        }
    }

    return t<=H;

}

int optimum_rate(){
    int low = 1, high = accumulate(arr,arr+n,0);

    while(high - low > 1){
        int mid =(low+high)/2;
        if(can_eat(mid))high = mid;
        else low = mid+1;
    }

    if(can_eat(low))return low;
    else if(can_eat(high))return high;
    else return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    
    while(test--){cin>>n>>H;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int ans = optimum_rate();

    cout<<ans<<"\n";}

    return 0;}