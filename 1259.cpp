#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int main(){
	int temp;
	vector<bool> v;
	cin>>temp;
	while(temp!=0){
		if(temp<10) v.push_back(true);
		else if(temp<100){
			if(temp%10==temp/10) v.push_back(true);
			else v.push_back(false);
		}else if(temp<1000){
			if(temp%10==temp/100) v.push_back(true);
			else v.push_back(false);
		}else if(temp<10000){
			if(temp%10==temp/1000&&(temp/10)%10==(temp/100)%10) v.push_back(true);
			else v.push_back(false);
		}else{
			if(temp%10==temp/10000&&(temp/10)%10==(temp/1000)%10) v.push_back(true);
			else v.push_back(false);
		}
		cin>>temp;
	}
	for(auto x:v){
		if(x) printf("yes\n");
		else printf("no\n");
	}
}
