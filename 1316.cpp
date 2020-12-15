#include <iostream>
#include <cstring>
using namespace std;
bool check(char* s){
	bool is[26]={false};
	is[s[0]-'a']=true;
	for(int i=1;i<strlen(s);i++){
		if(s[i]!=s[i-1]&&is[s[i]-'a']==true){
			return false;
		}else{
			is[s[i]-'a']=true;
		}
	}
	return true;
}
int main(){
	int num;
	cin>>num;
	char str[101];
	int cnt=0;
	for(int i=0;i<num;i++){
		cin>>str;
		if(check(str)){
			cnt++;
		}
	}
	printf("%d\n", cnt);
}
