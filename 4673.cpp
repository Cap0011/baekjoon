#include <iostream>
#include <cstring>
using namespace std;
int main(){
	bool isSelf[10005];
	memset(isSelf, true, sizeof isSelf);
	for(int i=1;i<10000;i++){
		int val;
		if(i/10==0) val = 2*i;
		else if(i/100==0) val = i+i/10+i%10;
		else if(i/1000==0) val = i+i/100+(i/10)%10+i%10;
		else if(i/10000==0) val = i+i/1000+(i/100)%10+(i/10)%10+i%10;

		if(val<10000) isSelf[val]=false;
	}
	for(int i=1;i<10000;i++){
		if(isSelf[i]) printf("%d\n",i);
	}
}
