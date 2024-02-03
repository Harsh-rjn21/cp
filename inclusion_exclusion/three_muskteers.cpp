/*
    Problem
Our Monk visits a neighbourhood school to teach kids, once a week. This week, they are studying the famous novel "The Three Musketeers" by Alexandre Dumas. As Monk is a fun teacher, he wants to enact a scene from the novel and hence, must choose 3 children from the class as the musketeers.
There are N children in his class. Monk is given the list of names of the students. Help Monk find the number of ways in which he can choose the musketeers, such that the names of the three children have atleast a vowel in common i.e. the names must have atleast one of ('a', 'e', 'i', 'o', 'u') in common. Two ways are considered different only if atleast one of the chosen student is different.

Input:
The first line consists of integer T. T testcases follow. The first line of each testcase consists of an integer N, denoting the number of children. It is followed by N lines, wherein each line is a string having only lowercase alphabets ('a'-'z') without spaces, denoting the names of children. A name can have a maximum length of 15 characters.

Output:
For each testcase, print the answer in a single line.

Constraints:
T<=20
N<=10^4

Sample Input
2
5
helen
irena
arthos
pentos
tulu
3
alen
bira
cult
Sample Output
1
0
Time Limit: 1
Memory Limit: 256
Source Limit:
Explanation
For the first test case, only 1 way is possible by choosing: helen, irena and pentos.
*/

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
int M = 1000000007;
using namespace std;

// a = 0
// e = 1
// i = 2
// o = 3
// u = 4
int hash_array[50];
set<int> bitmasks;
map<int,int> all_subsets;
deq bit_masks;

void generate_all_subsets(int bit_mask,int index,int ans){
    if(index>=5){if(ans!=0){all_subsets.insert({ans,0});}return;}
    int z = (1<<index);
    if((bit_mask&z)!=0){
        ans = (ans | z);
        generate_all_subsets(bit_mask,index+1,ans);
        ans = (ans & (~z));
        generate_all_subsets(bit_mask,index+1,ans);
    }
    else{generate_all_subsets(bit_mask,index+1,ans);}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<int, int> names;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;

        int bit_mask = 0;
        for (int j = 0; j < name.size(); j++)
        {
            if (name[j] == 'a')
               { bit_mask =bit_mask | 1;}
            if (name[j] == 'e')
                {bit_mask =bit_mask | 2;}
            if (name[j] == 'i')
                {bit_mask =bit_mask | 4;}
            if (name[j] == 'o')
                {bit_mask =bit_mask | 8;}
            if (name[j] == 'u')
                {bit_mask =bit_mask | 16;}
        }
        bitmasks.insert(bit_mask);
        bit_masks.push_back(bit_mask);
    }   

    for(auto i : bitmasks){
        generate_all_subsets(i,0,0);
    }
   
    for(auto i : all_subsets){
        for(auto j : bit_masks){
            if(((i.first) & j) == (i.first))all_subsets[i.first]++;
        }
    }

    int ans = 0;
    for(auto i : all_subsets){
        if(i.second<3){
            continue;
        }
        int k = i.second;
        int z = k*(k-1)*(k-2)/6;
        if((__builtin_popcount(i.first))%2!=0)ans+=z;
        else ans-=z;
    }

    cout<<ans;

    return 0;
}