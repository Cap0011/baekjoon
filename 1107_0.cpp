#include <iostream>
#include <cstring>
#include <string>
using namespace std;
bool btn[10];
int n, m;
int check(int num){
	string tmp = to_string(num);
	for(int i=0;i<tmp.length();i++){
		if(!btn[tmp[i]-'0']) return false;
	}
	return true;
}
int cal(int num){
	return to_string(num).length()+abs(num-n);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(btn, true, sizeof btn);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int temp;
		cin>>temp;
		btn[temp]=false;
	}
	if(m==10){
		cout<<abs(100-n)<<'\n';
		return 0;
	}
	int min = abs(100-n);
	for(int i=0;i<=n*2+100;i++){
		if(check(i)&&cal(i)<min) min = cal(i);
	}
	cout<<min<<'\n';
	return 0;
}
