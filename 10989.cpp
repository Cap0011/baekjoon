#include <iostream>
using namespace std;
int main(){
	int arr[10005]={0};
	int n, temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d", &temp);
		arr[temp]++;
	}
	for(int i=1;i<=10000;i++){
		for(int j=0;j<arr[i];j++){
			printf("%d\n",i);
		}
	}
}
