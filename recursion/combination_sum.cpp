/*
Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.

Example 1:

Input:
N = 4
arr[] = {7,2,6,5}
B = 16
Output:
(2 2 2 2 2 2 2 2)
(2 2 2 2 2 6)
(2 2 2 5 5)
(2 2 5 7)
(2 2 6 6)
(2 7 7)
(5 5 6)
Example 2:

Input:
N = 11
arr[] = {6,5,7,1,8,2,9,9,7,7,9}
B = 6
Output:
(1 1 1 1 1 1)
(1 1 1 1 2)
(1 1 2 2)
(1 5)
(2 2 2)
(6)

Your Task:
Your task is to complete the function combinationSum() which takes the array A and a sum B as inputs and returns a list of list denoting the required combinations in the order specified in the problem description. The printing is done by the driver's code. If no set can be formed with the given set, then  "Empty" (without quotes) is printed.


Expected Time Complexity: O(X2 * 2N), where X is average of summation B/arri for every number in the array.
Expected Auxiliary Space: O(X * 2N)


Constraints:
1 <= N <= 30
1 <= A[i] <= 20
1 <= B <= 100
*/

#include<bits/stdc++.h>
#define ll long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

deque<deque<int>> answer;
int B;

void combination(deq d, deq ans,int sum){
    if(sum==B){sort(ans.begin(),ans.end());answer.push_back(ans);}
    if(sum>B)return;
    if(sum<B){for(int i=0;i<d.size();i++){
        if(d[i]>=ans[ans.size()-1] || ans.size()==0){ans.push_back(d[i]);
        combination(d, ans, sum+d[i]);
        ans.pop_back();}
    }}
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;

    unordered_set<int> s;

    for(int i = 0; i < N; i++){
        int x;
        cin>>x;
        s.insert(x);
    }

    deque<int> d;

    for(auto i : s){
        d.push_back(i);
    }

    deque<int> ans;

    cin>>B;

    combination(d,ans,0);

    sort(answer.begin(),answer.end());
    for(auto i : answer){
        for(int j = 0; j < i.size(); j++){
            cout<<i[j]<<" ";
        }
        cout<<"\n";
    }    

    return 0;}