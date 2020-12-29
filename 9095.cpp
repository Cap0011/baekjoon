#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	int temp;
	int cnt[15];
	cnt[1] = 1;
	cnt[2] = 2;
	cnt[3] = 4;
	for(int i=4;i<11;i++){
		cnt[i] = cnt[i-1]+cnt[i-2]+cnt[i-3];
	}
	for(int i=0;i<t;i++){
		cin>>temp;
		cout<<cnt[temp]<<"\n";
	}
	return 0;
}
