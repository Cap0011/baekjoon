#include <iostream>
#include <queue>
using namespace std;
int main(){
	int t;
	cin>>t;
	int n,m, temp;
	int value;
	for(int i=0;i<t;i++){
		int pri[10]={0};
		queue<int> q;
		int max=0;
		cin>>n>>m;
		for(int j=0;j<n;j++){
			cin>>temp;
			if(j==m){ 
				q.push(0);
				value=temp;
				pri[temp]++;
			}else{
				pri[temp]++;
				q.push(temp);
			}
			if(max<temp) max=temp;
		}
		int target;
		bool check;
		int cnt=0;
		while(q.size()>0){
			check=false;
			target=q.front();
			if(target==0){
				check=true;
				target=value;
			}
			if(max==target){
				if(check){
					printf("%d\n",++cnt);
					break;
				}else{
					cnt++;
					q.pop();
					pri[max]--;
					if(!pri[max]){
						for(int j=max-1;j>0;j--){
							if(pri[j]>0){
								max=j;
								break;
							}
						}
					}
				}
			}else{
				int temp = q.front();
				q.pop();
				q.push(temp);
			}
		}
	}
	return 0;
}
