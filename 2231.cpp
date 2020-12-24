#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int result=-1;
	int sum, temp;
	for(int i=1;i<n;i++){
		sum=i;
		temp=i;
		while(temp>0){
			sum+=temp%10;
			temp/=10;
		}
		if(sum==n){
			result=i;
			break;
		}
	}
	if(result==-1) printf("0\n");
	else printf("%d\n",result);
}
