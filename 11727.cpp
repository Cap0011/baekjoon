#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int cnt[1005]={0};

	cnt[1] = 1;
	cnt[2] = 3;
	for(int i=3;i<=n;i++){
		cnt[i] = (cnt[i-1] + (cnt[i-2]*2)%10007)%10007;
	}
	cout<<cnt[n]<<'\n';
}
