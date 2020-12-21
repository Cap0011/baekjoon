#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int space=0;
	for(int i=n;i>=1;i--){
		for(int j=0;j<space;j++){
			printf(" ");
		}
		for(int j=0;j<i*2-1;j++){
			printf("*");
		}
		printf("\n");
		space++;
	}
}
