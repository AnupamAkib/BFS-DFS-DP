//Problem link: https://www.hackerearth.com/problem/algorithm/question-7-4/

#include <iostream>
#include <limits.h> //for INT_MAX
#include <cstring> //for memset
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> pipes[10];
int n, m, x, y, lvl, groundMap[1010][1010];
int dir[1010][1010];
bool vis[1010][1010];

void initializePipes(){
	pipes[1].push_back({ {0, 1}, {0, -1}, {1, 0}, {-1, 0} });
	pipes[2].push_back({ {1, 0}, {-1, 0} });
	pipes[3].push_back({ {0, 1}, {0, -1} });
	pipes[4].push_back({ {-1, 0}, {0, 1} });
	pipes[5].push_back({ {1, 0}, {0, 1} });
	pipes[6].push_back({ {0, -1}, {1, 0} });
	pipes[7].push_back({ {-1, 0}, {0, -1} });
}


int endoscope(int X, int Y){
	int cnt = 1;
	memset(vis, false, sizeof(vis));
	memset(dir, 0, sizeof(dir));
	queue<pair<int, int>> q;
	q.push({X, Y});
	vis[X][Y] = true;
	dir[X][Y] = 1;
	
	pair<int, int> head;
	while(!q.empty()){
		head = q.front();
		q.pop();
		int u = head.first;
		int v = head.second;
		if(dir[u][v] == lvl){
			continue;
		}

		for(auto p : pipes[groundMap[u][v]][0]){
			X = u + p.first;
			Y = v + p.second;
			if(X >= 0 and X < n and Y >= 0 and Y < m){
				int k = groundMap[X][Y], x1, y1;

				bool jawaJabe = false;

				if(k){
					for(auto q : pipes[k][0]){

						x1 = X + q.first;
						y1 = Y + q.second;
						if(u == x1 and v == y1){
							jawaJabe = true;
						}
					}

					if(!vis[X][Y] && jawaJabe){
						vis[X][Y] = true;
						q.push({X, Y});
						dir[X][Y] = 1 + dir[u][v];
						cnt++;
					}
				}
			}
		}
	}
	return cnt;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    initializePipes();

    int tc;
    cin >> tc;
    while(tc--){
    	cin >> n >> m >> x >> y >> lvl;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
    			cin >> groundMap[i][j];
    		}
    	}
    	if(groundMap[x][y]==0){
    		cout << 0 << endl;
    	}
    	else cout << endoscope(x, y) << endl;
    }
    return 0;
}
