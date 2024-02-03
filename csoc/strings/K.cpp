#include<bits/stdc++.h>
#include<string>
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

    string all[3];

    for(int i=0; i<3; i++){
        string a;
        cin >> a;
        for(int j = 0; j < a.length(); j++){
            if(a[j]==';' || a[j]=='-' || a[j]=='_')continue;
            all[i].push_back(tolower(a[j]));
        }
    }

    string possible[6];

    possible[0] += all[0];possible[0] += all[1]; possible[0] += all[2];
    possible[1] += all[0];possible[1] += all[2]; possible[1] += all[1];
    possible[2] += all[1];possible[2] += all[0]; possible[2] += all[2];
    possible[3] += all[1];possible[3] += all[2]; possible[3] += all[0];
    possible[4] += all[2];possible[4] += all[0]; possible[4] += all[1];
    possible[5] += all[2];possible[5] += all[1]; possible[5] += all[0];


    int t;
    cin >> t;

    while(t--){
        string a;
        cin >> a;

        string b = "";

        for(int j=0; j<a.length(); j++){
            if(a[j]==';' || a[j]=='-' || a[j]=='_')continue;
            b.push_back(tolower(a[j]));
        }

        bool ans = false;

        for(int i = 0; i<6;i++){
            if(possible[i]==b){
                ans=true;
                break;
            }
        }        
    
        ans ? cout<<"ACC\n":cout<<"WA\n";
    }

    return 0;}