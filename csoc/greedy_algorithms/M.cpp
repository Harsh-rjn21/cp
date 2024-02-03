#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n >> k;

    string a;
    cin >> a ;
    string num = a;
    for(int i = 0; i < k; i++){
        for(int j = i; j < n; j+=k){
            a[j] = a[i];
        }
    }

    if(num>a){
        int index = k-1;
        while(a[index]=='9'){
            for(int i = index; i < n; i+=k){
                a[i]='0';
            }
            --index;
        }
        
        for(int i = index;i<n; i+=k){
            a[i]++;
        }
    }
    cout<<n<<"\n" << a;
    return 0;}