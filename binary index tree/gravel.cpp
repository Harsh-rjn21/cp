/*
    Bob has n heap(s) of gravel (initially there are exactly c piece(s) in each). He wants to do m operation(s) with that heaps, each maybe:

adding pieces of gravel onto the heaps from u to v, exactly k pieces for each,
or querying "how many pieces of gravel are there in the heap p now?".
Request
Help Bob do operations of the second type.

Input
The first line contains the integers n,m,c, respectively.
m following lines, each forms:
S u v k to describe an operation of the first type.
Q p to describe an operation of the second type.

(Each integer on a same line, or between the characters S, Q and the integers is separated by at least one space character)
Output
For each operation of the second type, output (on a single line) an integer answering to the respective query (follows the respective Input order).

Limitations
06
0
0
0≤c,k≤109
0
Sample 1:
Input

7 5 0
Q 7
S 1 7 1
Q 3
S 1 3 1
Q 3

Output
0
1
2

*/
//							  ੴ  ਵਾਹਿਗੁਰੂ 

#include<bits/stdc++.h>
#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define int long long
#define deq deque<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),c)
const ll M = 1000000007;
using namespace std;

void update(int &n, int &x){
    for(int i = n; i<=N;i+= (i & (-i))){
        fenwick[i]+=x;
    }
}

int sum(int &n){
    int ans = 0;
    for(int i = n; i>0;i-=(i&(-i))){
        ans+=fenwick[i];
    }
    return ans;
}

signed main(){

    int m,c;
    cin >> N >> m >> c;
    update(1,c);
    while(m--){
        char x;
        cin >> x;

        if(x=='Q'){
            int l;
            cin >> l;
            cout << sum(l)<< "\n";
        }
        else if(x=='S'){
            int l,r,k;
            cin >> l >> r >> k;
            update(l,k);
            update(r+1,(-k));
        }
    }

    return 0;}