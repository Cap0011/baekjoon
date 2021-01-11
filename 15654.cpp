#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<int> temp;
int n, m;
bool check(int num){
	for(auto x:temp){
		if(x==num) return true;
	}
	return false;
}
void solve(){
	if(temp.size()==m){
		for(auto x:temp){
			cout<<x<<' ';
		}
		cout<<'\n';
		return;
	}
	for(auto x:v){
		if(!check(x)){ 
			temp.push_back(x);
			solve();
			temp.pop_back();
		}
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	solve();
}
