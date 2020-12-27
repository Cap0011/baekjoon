#include <iostream>
#include <stack>
#include <deque>
#include <vector>
using namespace std;
int main(){
	stack<int> s;
	deque<int> q;
	vector<bool> v;
	bool check[100005]={false};
	int n, temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		q.push_back(temp);
	}
	bool impossible=false;
	int target;
	int index=1;
	while(q.size()>0){
		target = q.front();
		if(index<=target){
			while(index<=target){
				s.push(index);
				check[index]=true;
				v.push_back(true);
				index++;
			}
			s.pop();
			check[target]=false;
			v.push_back(false);
			q.pop_front();
		}else if(check[target]){
			while(s.top()!=target){
				check[s.top()]=false;
				s.pop();
				v.push_back(false);
			}
			s.pop();
			check[target]=false;
			v.push_back(false);
			q.pop_front();
		}else{
			impossible=true;
			break;
		}
	}
	if(impossible) printf("NO\n");
	else{
		for(auto x:v){
			if(x) printf("+\n");
			else printf("-\n");
		}
	}
	return 0;
}
