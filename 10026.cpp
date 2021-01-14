#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int board[105][105]={};
bool check[105][105]={};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	char c;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>c;
			if(c=='R') board[i][j]=0;
			else if(c=='G') board[i][j]=1;
			else board[i][j]=2;
		}
	}
	int cnt=0;
	queue<int> q;
	for(int row=0;row<n;row++){
		for(int col=0;col<n;col++){
			if(!check[row][col]){
				cnt++;
				q.push(row*n+col);
				check[row][col]=true;
				while(q.size()>0){
					int r=q.front()/n;
					int c=q.front()%n;
					if(r-1>=0&&!check[r-1][c]&&board[r-1][c]==board[r][c]){
						check[r-1][c]=true;
						q.push((r-1)*n+c);
					}
					if(c-1>=0&&!check[r][c-1]&&board[r][c-1]==board[r][c]){
						check[r][c-1]=true;
						q.push((r)*n+c-1);
					}
					if(c+1<n&&!check[r][c+1]&&board[r][c+1]==board[r][c]){
						check[r][c+1]=true;
						q.push((r)*n+c+1);
					}
					if(r+1<n&&!check[r+1][c]&&board[r+1][c]==board[r][c]){
						check[r+1][c]=true;
						q.push((r+1)*n+c);
					}
					q.pop();
				}
			}
		}
	}
	cout<<cnt<<' ';
	cnt=0;
	bool isB;
	memset(check, false, sizeof check);
	for(int row=0;row<n;row++){
		for(int col=0;col<n;col++){
			if(!check[row][col]){
				cnt++;
				q.push(row*n+col);
				check[row][col]=true;
				if(board[row][col]==2) isB=true;
				else isB=false;
				while(q.size()>0){
					int r=q.front()/n;
					int c=q.front()%n;
					if(!isB){
					if(r-1>=0&&!check[r-1][c]&&board[r-1][c]<2){
						check[r-1][c]=true;
						q.push((r-1)*n+c);
					}
					if(c-1>=0&&!check[r][c-1]&&board[r][c-1]<2){
						check[r][c-1]=true;
						q.push((r)*n+c-1);
					}
					if(c+1<n&&!check[r][c+1]&&board[r][c+1]<2){
						check[r][c+1]=true;
						q.push((r)*n+c+1);
					}
					if(r+1<n&&!check[r+1][c]&&board[r+1][c]<2){
						check[r+1][c]=true;
						q.push((r+1)*n+c);
					}
					}else{
					if(r-1>=0&&!check[r-1][c]&&board[r-1][c]==2){
						check[r-1][c]=true;
						q.push((r-1)*n+c);
					}
					if(c-1>=0&&!check[r][c-1]&&board[r][c-1]==2){
						check[r][c-1]=true;
						q.push((r)*n+c-1);
					}
					if(c+1<n&&!check[r][c+1]&&board[r][c+1]==2){
						check[r][c+1]=true;
						q.push((r)*n+c+1);
					}
					if(r+1<n&&!check[r+1][c]&&board[r+1][c]==2){
						check[r+1][c]=true;
						q.push((r+1)*n+c);
					}
					}
					q.pop();
				}
			}
		}
	}
	cout<<cnt<<'\n';
}
