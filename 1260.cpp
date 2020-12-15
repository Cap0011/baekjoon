#include <iostream>
#include <list>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int n, m, start;
list<int> v[1001];
bool checkd[1001] = {false};
bool checkb[1001] = {false};
stack<int> s;
queue<int> q;
void dfs(int tar){
	if(checkd[tar]){
		return;
	}
	s.push(tar);
	printf("%d ", tar);
	checkd[tar]=true;
	for(list<int>::iterator it = v[tar].begin();it!=v[tar].end();++it){
		dfs(*it);
	}
	s.pop();
	return;
}
void bfs(int tar){
	printf("%d ", tar);
	q.push(tar);
	checkb[tar]=true;
	int val;
	while(q.size()>0){
		val = q.front();
		for(list<int>::iterator it = v[val].begin();it!=v[val].end();++it){
			if(!checkb[*it]){
				q.push(*it);
				printf("%d ", *it);
				checkb[*it]=true;
			}
		}
		q.pop();
	}
	return;
}
int main(){
	cin>>n>>m>>start;
	int num, temp;
	for(int i=0;i<m;i++){
		cin>>num>>temp;
		v[num].push_back(temp);
		v[temp].push_back(num);
	}
	for(int i=0;i<=n;i++){
		v[i].sort();
	}
	//DFS
	dfs(start);
	printf("\n");
	
	//BFS
	bfs(start);
	printf("\n");
}
