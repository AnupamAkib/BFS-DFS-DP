#include <iostream>
#include <limits.h> //for INT_MAX
#include <cstring> //for memset
#include <vector>
using namespace std;


int totalWormholes;
pair<int, int> source, target;

pair<int, int> holeStart[5];
pair<int, int> holeEnd[5];
int holeCost[5], mini;
bool vis[5];

pair<int, int> inputLocation(){
	int a, b;
	cin >> a >> b;
	return {a, b};
}

int findDistance(pair<int, int> a, pair<int, int> b){
	int dis = abs(a.first - b.first) + abs(a.second - b.second);
	return dis;
}

void calculateMinCost(int i, pair<int, int> currentPos, int cost){
	//calculate cost from all generated position to the target
	mini = min(mini, cost+findDistance(currentPos, target));

	if(i==totalWormholes){ //i is out of bound
		return;
	}

	//if currently we are in wormhole start position then try to enter through wormhole start position and out at at end pos
	if(currentPos.first == holeStart[i].first && currentPos.second == holeStart[i].second){ 
		if(!vis[i]){ //checking if this wormhole used previously, we don't need to use a wormhole more than once
			vis[i] = true;
			calculateMinCost(i+1, holeEnd[i], holeCost[i]+cost); //holeCost[i] is the cost for using the i'th wormhole
			vis[i] = false;
		}
		//we should check going outside the wormhole as well, here we need to calculate the distance
		calculateMinCost(i+1, holeEnd[i], findDistance(currentPos, holeEnd[i])+cost);
	}
	//if currently we are in wormhole end position then try to enter through wormhole end position and out at at first pos
	else if(currentPos.first == holeEnd[i].first && currentPos.second == holeEnd[i].second){
		if(!vis[i]){ //checking if this wormhole used previously, we don't need to use a wormhole more than once
			vis[i] = true;
			calculateMinCost(i+1, holeStart[i], holeCost[i]+cost); //holeCost[i] is the cost for using the i'th wormhole
			vis[i] = false;
		}
		//we should check going outside the wormhole as well, here we need to calculate the distance
		calculateMinCost(i+1, holeStart[i], findDistance(currentPos, holeStart[i])+cost);
	}
	else{
		//go to i'th wormhole's first position
		calculateMinCost(i, holeStart[i], findDistance(currentPos, holeStart[i])+cost);
		//go to i'th wormhole's last position
		calculateMinCost(i, holeEnd[i], findDistance(currentPos, holeEnd[i])+cost);
	}
	//do not use the i'th wormhole
	calculateMinCost(i+1, currentPos, cost);
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int N = 10;

    cin >> N;

    for(int t=1; t<=N; t++){
    	cin >> totalWormholes;
    	source = inputLocation();
    	target = inputLocation();
    	for(int i=0; i<totalWormholes; i++){
    		holeStart[i] = inputLocation();
    		holeEnd[i] = inputLocation();
    		cin >> holeCost[i];
    	}
    	mini = 1e8;
    	memset(vis, false, sizeof(vis));
    	calculateMinCost(0, source, 0);
    	cout << mini << endl;
    }

    return 0;
}
