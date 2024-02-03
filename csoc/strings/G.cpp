#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

bool check_date(string b,int year){
    if(year==1 || year==3 || year==5 || year==7 || year==8 || year==10 || year==12){
        return (b>="01" && b<="31");
    }
    if(year==2){
        return (b>="01" && b<="28");
    }
    if(year==4 || year==6 || year==9 || year==11){
        return (b>="01" && b<="30");
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a;
    cin >> a;

    map<string,int> dates;

    int n = a.length();

    for(int i= 0;i<=(n-10);i++){
        bool check = false;
        if(!(a[i]=='-' || a[i+1]=='-') && a[i+5]=='-' && a[i+2]=='-' && a[i+6]=='2' && a[i+7]=='0' && a[i+8]=='1' && a[i+9]>='3' && a[i+9]<='5' && ((a[i+3]=='0' && a[i+4]>='1' && a[i+4]<='9') || (a[i+3]=='1' && a[i+4]>='0' && a[i+4]<='2'))){
            int year = 0;
            if(a[i+3]=='1')year+=10;
            year+=(a[i+4]-'0');
            string b = "";
            b.push_back(a[i]);
            b.push_back(a[i+1]);
            if(check_date(b,year)){
                check = true;
            }
        }

        if(check){
            string x = a.substr(i,10);
            dates[x]++;
        }
    }

    string ans = "";
    int count = 0;

    for(auto i: dates){
        if(count<i.second){
            count = i.second;
            ans = i.first;
        }
    }
    cout << ans;
    
    return 0;}