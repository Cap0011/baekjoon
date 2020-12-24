#include <iostream>
#include <string>
using namespace std;
int main(){
	string buf;
	int n;
	int size=0;
	int stack[10005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>buf;
		if(buf=="push"){
			int temp;
			cin>>temp;
			stack[++size]=temp;
		}else if(buf=="pop"){
			if(size!=0) printf("%d\n",stack[size--]);
			else printf("-1\n");
		}else if(buf=="size"){
			printf("%d\n",size);
		}else if(buf=="empty"){
			if(size==0) printf("1\n");
			else printf("0\n");
		}else if(buf=="top"){
			if(size!=0) printf("%d\n",stack[size]);
			else printf("-1\n");
		}
	}
}
