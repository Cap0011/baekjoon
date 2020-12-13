#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> v;

bool check(int target){
	for(auto x:v){
		if(target<x) return false;
	}
	return true;
}
void solve(){
	if(v.size()==m){
		for(auto x:v){
			printf("%d ",x);
		}
		printf("\n");
	}else{
		for(int i=1;i<=n;i++){
			if(check(i)){
				v.push_back(i);
				solve();
				v.pop_back();
			}
		}
	}
}
int main(){
	cin>>n>>m;
	solve();
}
