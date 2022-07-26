//https://leetcode.com/problems/burst-balloons/
#include<bits/stdc++.h>
using namespace std;
#define execution_time cerr<<endl;int zaa=30;while(zaa--){cerr<<'-';}cerr<<endl;cerr<<fixed<<setprecision(10)<<"**Time -> "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"fs"<<endl;
#define print(xz) cout << xz << endl;
#define sz size()
#define lli long long

vector<int> v;
int dp[305][305];

class Solution {
public:

	int mx_coin(int left, int right){
		if(left+1 == right) return 0; //we added 1 in both start and end. So we are now working with 3 numbers
		if(dp[left][right] != -1) return dp[left][right];
	    int ret = 0;
	    for(int i=left+1; i<right; i++){
	    	int collected_coin = v[left] * v[i] * v[right];
	    	ret = max(ret, collected_coin + mx_coin(left, i) + mx_coin(i, right)); //check left subarray and right subarray
	    }
	    return dp[left][right]=ret;
	}

	int maxCoins(vector<int>& nums) {
	    v = nums;
	    v.insert(v.begin(), 1);
	    v.push_back(1);
	    memset(dp, -1, sizeof(dp));
	    return mx_coin(0, v.size()-1);
	}

};

int main(){
	clock_t tStart = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Solution problem;

	int n;
	cin >> n;
	vector<int> v;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		v.push_back(x);
	}

	int ans = problem.maxCoins(v);

	cout << ans;

	execution_time;
	return 0;
}
