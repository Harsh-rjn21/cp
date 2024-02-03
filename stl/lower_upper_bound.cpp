/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/

#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int e; cin>>e;

    int *begin = lower_bound(arr, arr+n,e);
    int *end = upper_bound(arr, arr+n,e);

    begin == end ? cout<<"[-1,-1]\n":cout<<"["<<begin-arr<<","<<end-arr-1<<"]\n";

    return 0;}