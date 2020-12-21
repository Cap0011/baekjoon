#include <iostream>
#include <queue>
using namespace std;
int main(){
	bool zone[101][101]={false};
	int check[10101]={0};
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
	int row,col;
	q.push(1);
	check[1] = 1;
	while(q.size()>0){
		int val = q.front();
		if(val%m==0){
			row=val/m;
			col=m;
		}else{
			row = val/m + 1;
			col = val-(row-1)*m;
		}
		int temp;
		if(zone[row-1][col]){
			temp = col+(row-2)*m;
			if(!check[temp]){
				q.push(temp);
				check[temp] = check[val]+1;
			}
		}
		if(zone[row][col-1]){
			temp = col-1+(row-1)*m;
			if(!check[temp]){
				q.push(temp);
				check[temp] = check[val]+1;
			}
		}
		if(zone[row][col+1]){
			temp = col+1+(row-1)*m;
			if(!check[temp]){
				q.push(temp);
				check[temp] = check[val]+1;
			}
		}
		if(zone[row+1][col]){
			temp = col+(row)*m;
			if(!check[temp]){
				q.push(temp);
				check[temp] = check[val]+1;
			}
		}
		q.pop();
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",check[m*(i-1)+j]);
		}
		printf("\n");
	}*/
	printf("%d\n", check[n*m]);
}
