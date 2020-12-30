#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cnt=0;
	vector<int> v[1005];
	queue<int> q;
	bool check[1005]={false};
	int n, m;
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int target=1;
	while(target<=n){
		check[target]=true;
		q.push(target);
		while(!q.empty()){
			int tar = q.front();
			check[tar] = true;
			while(v[tar].size()>0){
				int temp = v[tar].back();
				if(!check[temp]){
					q.push(temp);
					check[temp] = true;
				}
				v[tar].pop_back();
			}
			q.pop();
		}
		while(check[target]){
			target++;
		}
		cnt++;
	}
	cout<<cnt<<"\n";
}
