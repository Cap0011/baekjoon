#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int check[1000005];
	int m, n, h;
	cin>>m>>n>>h;
	for(int i=0;i<h;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				cin>>check[i*m*n+j*m+k];
			}
		}
	}
}
