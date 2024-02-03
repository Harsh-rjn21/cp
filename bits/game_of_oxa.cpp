/*
Monk and Mariam are playing the game of OXA. The game starts by Mariam writing an array A of N numbers on a sheet of paper. An OXA value can be calculated by choosing a subset of numbers from the set and applying the operations OR-XOR-ADD cyclically i.e. say the chosen numbers are 4, 6, 1, 5, 7 . . . . . , the OXA value of this subset will be = ( ( ( (4 OR 6 ) XOR 1 ) + 5) OR 7) XOR ... and so on, where OR, XOR stand for bitwise OR and XOR operations. The ordering of numbers in the subset will be retained from the main set.
The challenge for Monk is to observe the numbers carefully and predict the parity of the maximum OXA value possible from any chosen subset of numbers.

The Monk will predict the parity (whether the maximum OXA value is even or odd), in the form string S, which will either contain "Even" or "Odd" (without quotes). If the Monk prediction comes to be true, then he will win the game else Mariam will win the game.

You are given Monk's prediction and the array A, analyze the array and announce the winner of the Game of OXA !

Input:
The first line consists of an integer T. T testcases follow.
The first line of each testcase consists of a string S, Monk's prediction.
The second line of each testcase consists of an integer N.
In next N lines, each line will contain 1 integer denoting the elements of the array.

Output:
For each testcase, print the answer in a new line i.e. either "Monk" (without the quotes) or "Mariam" (without the quotes).

Constraints:
1<T<=10

S is either "Even" or "Odd", without the quotes
N <= 16
0 <= A[i] <= 10^5

Sample Input
2
Even
5
4
5
1
2
10
Odd
2
4
5
Sample Output
Mariam
Monk
Time Limit: 1
Memory Limit: 256
Source Limit:
Explanation
In the first testcase, the maximum OXA value is 17, (obtained from subset {4,5,2,10} i.e. ( (4 OR 5) XOR 2 ) + 10= 17). Monk predicted "Even" and hence, Mariam wins.
In the second testcase, the maximum OXA value is 5, (obtained from subset {5}). Monk predicted "Odd" and hence, Monk wins.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

deq entries;
unordered_set<int> possible_ans;

// | => 0
// ^ => 1
// + => 2

void find_all_possible(int index, int ans,int i){
    if(i >= entries.size()){
        possible_ans.insert(ans);
        return;
    }

    if(index == 0){
        int ans1 = ans | entries[i];
        find_all_possible((index+1)%3, ans1, i+1);
    }

    if(index == 1){
        int ans1 = ans ^ entries[i];
        find_all_possible((index+1)%3, ans1, i+1);
    }
    if(index == 2){
        int ans1 = ans + entries[i];
        find_all_possible((index+1)%3, ans1, i+1);
    }
    find_all_possible((index%3), ans, i+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;

  while(t--){ 
    string str;
    cin>>str;

    int a = str == "Odd" ? 1 : 0;

    int n;
    cin>>n;

    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        entries.push_back(x);
    }

    find_all_possible(0,0,0);

    int ans = *max_element(possible_ans.begin(), possible_ans.end());
    (ans & 1) == a ? cout<<"Monk\n" : cout<<"Mariam\n";
    }
    return 0;}