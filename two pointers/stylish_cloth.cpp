/*Gleb loves shopping. Once, he got the idea to choose a cap, a shirt, pants and shoes so that they look as stylish as possible. In Gleb's understanding clothes are more stylish when the difference in color of the elements of his clothes is small.

There are n1 caps, n2 shirts, n3 pants and n4 shoes (1 ≤ ni ≤ 100, 000). Each clothes element has its color (an integer from 1 to 100, 000). A set of clothes is one cap, shirt, pants and one pair of boots. Each set is characterized by the maximum difference between any two of its elements. Help Gleb to choose the most stylish set, that is the set with the minimum color difference.

Input
For each clothes element i (i = 1, 2, 3, 4) given its count ni, and ni integers in next line which is their color. First clothes element in input is caps, second is shirts, third is pants and forth is shoes. All numbers in input are positive integers not bigger than 100, 000.

Output
Write 4 integers in output, color of cap, shirt, pants and shoes Gleb will choose. If there are several most stylish sets output any of them.

Examples
inputCopy
3
1 2 3
2
1 3
2
3 4
2
2 3
outputCopy
3 3 3 3
inputCopy
1
5
4
3 6 7 10
4
18 3 9 11
1
20
outputCopy
5 6 9 20*/

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

int power(int a, int b, int mod){
    int ans = 1;
    while (b > 0){
        if (b & 1){ans = (ans%mod * 1LL * a%mod) % mod;}
        a = (a%mod * 1LL * a%mod) % mod;
        b >>= 1;}
    return ans%mod;}

ll modInverse(ll n,ll mod){
    return power(n,mod-2,mod)%mod;}

int mini(int a0, int a1, int a2, int a3){
    if(a0<=a1 && a0<=a2 && a0<=a3){
        return 0;
    }
    else if(a1<=a2 && a1<=a3 && a1<=a0){
        return 1;
    }
    else if(a2<=a1 && a2<=a3 && a2<=a0){
        return 2;
    }
    else if(a3<=a1 && a3<=a2 && a3<=a0){
        return 3;
    }
}

int maxi(int a0, int a1, int a2, int a3){
    if(a0>=a1 && a0>=a2 && a0>=a3){
        return 0;
    }
    else if(a1>=a2 && a1>=a3 && a1>=a0){
        return 1;
    }
    else if(a2>=a1 && a2>=a3 && a2>=a0){
        return 2;
    }
    else if(a3>=a1 && a3>=a2 && a3>=a0){
        return 3;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(20);

    int n[4];
    deq styles[4];

    rp(i,0,4){
        cin>>n[i];
        rp(j,0,n[i]){
            int x;
            cin >> x;
            styles[i].push_back(x);
        }
        sort(styles[i].begin(),styles[i].end());
    }

    int ansvalue = INT_MAX,ans[4]={0};
    int i[4] = {0};
    while(true){
        int x = mini(styles[0][i[0]],styles[1][i[1]],styles[2][i[2]],styles[3][i[3]]);
        int y = maxi(styles[0][i[0]],styles[1][i[1]],styles[2][i[2]],styles[3][i[3]]);
        // ans = min(ans,(styles[y][i[y]]-styles[x][i[x]]));
        if((styles[y][i[y]]-styles[x][i[x]])<ansvalue){
            ansvalue = styles[y][i[y]]-styles[x][i[x]];
            rp(j,0,4)ans[j]=styles[j][i[j]];
        }
        if(i[x]==(n[x]-1))break;
        i[x]++;
    }

    // cout << ans << "\n" ;

    rp(j,0,4)cout << ans[j] << " ";

    return 0;}