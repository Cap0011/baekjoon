#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, k;
	int coin[10];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>coin[i];
	}
	
	int cnt=0;
	for(int i=n-1;i>=0;i--){
		while(k>=coin[i]){
			cnt++;
			k-=coin[i];
		}
	}
	printf("%d\n",cnt);
}
