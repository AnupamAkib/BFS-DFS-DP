//Statement: https://docs.google.com/document/d/1bXQlDr482oKyxjCBmmMCrr3VE2sj7BIbhTDxLnYGg8Q/edit
//Input, Output, Code: https://ideone.com/gYAJn5
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

int matrixSize, numOfRareElements;
int rareElementsPosition[50][50], matrix[50][50];

int BFS(int x, int y){
    bool vis[50][50] = {false};
    int dist[50][50] = {0}, maximumDistance = 0;
    int visitedRareElements = 0;
    queue<pair<int, int> > Q;
    Q.push({x, y});
    vis[x][y] = true;
    while(!Q.empty()){
        pair<int, int> head = Q.front();
        Q.pop();
        for(int i=0; i<4; i++){
            x = head.ff + dx4[i];
            y = head.ss + dy4[i];
            if(x >= 0 and x < matrixSize and y >= 0 and y < matrixSize){ //check if adjacent is inside matrix
                if(!vis[x][y] and matrix[x][y]){ //there is a road and the road not yet visited
                    Q.push({x, y});
                    vis[x][y] = true;
                    dist[x][y] = dist[head.ff][head.ss] + 1; //increment distance by 1
                    if(rareElementsPosition[x][y]){ //rare element found in this position
                        visitedRareElements++; //one rare element visited so increase the variable by 1
                        maximumDistance = max(maximumDistance, dist[x][y]); //find maximum distance
                    }
                }
            }
        }
    }
    if(visitedRareElements == numOfRareElements) return maximumDistance; //all rare elements visited
    return inf; //all rare elements could not be visited so this position is not suitable for establishing a research center
}

void solve(lli tc){
/*
    Run BFS from each position where there is no rare elements already and there is road. Then get the maximum distance for that position.
    Find max distance for other position too and get the minimum among them as result.
*/
    cin >> matrixSize >> numOfRareElements;
    mem(rareElementsPosition, false);
    for(int i=0; i<numOfRareElements; i++){
        int x, y;
        cin >> x >> y;
        rareElementsPosition[x-1][y-1] = true;
    }
    input2D(matrix, matrixSize, matrixSize);
    int minMaxAnswer = inf;
    for(int i=0; i<matrixSize; i++){
        for(int j=0; j<matrixSize; j++){
            if(matrix[i][j] and !rareElementsPosition[i][j]){ //there is a road and there is no rare element on the road
                //run bfs
                int maxDist = BFS(i, j); //get maximum distance among all rare elements if we establish a research center in {i, j} position
                minMaxAnswer = min(minMaxAnswer, maxDist); //find the minimum distance from all maximum distance
            }
        }
    }
    printcase(minMaxAnswer) //our final answer
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
