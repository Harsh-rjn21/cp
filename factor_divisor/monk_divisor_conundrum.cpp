/*
Here is another task for you, prepared by Monk himself. So, this is how it goes :

Given an integer array A of size N, Monk needs you to answer T queries for him. In each query, he gives you 2 integers P and Q. In response to each of these queries, you need to tell Monk the count of numbers in array A. that are either divisible by P, Q, or both.

Input Format :
The first line contains a single integer N denoting the size of array A. The next line contains N space separated integers, where the  integer denotes .

The next line contains a single integer T denoting the number of queries Monk poses to you. Each of the next T lines contains 2 space separated integers P and Q.

Output Format :

For each query, print the answer on a new line.

Constraints :
N<=10^5
A[i]<=10^5
T<=10^5
P,Q<=10^5

Sample Input
6
2 3 5 7 4 9
2
4 5
3 7
Sample Output
2
3

Explanation
For the  query in the  sample, the numbers that form a part of the count are 4 and 5, present at indices 5 and 3 respectively.
*/

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
const int M = 200005;
using namespace std;

int hash_array[M + 1];
int multiple_count[M + 1];

void fill_multiples(int maxi)
{
    for (int i = 2; i <= maxi; i++)
    {
        for (int j = i; j <= maxi; j+=i)
        {
            if (hash_array[j] != 0)
                multiple_count[i]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        hash_array[arr[i]]++;
    }

    int maxi = *max_element(arr, arr + n);

    fill_multiples(maxi);

    int t;
    cin >> t;

    while (t--)
    {
        int p, q;
        cin >> p >> q;
        int ans = multiple_count[p] + multiple_count[q];
        ull lcm = p * q / __gcd(p, q);
        if (lcm <= maxi)
            ans -= multiple_count[lcm];
        cout << ans << "\n";
    }

    return 0;
}