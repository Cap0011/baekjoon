#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	unsigned long long cnt[1000];
	cnt[1]=1;
	cnt[2]=2;
	for(int i=3;i<=1000;i++){
		cnt[i] = (cnt[i-1]+cnt[i-2])%10007;
	}
	cout<<cnt[n]<<"\n";
	return 0;
}
