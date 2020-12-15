#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char buf[101]={};
	cin>>buf;
	int cnt=0;
	for(int i=0;i<strlen(buf);i++){
		if(buf[i]=='d'){
			if(buf[i+1]=='z'&&buf[i+2]=='='){
				i+=2;
			}else if(buf[i+1]=='-'){
				i++;
			}
		}else if(buf[i]=='c'){
			if(buf[i+1]=='='||buf[i+1]=='-'){
				i++;
			}
		}else if(buf[i]=='l'&&buf[i+1]=='j'){
			i++;
		}else if(buf[i]=='n'&&buf[i+1]=='j'){
			i++;
		}else if(buf[i]=='s'&&buf[i+1]=='='){
			i++;
		}else if(buf[i]=='z'&&buf[i+1]=='='){
			i++;
		}
		cnt++;
	}
	printf("%d\n", cnt);
}
