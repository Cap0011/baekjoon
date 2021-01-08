#include <iostream>
using namespace std;
bool board[70][70]={0};
void solve(int x, int y, int n){
	bool t = false;
	bool f = false;
	for(int i=x;i<x+n;i++){
		for(int j=y;j<y+n;j++){
			if(board[i][j]) t = true;
			else f = true;
		}
	}
	if(!t==f){
		if(t) cout<<1;
		else cout<<0;
		return;
	}
	cout<<'(';
	n/=2;
	solve(x, y, n);
	solve(x, y+n, n);
	solve(x+n, y, n);
	solve(x+n, y+n, n);
	cout<<')';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string buf;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>buf;
		for(int j = 0;j<n;j++){
			if(buf[j]=='0') board[i][j] = false;
			else board[i][j] = true;
		}
	}
	solve(0, 0, n);
	cout<<'\n';
}
