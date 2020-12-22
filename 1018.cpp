#include <iostream>
using namespace std;
int main(){
	bool board[60][60];
	bool bl[60][60]={false};
	bool wh[60][60]={false};
	int n, m;
	cin>>n>>m;
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			if(i%2==0){
				if(j%2==0) bl[i][j]=true;
				else wh[i][j]=true;
			}else{
				if(j%2==0) wh[i][j]=true;
				else bl[i][j]=true;
			}
		}
	}
	char temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>temp;
			if(temp=='B') board[i][j]=true;
		}
	}
	int row=0;
	int col=0;
	int min=10000;
	int w=0;
	int b=0;
	while(row<n-7){
		for(int i=row;i<row+8;i++){
				for(int j=col;j<col+8;j++){
					if(bl[i][j]!=board[i][j]) b++;
					if(wh[i][j]!=board[i][j]) w++;
				}
		}
		col++;
		if(col==m-7){
			row++;
			col=0;
		}
		if(min>w)min=w;
		if(min>b)min=b;
		w=0;
		b=0;
	}
	printf("%d\n",min);
}
