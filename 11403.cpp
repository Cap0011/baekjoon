#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool arr[105][105]={false};
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			if(i==k) continue;
			if(!arr[i][k]) continue;
			for(int j=0;j<n;j++){
				if(arr[i][j]) continue;
				if(arr[k][j]) arr[i][j]=true;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
