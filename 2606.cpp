#include <iostream>
#include <vector>
using namespace std;
vector<int> v[101];
int cnt=0;
bool check[101] = {false};

void dfs(int start){
	if(check[start]){
		return;
	}else{
		check[start]=true;
		cnt++;
		for(auto x:v[start]){
			dfs(x);
		}
	}
	return;
}
int main(){
	int n, m;
	cin>>n>>m;
	int t1, t2;
	for(int i=0;i<m;i++){
		cin>>t1>>t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	dfs(1);
	printf("%d\n",--cnt);
}
