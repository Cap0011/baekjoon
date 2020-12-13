#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> v;

void solve(){
	if(v.size()==m){
		for(auto x:v){
			printf("%d ",x);
		}
		printf("\n");
		return;
	}else{
		for(int i=1;i<=n;i++){
			v.push_back(i);
			solve();
			v.pop_back();
		}
	}
}
int main(){
	cin>>n>>m;
	solve();
}
