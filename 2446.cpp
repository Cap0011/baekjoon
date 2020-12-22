#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i-1;j++){
			printf(" ");
		}
		for(int j=0;j<(n-i)*2+1;j++){
			printf("*");
		}
		for(int j=0;j<i-1;j++){
			printf(" ");
		}
		printf("\n");
	}
	for(int i=n-1;i>=1;i--){
		for(int j=0;j<i-1;j++){
			printf(" ");
		}
		for(int j=0;j<(n-i)*2+1;j++){
			printf("*");
		}
		for(int j=0;j<i-1;j++){
			printf(" ");
		}
		printf("\n");
	}
}
