#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long dp[105]={0};
	
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for(int i=6;i<101;i++){
		dp[i] = dp[i-5]+dp[i-1];
	}
	
	int t, n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		cout<<dp[n]<<'\n';
	}
}
