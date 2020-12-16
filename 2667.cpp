#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[26][26]={false};
bool check[26][26] = {false};
int id=0;
int cnt=0;
vector<int> v;
void dfs(int row, int col){
	if(map[row][col]==0||check[row][col]){
		return;
	}else{
		if(check[row+1][col]==false&&check[row-1][col]==false&&check[row][col-1]==false&&check[row][col+1]==false){
			id++;
			if(cnt!=0) v.push_back(cnt);
			cnt=0;
		}
		check[row][col]=true;
		cnt++;
		dfs(row-1, col);
		dfs(row+1, col);
		dfs(row, col-1);
		dfs(row, col+1);
	}
	return;
}
int main(){
	int n;
	cin>>n;
	char c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){	
			cin>>c;
			map[i][j] = c-'0';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(map[i][j]==1) dfs(i,j);
		}
	}
	v.push_back(cnt);
	sort(v.begin(), v.end());
	printf("%d\n",id);
	for(auto x:v){
		printf("%d\n",x);
	}
}
