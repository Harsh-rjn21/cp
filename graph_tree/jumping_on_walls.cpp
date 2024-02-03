/*
Jumping on Walls

Vasya plays a computer game with ninjas. At this stage Vasya's ninja should get out of a deep canyon.

The canyon consists of two vertical parallel walls, their height is n meters. Let's imagine that we split these walls into 1 meter-long areas and number them with positive integers from 1 to n from bottom to top. Some areas are safe and the ninja can climb them. Others are spiky and ninja can't be there. Let's call such areas dangerous.

Initially the ninja is on the lower area of the left wall. He can use each second to perform one of the following actions:

climb one area up;
climb one area down;
jump to the opposite wall. That gets the ninja to the area that is exactly k meters higher than the area he jumped from. More formally, if before the jump the ninja is located at area x of one wall, then after the jump he is located at area x + k of the other wall.
If at some point of time the ninja tries to get to an area with a number larger than n, then we can assume that the ninja got out of the canyon.

The canyon gets flooded and each second the water level raises one meter. Initially the water level is at the lower border of the first area. Ninja cannot be on the area covered by water. We can assume that the ninja and the water "move in turns" — first the ninja performs some action, then the water raises for one meter, then the ninja performs one more action and so on.

The level is considered completed if the ninja manages to get out of the canyon.

After several failed attempts Vasya started to doubt whether it is possible to complete the level at all. Help him answer the question.

Input
The first line contains two integers n and k (1 ≤ n, k ≤ 105) — the height of the canyon and the height of ninja's jump, correspondingly.

The second line contains the description of the left wall — a string with the length of n characters. The i-th character represents the state of the i-th wall area: character "X" represents a dangerous area and character "-" represents a safe area.

The third line describes the right wall in the same format.

It is guaranteed that the first area of the left wall is not dangerous.

Output
Print "YES" (without the quotes) if the ninja can get out from the canyon, otherwise, print "NO" (without the quotes).

Examples
inputCopy
7 3
---X--X
-X--XX-
outputCopy
YES
inputCopy
6 2
--X-X-
X--XX-
outputCopy
NO
Note
In the first sample the ninja should first jump to the right wall, then go one meter down along the right wall, then jump to the left wall. The next jump can get the ninja from the canyon.

In the second sample there's no way the ninja can get out of the canyon.
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define deq deque<int>
#define mii map<int,int>
#define pii pair<int,int>
int M = 1000000007;
using namespace std;

int n,k;
int side[2][100007];
int dp[2][100000][1000];

int depth_first_search(int s, int l, int level){
    if(l>n)return 1;
    if(side[s][l]==1 || level >= l)return 0;

    if(dp[s][l][level]!=-1)return dp[s][l][level];
   
    return (depth_first_search((s+1)%2,l+k,level+1) | depth_first_search(s,l+1,level+1) | depth_first_search(s,l-1,level+1));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp,-1,sizeof(dp));

    cin >> n >> k;

    for(int i = 0; i < 2; i++){
        for(int j = 1; j<=n; j++){
            char x;
            cin >> x;
            side[i][j] = ((x == '-') ? 0 : 1 );
        }
    }

   ( depth_first_search(0,1,0) == 1 )? cout << "YES\n" : cout << "NO\n";

    return 0;}