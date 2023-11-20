#include <iostream>
#include <limits.h> //for INT_MAX
#include <cstring> //for memset

using namespace std;

int n;
int balloon[12];
bool vis[12];

int findLeft(int pos){
	int l = -1;
	for(int i=pos-1; i>=0; i--){
		if(!vis[i]){
			l = i;
			break;
		}
	}
	return l;
}

int findRight(int pos){
	int r = -1;
	for(int i=pos+1; i<n; i++){
		if(!vis[i]){
			r = i;
			break;
		}
	}
	return r;
}

int getPoint(int pos){
	int idx_L = findLeft(pos);
	int idx_R = findRight(pos);
	if(idx_R != -1 && idx_L != -1){
		return balloon[idx_L]*balloon[idx_R];
	} 
	else if(idx_R != -1){
		return balloon[idx_R];
	}
	else if(idx_L != -1){
		return balloon[idx_L];
	}
	else{
		return balloon[pos];
	}
}

int burst(){
	int point = 0;
	for(int i=0; i<n; i++){
		if(vis[i]) continue;
		vis[i] = true; //destroy balloon
		point = max(point, getPoint(i) + burst());
		vis[i] = false; //restore balloon
	}

	return point;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //iterative DFS diye problem solving korte hobe

    cin >> n;

    for(int i=0; i<n; i++){
    	cin >> balloon[i];
    }
	int res = 0;

    memset(vis, false, sizeof(vis));
    res = burst();
    cout << res << endl;

    return 0;
}
