#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	int zero[41];
	int one[41];
	zero[0]=1;
	zero[1]=0;
	one[0]=0;
	one[1]=1;
	for(int i=2;i<=40;i++){
		zero[i] = zero[i-1]+zero[i-2];
		one[i] =one[i-1]+one[i-2];
	}
	int n;
	for(int i=0;i<t;i++){
		cin>>n;
		cout<<zero[n]<<" "<<one[n]<<"\n";
	}
	return 0;
}
