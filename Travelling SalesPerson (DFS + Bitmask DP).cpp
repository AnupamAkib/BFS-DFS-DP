//https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/travelling-salesman-4/submissions/code/1345759332 (statement not accurate)
/*
////Problem statement: 
https://docs.google.com/document/d/1AjrdQzyzl9JDOQJTfUkdy1Lbj5jT5LS06Vk1Tq7pdLI/edit
////View this code for bitwise operations on Mask:
https://gist.github.com/lelouche556/d05095cadb25f0a0d267bf379ef71990
*/

/*BISMILLAHIR RAHMANIR RAHIM*/
#include<bits/stdc++.h>
#define lli long long int
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define ALL(x) x.begin(), x.end()
#define PI acos(-1.0)
#define nl cout<<"\n"
#define print(x) cout<<x<<endl;
#define mem(ar, val) memset(ar, val, sizeof(ar))
#define point(x) fixed<<setprecision(x)
#define printcase(n) cout << "Case " << tc << ": " << n <<endl;
#define printcaseii(n, m) cout << "Case " << tc << ": " << n << " " << m <<endl;
#define aInput(ar, n) for(int i=0; i<n; i++)cin>>ar[i];
#define vInput(v, n) for(int i=0; i<n; i++){lli xwq;cin>>xwq;v.push_back(xwq);}
#define input2D(ar, row, col) for(int i=0; i<row; i++){for(int j=0; j<col; j++){cin >> ar[i][j];}}
#define print2D(ar, row, col) for(int i=0; i<row; i++){for(int j=0; j<col; j++){cout << ar[i][j] << "\t";}cout<<endl;}
#define vprint(vec) for(int i=0; i<vec.size(); i++){cout << vec[i]; (i==vec.size()-1? cout<<endl : cout<<" ");}
#define aprint(ar, n) for(int i=0; i<n; i++){cout << ar[i] << " ";}cout<<endl
#define ANUPAM_AKIB ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define execution_time cerr<<endl;int z=30;while(z--){cerr<<'-';}cerr<<endl;cerr<<point(16)<<"**Time -> "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"fs"<<endl;
#define INPUT freopen("input.txt", "r", stdin)
#define OUTPUT freopen("output.txt", "w", stdout)
#define umap unordered_map
#define _IN input()
#define IN input()
#define yo(x) cout<<(#x)<<" = "<<(x)<<endl;
#define loop(n) for(int ctrx=0; ctrx<n; ctrx++)
#define ff first
#define ss second
#define VEC vector<lli>
#define sz size()
using namespace std;
const lli inf = 1e9+9;
const lli mod = 4294967296;
lli findLCM(lli a, lli b){return ((a*b)/__gcd(a,b));}
lli input(){lli x; cin >> x; return x;}
int digitCNT(lli n){int cnt = 0;while(n>0){cnt++;n/=10;}return cnt;}
string to_binary(lli num){if(num==0) return ""; return to_binary(num/2)+to_string(num%2);}
lli to_decimal(string s){lli r = 0, p = 1;for(int i=s.sz-1; i>=0; i--){if(s[i] == '1') r += p; p *= 2;}return r;}
bool isPalindrome(string s){for(int i=0, j=s.size()-1; i<s.size()/2; i++, j--){if(s[i]!=s[j]) return 0;}return 1;}
bool isPrime(lli n){if(n<2){return false;}if(n==2||n==3){return true;}if(n%2==0){return false;}for(lli i=3; i*i<=n; i+=2){if(n%i==0){return false;}}return true;}
//vertical & horizontal adjacent moves for 4 sides
// right, left, top, down
int dx4[] = {0, 0, -1, 1};
int dy4[] = {1, -1, 0, 0};
//adjacent moves for all 8 sides including diagonal moves
int dx8[] = {0, 1, 1, 0, -1, 1, -1, -1};
int dy8[] = {1, 0, 1, -1, 0, -1, 1, -1};
bool cmp(pair<lli, lli> a, pair<lli, lli> b){
    return a.ff>b.ff;
}

int n;
int cost[15][15], DP[5000][15]; // 2^12 = 4096, we took 5000 size
bool visited[15];

int getBitMask(){ //function to get bitmask integer value from 'visited' array
    int r=0;
    for(int i=n-1, p=1; i>=0; i--, p*=2){ //it actually converts 'visited' binary string to its integer value
        if(visited[i]) r += p;
    }
    return r;
}

int minimumAirfare(int u, int officeToVisit){
    if(officeToVisit == 1){ //now i have to return back to office 1 (which is 0 in my code)
        if(!cost[u][0]) return inf; //no path from city u to 0
        return cost[u][0]; //path from u to 0 found
    }
    int mask = getBitMask(); //get bitmask value
    if(DP[mask][u] != -1) return DP[mask][u]; //this state has already visited, return the answer
    int ret = inf;
    visited[u] = true;
    for(int i=0; i<n; i++){ //check all path from 'u'
        if(!visited[i] and cost[u][i]){//'i' path not visited and there are path between 'u' and 'i'
            ret = min(ret, cost[u][i]+minimumAirfare(i, officeToVisit-1));
        }
    }
    visited[u] = false;
    return DP[mask][u]=ret; //memorization and return
}

void solve(lli tc){
    cin >> n;
    input2D(cost, n, n);
    mem(visited, false);
    mem(DP, -1);
    int mnAirfare = minimumAirfare(0, n);
    printcase(mnAirfare);
}

int main(){
    ANUPAM_AKIB;
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        INPUT;
        OUTPUT;
    #endif

    lli tc = 1;
    
    cin >> tc; //TEST CASE

    for(int i=1; i<=tc; i++){
        solve(i);
    } //*/

    /*while(cin >> tc && tc!=0) solve(tc);  //EOF*/

    #ifndef ONLINE_JUDGE
        execution_time;
    #endif
    return EXIT_SUCCESS;
}
