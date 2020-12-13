#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

bool check(int num){
	for(auto x:v){
		if(x==num){
			return true;
		}
	}
	return false;
}
void solve(){
	if(v.size() == m){
		for(auto x : v){
			printf("%d ", x);
		}
		printf("\n");
		return;
	}
	else{
		for(int i=1 ; i<=n ; i++){
			if(!check(i)){
				v.push_back(i);
				solve();
				v.pop_back();
			}
		}
	}
}

int main(){
	cin >> n >> m;
	solve();
}

