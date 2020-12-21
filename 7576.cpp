#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int main(){
	int m, n;
	int zone[1005][1005]={0};
	int check[1005][1005];
	cin>>m>>n;
	bool isDone=true;
	queue<int> start;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>zone[i][j];
			if(zone[i][j]==0) isDone=false;
			if(zone[i][j]==1) start.push((i-1)*m+j);
		}
	}
	printf("okay!");
	if(isDone){
		printf("0\n");
		return 0;
	}
	memset(check, -1, sizeof check);
	queue<int> q;
	int val, row, col;
	while(start.size()>0){
		val = start.front();
		q.push(val);
		if(val%m==0){
			row = val/m;
			col = m;
		}else{
			row = val/m+1;
			col = val%m;
		}
		check[row][col]=0;
		while(q.size()>0){
			int tar = q.front();
			int r,c;
			if(tar%m==0){
				r = tar/m;
				c = m;
			}else{
				r = tar/m+1;
				c = tar%m;
			}
			if(r-1>=1&&zone[r-1][c]!=-1){
				if(zone[r-1][c]==0) zone[r-1][c]=1;
				if(check[r-1][c]<0||check[r-1][c]>check[r][c]+1) check[r-1][c]=check[r][c]+1;
				q.push((r-2)*m+c);
			}
			if(c-1>=1&&zone[r][c-1]!=-1){
				if(zone[r][c-1]==0) zone[r][c-1]=1;
				if(check[r][c-1]<0||check[r][c-1]>check[r][c]+1) check[r][c-1]=check[r][c]+1;
				q.push((r-1)*m+c-1);
			}
			if(c+1<=m&&zone[r][c+1]!=-1){
				if(zone[r][c+1]==0) zone[r][c+1]=1;
				if(check[r][c+1]<0||check[r][c+1]>check[r][c]+1) check[r][c+1]=check[r][c]+1;
				q.push((r-1)*m+c+1);
			}
			if(r+1<=n&&zone[r+1][c]!=-1){
				if(zone[r+1][c]==0) zone[r+1][c]=1;
				if(check[r+1][c]<0||check[r+1][c]>check[r][c]+1) check[r+1][c]=check[r][c]+1;
				q.push((r)*m+c);
			}
			q.pop();
		}
		
		start.pop();
	}
	/*
	int val;
				val=(i-1)*n+j;
				q.push(val);
				check[i][j]=0;
				while(q.size()>0){
					int tar = q.front();
					int row,col;
					if(tar%n==0){
						row = tar/n;
						col = n;
					}else{
						row = tar/n+1;
						col = tar%n;
					}

					if(row-1>=1&&zone[row-1][col]!=-1){
						if(zone[row-1][col]==0){
							zone[row-1][col]=1;
							check[row-1][col]=check[row][col]+1;
							q.push((row-2)*n+col);
						}else if(check[row-1][col]>check[row][col]+1){
							check[row-1][col]=check[row][col]+1;
							q.push((row-2)*n+col);
						}
					}
					if(col-1>=1&&zone[row][col-1]!=-1){
						if(zone[row][col-1]==0){
							zone[row][col-1]=1;
							check[row][col-1]=check[row][col]+1;
							q.push((row-1)*n+col-1);
						}else if(check[row][col-1]>check[row][col]+1){
							check[row][col-1]=check[row][col]+1;
							q.push((row-1)*n+col-1);
						}
					}
					if(col+1<=n&&zone[row][col+1]!=-1){
						if(zone[row][col+1]==0){
							zone[row][col+1]=1;
							check[row][col+1]=check[row][col]+1;
							q.push((row-1)*n+col+1);
						}else if(check[row][col+1]>check[row][col]+1){
							check[row][col+1]=check[row][col]+1;
							q.push((row-1)*n+col+1);
						}
					}
					if(row+1<=m&&zone[row+1][col]!=-1){
						if(zone[row+1][col]==0){
							zone[row+1][col]=1;
							check[row+1][col]=check[row][col]+1;
							q.push((row)*n+col);
						}else if(check[row+1][col]>check[row][col]+1){
							check[row+1][col]=check[row][col]+1;
							q.push((row)*n+col);
						}
					}
					q.pop();
				}
	*/
	int max=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(zone[i][j]==0){
				printf("-1\n");
				return 0;
			}
			if(max<check[i][j]) max = check[i][j];
			printf("%d ",check[i][j]);
		}
		printf("\n");
	}
	//printf("%d\n",max);

	return 0;
}
