#include <iostream>
#include <queue>
using namespace std;
int main(){
	queue<int> q;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	int temp;
	while(q.size()>1){
		q.pop();
		if(q.size()==1) break;
		temp = q.front();
		q.push(temp);
		q.pop();
	}
	printf("%d\n", q.front());
}
