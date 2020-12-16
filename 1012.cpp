#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool zone[51][51]={false};
bool check[51][51]={false};
vector<int> v;
int cnt;
void dfs(int r, int c){
	if(!zone[r][c]||check[r][c]) return;
	else{
		check[r][c]=true;
		if(check[r-1][c]==false&&check[r+1][c]==false&&check[r][c-1]==false&&check[r][c+1]==false){
			cnt++;
		}
		dfs(r-1,c);
		dfs(r+1,c);
		dfs(r,c-1);
		dfs(r,c+1);
	}
	return;
}
int main(){
	int t, m, n, k;
	cin>>t;
	int r, c;
	for(int i=0;i<t;i++){
		cin>>m>>n>>k;
		cnt=0;
		memset(zone, false, sizeof zone);
		memset(check, false, sizeof check);
		for(int a=0;a<k;a++){
			cin>>r>>c;
			zone[r+1][c+1]=true;
		}
		for(int a=1;a<=m;a++){
			for(int b=1;b<=n;b++){
				if(zone[a][b]) dfs(a, b);
			}
		}
		v.push_back(cnt);
	}
	for(auto x:v){
		printf("%d\n",x);
	}
}
