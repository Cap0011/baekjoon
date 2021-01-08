#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int stair[305]={0};
	int cnt[305]={0};
	int conse;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stair[i];
	}
	cnt[1] = stair[1];
	cnt[2] = stair[2]+stair[1];
	for(int i=3;i<=n;i++){
		cnt[i] = max(cnt[i-2]+stair[i], cnt[i-3]+stair[i]+stair[i-1]);
	}
	cout<<cnt[n]<<'\n';
	return 0;
}
