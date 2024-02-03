#include<bits/stdc++.h>
#define ll long long
ll mod = 1000000007;
using namespace std;

string modify(string& s, int n, int pos) {
	string start = s.substr(pos);
	string end = s.substr(0, pos);
	if (n % 2 != pos % 2)
		reverse(end.begin(), end.end());
	return start + end;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        set<char> alpha;
        deque<int> d(26,0);

        char l = s[0];
        for(int i = 0; i<n;i++){
            alpha.insert(s[i]);
            if(l>s[i]){
                l=s[i];
            }
        }

        if(alpha.size()==1){
            cout<<s<<"\n";
            cout<<"1\n";
        }
        else{
            deque<int> posis;
            for(int i = 0;i<s.length();i++){
                if(l==s[i]){posis.push_back(i);}
            }
            int ans = posis[0]+1;
            string answer = modify(s,n,posis[0]);

            for(int i = 1; i<posis.size();i++){
                string cji = modify(s,n,posis[i]);
                if(cji<answer){
                    ans = posis[i]+1;
                    answer=cji;
                }
            }

        cout<<answer<<"\n"<<ans<<"\n";
        }

    }
    return 0;}