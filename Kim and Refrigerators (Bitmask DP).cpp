//https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/kim-and-refrigerators

// Bismillahir Rahmanir Rahim //
#include <iostream>
#include <math.h>
#include <deque>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <fstream>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <map>

using namespace std;
#define print(x) cout<<x<<endl;
#define  lli long long

int n, dp[12][10000];
pair<int, int> p[15];

int dis(int i, int j){
    return abs(p[i].first-p[j].first) + abs(p[i].second-p[j].second);
}

int str2Dec(string s){
    int res = 0;
    for(int i=s.size()-1, j=1; i>=0; i--, j*=2){
        if(s[i]=='1') res += j;
    }
    return res;
}

int getShortestPath(int prev, int cnt, string mask){
    if(cnt == 0){
        return dis(prev, 1);
    }
    int bitmask = str2Dec(mask);
    if(dp[prev][bitmask] != -1) return dp[prev][bitmask];
    int mini = INT_MAX;
    for(int i=2; i<n+2; i++){
        if(mask[i] == '0'){
            mask[i] = '1';
            mini = min(mini, dis(prev, i)+getShortestPath(i, cnt-1, mask));
            mask[i] = '0';
        }
    }
    return dp[prev][bitmask] = mini;
}

int main(){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //code starts
    
    int tc = 10;
    for(int t=1; t<=tc; t++){
        int x, y;
        cin >> n;
        cin >> x >> y;
        p[0] = {x, y};
        cin >> x >> y;
        p[1] = {x, y};
        for(int i=2; i<n+2; i++){
            cin >> x >> y;
            p[i] = {x, y};
        }
        memset(dp, -1, sizeof(dp));
        string mask(n+3, '0');
        print("# " << t << " " << getShortestPath(0, n, mask));
    }

    #ifndef ONLINE_JUDGE
        cerr<<endl;int z=30;while(z--){cerr<<'-';}cerr<<endl;cerr<<fixed<<setprecision(10)<<"**Time -> "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"fs"<<endl;
    #endif
    return 0;
}
