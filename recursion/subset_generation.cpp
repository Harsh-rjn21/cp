/*Problem : Subsets

Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

deque<set<int>> d;

vector<int> ans1;

void make_power_set(stack<int> s,set<int> ans){
    if(s.empty()){d.push_back(ans);return;}

    int x =s.top();
    s.pop();
    ans.insert(x);
    make_power_set(s,ans);

    ans.erase(x);
    make_power_set(s,ans);
}

void solve(stack<int> s){
    if(s.empty()){
        for(int i= 0;i < ans1.size(); i++){
            cout << ans1[i]<<" ";
        }
        cout << "\n";
        return;
    }
    int z = s.top();
    s.pop();
    solve(s);
    ans1.push_back(z);
    solve(s);
    ans1.pop_back();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<int> s;
    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        s.push(a);
    }

    set<int> ans;
    solve(s);
    // make_power_set(s,ans);

    // for(int i =0;i<d.size();i++){
    //     string k = "";
    //     k.push_back('{');
    //     for(auto j : d[i]){
    //         k.push_back((char)(j+'0'));
    //         k.push_back(',');
    //     }
    //     if(k[k.size()-1]==',')k.pop_back();
    //     k.push_back('}');
    //     cout<<k<<"\n";
    // }

    return 0;}