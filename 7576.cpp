#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int main(){
	int m, n;
	int zone[1005][1005]={0};
	int check[1005][1005];
	memset(check, -1, sizeof check);
	cin>>m>>n;
	bool isDone=true;
	queue<int> start;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>zone[i][j];
			if(zone[i][j]==0) isDone=false;
			if(zone[i][j]==1){
				start.push((i-1)*m+j);
				check[i][j]=0;
			}
		}
	}
	if(isDone){
		printf("0\n");
		return 0;
	}
	int val, row, col;
	while(start.size()>0){
		val = start.front();
		if(val%m==0){
			row = val/m;
			col = m;
		}else{
			row = val/m+1;
			col = val%m;
		}

		if(row-1>=1&&zone[row-1][col]==0){
			zone[row-1][col]=1;
			check[row-1][col]=check[row][col]+1;
			start.push((row-2)*m+col);
		}
		if(col-1>=1&&zone[row][col-1]==0){
			zone[row][col-1]=1;
			check[row][col-1]=check[row][col]+1;
			start.push((row-1)*m+col-1);
		}
		if(col+1<=m&&zone[row][col+1]==0){
			zone[row][col+1]=1;
			check[row][col+1]=check[row][col]+1;
			start.push((row-1)*m+col+1);
		}
		if(row+1<=n&&zone[row+1][col]==0){
			zone[row+1][col]=1;
			check[row+1][col]=check[row][col]+1;
			start.push((row)*m+col);
		}
		start.pop();
	}
	int max=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(zone[i][j]==0){
				printf("-1\n");
				return 0;
			}
			if(max<check[i][j]) max = check[i][j];
		}
	}
	printf("%d\n",max);
	return 0;
}
