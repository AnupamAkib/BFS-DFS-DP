//https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/sum-of-nodes-in-kth-level/problem

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

int k;
bool graph[100][100];

int string2Number(string s){
    int r = 0, f = 1;
    for(int i=s.sz-1; i>=0; i--){
        r += f*(s[i]-'0');
        f *= 10;
    }
    return r;
}

int constract_tree(string s){
    if(s=="(*)") return -1;
    int cnt=0, p=1, x;
    string d;
    //get current sub string root
    while(s[p]-'0' >=0 and s[p]-'0' <= 9){
        d += s[p];
        p++;
    }
    string left, right;
    x = p;
    //search for left string
    for(int i=p; i<s.sz; i++, x++){
        if(s[i]=='(') cnt++;
        if(s[i]==')') cnt--;
        left += s[i];
        if(cnt==0) break;
    }
    cnt=0;
    //search for right string
    for(int i=x+1; i<s.sz; i++){
        if(s[i]=='(') cnt++;
        if(s[i]==')') cnt--;
        right += s[i];
        if(cnt==0) break;
    }
    int nd = string2Number(d);
    int l = constract_tree(left);
    int r = constract_tree(right);
    if(l!=-1) graph[nd][l] = 1;
    if(r!=-1) graph[nd][r] = 1;
    return nd;
}

int BFS(int root){
    bool vis[10000] = {0};
    queue<int> Q;
    vis[root] = 1;
    Q.push(root);
    int lvl[20] = {0}, sum=0;
    while(!Q.empty()){
        int head = Q.front();
        Q.pop();
        if(lvl[head]==k) sum += head; //level is K
        for(int i=0; i<100; i++){
            if(graph[head][i] and !vis[i]){
                vis[i] = true;
                Q.push(i);
                lvl[i] = lvl[head] + 1;
            }
        }
    }
    return sum;
}

void solve(lli tc){
    cin >> k;
    string s;
    cin >> s;
    for(int i=0; i<s.sz; i++){ //mark child of leaf node as *
        if(s[i]=='(' and s[i+1]==')'){
            s.insert(s.begin()+i+1, '*');
            i++;
        }
    }
    mem(graph, 0);
    constract_tree(s);
    string rt="";
    for(int i=1; i<s.sz; i++){ //get the root element
        if(s[i]-'0'>=0 and s[i]-'0'<=9) rt+=s[i];
        else break;
    }
    int root = string2Number(rt); 
    print(BFS(root));
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
