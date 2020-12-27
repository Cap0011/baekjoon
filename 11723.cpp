#include <iostream>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	string buf;
	int x;
	int k=0;
	for(int i=0;i<n;i++){
		cin>>buf;
		if(buf=="add"){
			cin>>x;
			if(~(k&(1<<x))) k|=(1<<x);
		}else if(buf=="remove"){
			cin>>x;
			if(k&(1<<x)) k&=(~(1<<x));
		}else if(buf=="check"){
			cin>>x;
			if(k&(1<<x)) puts("1");
			else puts("0");
		}else if(buf=="toggle"){
			cin>>x;
			k=k^(1<<x);
		}else if(buf=="all"){
			k|=(1<<21)-1;
		}else if(buf=="empty"){
			k=0;
		}
	}
}
