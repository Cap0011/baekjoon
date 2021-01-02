#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt[50005] = {0};
	int n;
	cin>>n;
	for(int i=1;i<224;i++){
		cnt[i*i] = 1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<224;j++){
			if(j*j>=i) break;
			if(cnt[i]==0||cnt[i]>cnt[i-j*j]+1) cnt[i]=cnt[i-j*j]+1;
		}
	}
	cout<<cnt[n]<<'\n';
}
