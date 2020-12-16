#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
	bool zone[101][101]={false};
	bool check[101][101]={false};
	int n, m;
	cin>>n>>m;
	char c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c;
			zone[i][j]=c-'0';
		}
	}
	queue<int> q;
	int row=1;
	int col=1;
	queue<int> bound;
	bound.push(1);
	int cnt=0;
	q.push(1);
	while(q.size()>0){
		int val = q.front();
		if(val==bound.front()){
			printf("[%d]",val);
			cnt++;
			bound.pop();
		}
		row = val/m + 1;
		col = val-(row-1)*m;
		check[row][col]=true;
		bool is=false;
		if(zone[row-1][col]&&!check[row-1][col]){
			if(row-1==n&&col==m) break;
			q.push(col+(row-2)*m);
			is=true;
		}
		if(zone[row+1][col]&&!check[row+1][col]){
			if(row+1==n&&col==m) break;
			q.push(col+(row)*m);
			is=true;
		}
		if(zone[row][col-1]&&!check[row][col-1]){
			if(row==n&&col-1==m) break;
			q.push(col-1+(row-1)*m);
			is=true;
		}
		if(zone[row][col+1]&&!check[row][col+1]){
			if(row==n&&col+1==m) break;
			q.push(col+1+(row-1)*m);
			is=true;
		}
		if(is) bound.push(q.back());
		printf("<%d>",bound.front());
		q.pop();
	}
	cnt++;
	printf("%d\n", cnt);
}
