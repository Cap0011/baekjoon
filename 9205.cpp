#include <iostream>
#include <cstring>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cs[105][2];
	bool check[105][105];
	int t;
	cin>>t;
	for(int k=0;k<t;k++){
		memset(cs, 0, sizeof cs);
		memset(check, false, sizeof check);
		int n;
		cin>>n;
		for(int i=0;i<=n+1;i++){
			cin>>cs[i][0]>>cs[i][1];
		}
		for(int i=0;i<=n+1;i++){
			for(int j=0;j<=n+1;j++){
				if(abs(cs[i][0]-cs[j][0])+abs(cs[i][1]-cs[j][1])<=1000){
					check[i][j]=true;
					check[j][i]=true;
				}
			}
		}
		for(int k=0;k<=n+1;k++){
			for(int i=0;i<=n+1;i++){
				if(!check[i][k]) continue;
				for(int j=0;j<=n+1;j++){
					if(check[i][j]) continue;
					if(check[k][j]) check[i][j] = true;
				}
			}
		}
		if(check[0][n+1]) cout<<"happy\n";
		else cout<<"sad\n";
	}
	return 0;
}
