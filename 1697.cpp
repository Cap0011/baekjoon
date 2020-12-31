#include <iostream>
#include <queue>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin>>n>>k;

	int time[100005] = {0};
	queue<int> q;

	int cnt=0;
	q.push(n);
	int tar;
	while(q.size()>0){
		tar = q.front();
		if(tar==k){
			cout<<time[tar]<<"\n";
			break;
		}
		if((tar-1)<=100000&&(tar>0)&&!time[tar-1]){ 
			time[tar-1] = time[tar]+1;
			q.push(tar-1);
		}
		if((tar+1)<=100000&&!time[tar+1]){ 
			time[tar+1] = time[tar]+1;
			q.push(tar+1);
		}
		if((tar*2)<=100000&&!time[tar*2]){
			time[tar*2] = time[tar]+1;
			q.push(tar*2);
		}
		q.pop();
	}
	return 0;
}
