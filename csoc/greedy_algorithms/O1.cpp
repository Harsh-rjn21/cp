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

    int t;
    cin >> t;
    while(t--){
    bool ans = false;

    int n;
    cin >> n;

    deque<string> all;
    map<string,set<int>> hat;
    string a;

    for(int i = 0; i < n; i++){
        cin >>a;
        all.push_back(a);
        if(hat.count(a)){
            hat[a].insert(i);
        }
        else{
            set<int> sd;
            sd.insert(i);
            hat.insert({a,sd}); 
        }
        if(a.length()==1){ans=true;}
        if(a.length()==2 && a[0]==a[1])ans=true;
        if(a.length()==3 && a[0]==a[2]){
            ans = true;
        }
    }

    if(!ans){
        for(int i = 0; i < n; i++){
            if(ans)break;
                string y = "";
                string x = "";
                string h= "";
            if(all[i].length()==3){
                x.push_back(all[i][2]);
                x.push_back(all[i][1]);
                x.push_back(all[i][0]);
                y.push_back(all[i][1]);
                y.push_back(all[i][0]);
                h.push_back(all[i][2]);
                h.push_back(all[i][1]);
            }
            if(all[i].length()==2){
                x.push_back(all[i][1]);
                x.push_back(all[i][0]);
            }
            if((hat.count(x) && any_of(hat[x].begin(),hat[x].end(),[i,n](int a){return (a>i && a<n);}))){ans = true;break;}
            if((hat.count(y) && any_of(hat[y].begin(),hat[y].end(),[i,n](int a){return (a>i && a<n);}))){ans = true;break;}
            if((hat.count(h) && any_of(hat[h].begin(),hat[h].end(),[i,n](int a){return (a>=0 && a<i);}))){ans = true;break;}
        }
    }
    ans ? cout<<"YES\n":cout<<"NO\n";}

    return 0;}