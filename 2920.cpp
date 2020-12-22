#include <iostream>
using namespace std;
int main(){
	int temp;
	int before;
	cin>>before>>temp;
	int b=before-temp;
	before=temp;
	for(int i=0;i<6;i++){
		cin>>temp;
		if((before-temp)!=b){
			printf("mixed\n");
			return 0;
		}
		before=temp;
	}
	if(b==1){
		printf("descending\n");
	}else{
		printf("ascending\n");
	}
	return 0;
}
