#include <iostream>
#include <limits.h> //for INT_MAX
#include <cstring> //for memset
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int targetLevel, answer = 0;

int toInteger(string s){ //function to convert string number to integer number
	int n = 0;
	for(auto p : s){
		n*=10;
		n+=(p-'0');
	}
	return n;
}

void solve(string s, int level){
	string left="", right="", tmp="", headNum = "";
	int sum = 0, p = 1;
	//find the int number that represents node value. The number can contains many digits
	while(s[p] != '('){
		headNum += s[p];
		p++;
	}

	int node = toInteger(headNum); //convert it to integer

	if(level == targetLevel){ //target level found
		answer += node; //add the value 
		return;
	}

	for(int i=p; i<s.size()-1; i++){ //look for left & right sub tree
		tmp += s[i]; //keep contracting tree
		if(s[i] == '(') sum++;
		if(s[i] == ')') sum--;
		if(!sum){ //valid subtree found
			if(!left.size()){ //determine whether we should keep it in left or right
				left = tmp;
				tmp.clear(); //clear current tree
			}
			else{ //left subtree is already found. So keep it to right
				right = tmp;
				tmp.clear();
			}
		}
	}

	//() means null
	if(left != "()"){ //left is not null
		solve(left, level+1);
	}
	if(right != "()"){ //right is not null
		solve(right, level+1);
	}
}

int main(){
    freopen("input.txt", "r", stdin);  
    freopen("output.txt", "w", stdout);

    string s;
    cin >> targetLevel >> s;

    solve(s, 0);

    cout << answer << endl;

    return 0;
}

