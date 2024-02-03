/*
My birthday is coming up and traditionally I'm serving pie. Not just one pie, no, I have a number N of them, of various tastes and of various sizes. F of my friends are coming to my party and each of them gets a piece of pie. This should be one piece of one pie, not several small pieces since that looks messy. This piece can be one whole pie though.

My friends are very annoying and if one of them gets a bigger piece than the others, they start complaining. Therefore all of them should get equally sized (but not necessarily equally shaped) pieces, even if this leads to some pie getting spoiled (which is better than spoiling the party). Of course, I want a piece of pie for myself too, and that piece should also be of the same size.

What is the largest possible piece size all of us can get? All the pies are cylindrical in shape and they all have the same height 1, but the radii of the pies can be different.

Input
One line with a positive integer: the number of test cases. Then for each test case:

One line with two integers N and F with 1 ≤ N, F ≤ 10000: the number of pies and the number of friends.
One line with N integers ri with 1 ≤ ri ≤ 10000: the radii of the pies.
Output
For each test case, output one line with the largest possible volume V such that me and my friends can all get a pie piece of size V. The answer should be given as a floating point number with an absolute error of at most 10-3.

Example
Input:
3
3 3
4 3 3
1 24
5
10 5
1 4 2 3 4 5 6 5 4 2

Output:
25.1327
3.1416
50.2655
*/

#include<bits/stdc++.h>
#define ll long long
#define deq deque<int>
ll mod = 1000000007;
using namespace std;

deq d;
int n,f;
double precision = 0.0001;

bool check(double x){
    int friends = f+1;

    int i = 0;
    double remain = 0;
    while(i<n){
        if(x<=d[i]){
            friends--;
            remain = d[i]-x;
            while(remain>=x){
                friends--;
                remain-=x;
            if(friends<=0)break;
            }
            remain = 0;
            if(friends<=0)break;
        }
        ++i;
    }
    return friends<=0;
}

double optimumRadiusSquare(){
    double low = 0, high = d[n-1];
    while(high - low > precision){
        double mid = (high+low)/2;
        if(check(mid)){low = mid;}
        else high = mid - precision;
    }

    if(check(high))return high;
    else return low;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>f;

    int x;
    for(int i = 0; i < n; i++){
        cin>>x;
        d.push_back(x*x);
    }
    sort(d.begin(), d.end());

    double ans = optimumRadiusSquare();
    cout<<setprecision(10)<<3.142*ans;
    return 0;}