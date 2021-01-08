#include <iostream>
using namespace std;
int paper[2200][2200];
int cnt[3] = {0};
void solve(int x, int y, int n){
	if(n==1){ 
		cnt[paper[x][y]+1]++;
		return;
	}
	bool neg = false;
	bool zero = false;
	bool pos = false;
	for(int i = x; i<x+n;i++){
		for(int j = y ; j<y+n;j++){
			if(paper[i][j]==-1) neg = true;
			else if(paper[i][j]==0) zero = true;
			else pos = true;
		}
	}
	if(neg&&!zero&&!pos){
		cnt[0]++;
		return;
	}
	if(!neg&&zero&&!pos){
		cnt[1]++;
		return;
	}
	if(!neg&&!zero&&pos){
		cnt[2]++;
		return;
	}
	n/=3;
	solve(x, y, n);
	solve(x+n, y, n);
	solve(x+2*n, y, n);
	solve(x, y+n, n);
	solve(x+n, y+n, n);
	solve(x+2*n, y+n, n);
	solve(x, y+2*n, n);
	solve(x+n, y+2*n, n);
	solve(x+2*n, y+2*n, n);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>paper[i][j];
		}
	}
	solve(0, 0, n);
	cout<<cnt[0]<<'\n';
	cout<<cnt[1]<<'\n';
	cout<<cnt[2]<<'\n';
}
