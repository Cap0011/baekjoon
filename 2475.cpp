#include <iostream>
using namespace std;
int main(){
	int temp;
	int sum=0;
	for(int i=0;i<5;i++){
		cin>>temp;
		sum+=temp*temp;
	}
	printf("%d\n",sum%10);
}
