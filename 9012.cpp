#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main(){
	int left=0;
	char buf[100];
	vector<bool> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		memset(buf, '\0', sizeof buf);
		left=0;
		scanf("%s",buf);
		for(int i=0;buf[i]!='\0';i++){
			if(buf[i]=='(') left++;
			else if(buf[i]==')'){
				left--;
				if(left<0){
					left=-1;
					break;
				}
			}
		}
		if(left!=0) v.push_back(false);
		else v.push_back(true);
	}
	for(auto x:v){
		if(x==false){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
}
