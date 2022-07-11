//https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/warmholes/problem
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

typedef struct{
    int x, y;
} coor;

int distance(coor a, coor b){
    int x1 = a.x, y1 = a.y, x2 = b.x, y2 = b.y;
    return abs(x1-x2) + abs(y1-y2);
}

int n, wh_cost[12];
coor from, to;
pair<coor, coor> wormhole[12];
bool vis[1000][1000];

int findMinimumCost(coor p, int pos, int d, int prev){
    if(pos==n) return inf; //out of bound
    if(p.x==to.x and p.y==to.y) return 0; //distination co-ordinate reached
    int mini=inf;
    coor c, s, e;
    if(d==1) c = wormhole[pos].ss; //checking whether we start travel the wormhole from it's entry direction or exit direction
    else c = wormhole[pos].ff;

    if(!vis[c.x][c.y] and d != 0 and pos==prev){ //go through wormhole with cost wh_cost[i]
        vis[c.x][c.y] = true;
        mini = min(mini, wh_cost[pos]+findMinimumCost(c, pos, 1, pos)); //going through wormhole
        mini = min(mini, distance(p, c)+findMinimumCost(c, pos, 1, pos)); //there are wormhole but we are not using it. Travelling outside of it
        vis[c.x][c.y] = false;
    }
    s = wormhole[pos].ff; //starting co-ordinate of wormhole
    e = wormhole[pos].ss; //ending co-ordinate of wormhole
    if(!vis[s.x][s.y]){ //visiting start index of wormhole
        vis[s.x][s.y] = true;
        mini = min(mini, distance(p, s)+findMinimumCost(s, pos, 1, pos));
        vis[s.x][s.y] = false; 
    }
    if(!vis[e.x][e.y]){ //visiting end index of wormhole
        vis[e.x][e.y] = true;
        mini = min(mini, distance(p, e)+findMinimumCost(e, pos, 2, pos));
        vis[e.x][e.y] = false;
    }
    mini = min(mini, distance(p, to)+findMinimumCost(to, pos, 1, pos)); //from each co-ordinate we go to our distination point and check if it is the optimal
    mini = min(mini, findMinimumCost(p, pos+1, 1, pos)); //we are not going to this wormhole that located in 'pos' position
    return mini;
}

void solve(lli tc){
    cin >> n;
    cin >> from.x >> from.y >> to.x >> to.y;
    for(int i=0; i<n; i++){
        coor st, ed;
        cin >> st.x >> st.y >> ed.x >> ed.y >> wh_cost[i];
        wormhole[i] = {st, ed};
    }
    mem(vis, 0);
    print(findMinimumCost(from, 0, 0, 0));
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
