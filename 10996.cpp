#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j%2==0){
				for(int k=0;k<j/2;k++){
					for(int s=0;s<k/2;s++){
						printf(" ");
					}
					printf("* *");
				}
				for(int s=0;s<j/2;s++){
					printf(" ");
				}
				printf("*");
			}else{
				printf(" *\n");
			}
		}
	}
}
