#include <iostream>
#include <string>
using namespace std;
int main(){
	string buf;
	int n;
	int queue[20000];
	int size=0;
	int front=1;
	int back=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>buf;
		if(buf=="push"){
			int temp;
			cin>>temp;
			queue[++back]=temp;
			size++;
		}else if(buf=="pop"){
			if(size!=0){	
				size--;
				printf("%d\n",queue[front]);
				front++;
			}else printf("-1\n");
		}else if(buf=="size"){
			printf("%d\n",size);
		}else if(buf=="empty"){
			if(size==0) printf("1\n");
			else printf("0\n");
		}else if(buf=="front"){
			if(size==0) printf("-1\n");
			else printf("%d\n",queue[front]);
		}else if(buf=="back"){
			if(size==0) printf("-1\n");
			else printf("%d\n",queue[back]);
		}
	}
}
