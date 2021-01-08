#include <iostream>
using namespace std;
int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a=b;
		b=r;
	}
	return a;
}
int lcm(int a, int b){
	return a*b/gcd(a,b);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int m, n, x, y;
		cin>>m>>n>>x>>y;
		if(m==x&&n==y){
			cout<<lcm(m,n)<<'\n';
			continue;
		}
		bool check = false;
		int cnt = x;
		int limit = lcm(m,n);
		int _y;
		if(x%n==0) _y=n;
		else _y = x%n;
		for(int j=_y;cnt<=limit;){
			if(j==y){
				check = true;
				break;
			}
			j+=m;
			j%=n;
			if(j==0) j=n;
			cnt+=m;
		}
		if(!check) cout<<"-1"<<'\n';
		else cout<<cnt<<'\n';
	}
}
