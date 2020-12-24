#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	cin>>n;
	int cnt=0;
	string buf;
	int result;
		for(int i=666;;i++){
			buf = to_string(i);
			int count=0;
			for(int j=0;j<=buf.length()-3;j++){
				if(buf.substr(j,3)=="666"){
					result=i;
					cnt++;
					break;
				}	
			}
			if(cnt==n) break;
		}
	printf("%d\n",result);
}
