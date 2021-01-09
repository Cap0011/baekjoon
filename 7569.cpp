#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[1000005];
	int check[1000005];
	memset(check, -1, sizeof check);
	
	queue<int> q;
	int m, n, h;
	cin>>m>>n>>h;
	bool isDone=true;
	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				int index = i*m*n+j*m+k;
				cin>>arr[index];
				if(arr[index]==1){ 
					q.push(index);
					check[index]=0;
				}
				if(arr[index]==0) isDone=false;
			}
		}
	}
	if(isDone){
		cout<<"0\n";
		return 0;
	}
	while(q.size()>0){
		int tar = q.front();
		int val = tar-m;
		if(tar%(m*n)-m>=0&&arr[val]==0){
			q.push(val);
			check[val] = check[tar]+1;
			arr[val]=1;
		}
		val = tar-1;
		if(tar%m-1>=0&&arr[val]==0){
			q.push(val);
			check[val] = check[tar]+1;
			arr[val]=1;
		}
		val = tar+1;
		if(tar%m!=m-1&&arr[val]==0){
			q.push(val);
			check[val] = check[tar]+1;
			arr[val]=1;
		}
		val = tar+m;
		if(tar%(m*n)<m*(n-1)&&arr[val]==0){
			q.push(val);
			check[val] = check[tar]+1;
			arr[val]=1;
		}
		val = tar+m*n;
		if(tar/(m*n)<(h-1)&&arr[val]==0){
			q.push(val);
			check[val] = check[tar]+1;
			arr[val]=1;
		}
		val = tar-m*n;
		if(tar/(m*n)>0&&arr[val]==0){
			q.push(val);
			check[val] = check[tar]+1;
			arr[val]=1;
		}
		q.pop();
	}
	int max=-1;
	for(int i=0;i<m*n*h;i++){
		if(arr[i]==0){
			cout<<"-1\n";
			return 0;
		}
		if(max<check[i]) max = check[i];
	}
	cout<<max<<'\n';
	/*
	for(int i=0;i<h;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				int index = i*m*n+j*m+k;
				cout<<check[index]<<' ';
			}
			cout<<'\n';
		}
		cout<<'\n';
	}
	*/
}
