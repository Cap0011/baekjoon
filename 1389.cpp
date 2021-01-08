#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int check[105][105]={0};
	int a, b;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		check[a][b]=1;
		check[b][a]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			if(!check[i][k]) continue;
			for(int j=1;j<=n;j++){
				if(i!=j){
					if(check[k][j]&&check[i][j]) check[i][j]=min(check[i][j],check[i][k]+check[k][j]);
					else if(check[k][j]&&!check[i][j]) check[i][j] = check[i][k]+check[k][j];
				}
			}
		}
	}
	int sum;
	int index;
	int min = -1;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<=n;j++){
			if(i!=j) sum+=check[i][j];
		}
		if(min<0||sum<min){
			min = sum;
			index = i;
		}
	}
	cout<<index<<'\n';
}
