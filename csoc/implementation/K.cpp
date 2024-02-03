#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

struct cmp{bool operator()(const pii &a, const pii &b) const{
    int lena = a.second - a.first + 1;
    int lenb = b.second - b.first + 1;
    if(lena == lenb) return a.first < b.first;
    return lena > lenb;
}
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n] = {0};

        set<pii,cmp> ans;
        ans.insert({0,n-1});


        for(int i = 1; i<=n; i++){
            auto x = *(ans.begin());
            int l = x.first;
            int r = x.second;
            ans.erase(x);

            int m;

            if((r-l) % 2 == 0){
                m = (r + l)/2;
                arr[m] = i;
            }
            else if((r-l) % 2 == 1){
                m = (r + l - 1)/2;
                arr[m] = i;
            }
                ans.insert({l,m-1});
                ans.insert({m+1,r});
                // sort(cmp.begin(),cmp.end(),[](pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){if(a.first == b.first){return a.second.first < b.second.first;}return a.first>b.first;});
        }
        for(int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;}