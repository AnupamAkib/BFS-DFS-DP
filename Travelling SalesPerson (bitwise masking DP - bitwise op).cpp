#include <iostream>
#include <limits.h> //for INT_MAX
#include <cstring> //for memset

using namespace std;

int n, m[13][13], allVisited;
int DP[12][4096];

int call(int node, int mask){
    if(mask == allVisited){
        return m[node][0];
    }
    if(DP[node][mask] != -1) return DP[node][mask];

    int ret = 1e9;

    for(int i=0; i<n; i++){
        if(!(mask & (1<<i)) && node!=i){ //(mask&(1<<i)) here () is important for bitwise
            ret = min(ret, m[node][i]+call(i, mask|(1<<i)) );
        }
    }
    
    return DP[node][mask]=ret;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCase = 0;
    cin >> testCase;
    while(testCase--){
        cin >> n;
        allVisited = (1 << n) - 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> m[i][j];
            }
        }

        memset(DP, -1, sizeof(DP));
        int ans = call(0, 1); // assuming 0 is visited, so mask is by default 1, that represents 000001 in binary
         
        cout << ans << endl;
    }

    return 0;
}
