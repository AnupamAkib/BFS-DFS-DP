//https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/fisherman/problem
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
#define print2D(ar, row, col) for(int i=0; i<row; i++){for(int j=0; j<col; j++){cout << ar[i][j] << " ";}cout<<endl;}
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
int dx4[] = {0, 0, -1, 1};
int dy4[] = {1, -1, 0, 0};
//adjacent moves for all 8 sides including diagonal moves
int dx8[] = {0, 1, 1, 0, -1, 1, -1, -1};
int dy8[] = {1, 0, 1, -1, 0, -1, 1, -1};
bool cmp(pair<lli, lli> a, pair<lli, lli> b){
    return a.ff>b.ff;
}

int n, visited[15];
vector<pair<int, int> > fisherman;

int findLeft(int spot){ //find non occupied in left side
    if(spot == 0) return inf; //return a big value when all spot already occupied
    if(!visited[spot]) return spot;
    return findLeft(spot-1);
}

int findRight(int spot){ //find non occupied in right side
    if(spot > n) return inf; //return a big value when all spot already occupied
    if(!visited[spot]) return spot;
    return findRight(spot+1);
}

int entry(int pos, int fishermanRemaining){
    if(pos>=3) return 0; //when invalid position return 0
    if(!fishermanRemaining){ //no fisherman left in this gate
        if(pos+1==3) return 0; //if it was the last gate
        return entry(pos+1, fisherman[pos+1].ss); //if not last gate then check next gate
    }
    int mini = inf;
    int gate = fisherman[pos].ff; //get current opening gate position
    int left = findLeft(gate); //find left
    int right = findRight(gate); //find right
    int leftCost = abs(left-gate)+1; //get cost of occupying left spot
    int rightCost = abs(right-gate)+1; //get cost of occupying right spot

    //go nearest spot. If both side same then visit both side
    if(leftCost <= rightCost){
        visited[left] = 1;
        mini = min(mini, leftCost+entry(pos, fishermanRemaining-1));
        visited[left] = 0;
    }
    if(rightCost <= leftCost){
        visited[right] = 1;
        mini = min(mini, rightCost+entry(pos, fishermanRemaining-1));
        visited[right] = 0;
    }
    return mini;
}

void solve(lli tc){
    cin >> n;
    int fm[5], gate[5];
    aInput(gate, 3);
    aInput(fm, 3);
    for(int i=0; i<3; i++){
        fisherman.push_back({gate[i], fm[i]});
    }
    int ans = inf;
    //start from all possible combination of gate for minimum result
    do{
        ans = (min(ans, entry(0, fisherman[0].ss)));
    }
    while(next_permutation(ALL(fisherman)));
    print(ans)
}

int main(){
    ANUPAM_AKIB;
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        INPUT;
        OUTPUT;
    #endif

    lli tc = 1;

    //cin >> tc; //TEST CASE

    for(int i=1; i<=tc; i++){
        solve(i);
    } //*/

    /*while(cin >> tc && tc!=0) solve(tc);  //EOF*/

    #ifndef ONLINE_JUDGE
        execution_time;
    #endif
    return EXIT_SUCCESS;
}
