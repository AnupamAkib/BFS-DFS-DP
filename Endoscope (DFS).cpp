
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
//bool isPalindrome(string s){for(int i=0, j=s.size()-1; i<s.size()/2; i++, j--){if(s[i]!=s[j]) return 0;}return 1;}
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

vector<int> pipeType(int n){
    vector<int> v;
    if(n==1) v = vector<int>({0, 1, 2, 3});
    if(n==2) v = vector<int>({2, 3});
    if(n==3) v = vector<int>({0, 1});
    if(n==4) v = vector<int>({0, 2});
    if(n==5) v = vector<int>({0, 3});
    if(n==6) v = vector<int>({1, 3});
    if(n==7) v = vector<int>({1, 2});
    return v;
}

int N, M, X, Y, L;
int a[52][52];
bool vis[52][52];

bool checkPipe(int prev_dir, int now){
    if(prev_dir == -1) return true;
    vector<int> nw = pipeType(now);
    if(prev_dir==0){
        for(auto p : nw){
            if(p==1) return true;
        }
    }
    if(prev_dir==1){
        for(auto p : nw){
            if(p==0) return true;
        }
    }
    if(prev_dir==2){
        for(auto p : nw){
            if(p==3) return true;
        }
    }
    if(prev_dir==3){
        for(auto p : nw){
            if(p==2) return true;
        }
    }
    return false;
}

void DFS(int dir, int x, int y, int level){
    if(x<0 or x==N or y<0 or y==M or level>L or !a[x][y]) return;
    if(!checkPipe(dir, a[x][y])) return;
    vector<int> p = pipeType(a[x][y]);
    vis[x][y] = true;
    for(auto d : p){
        int i = x+dx4[d], j = y+dy4[d];
        DFS(d, i, j, level+1);
    }
}

void solve(lli tc){
    cin >> N >> M >> X >> Y >> L;
    input2D(a, N, M);
    mem(vis, 0);
    DFS(-1, X, Y, 1);
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            ans += vis[i][j];
        }
    }
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
