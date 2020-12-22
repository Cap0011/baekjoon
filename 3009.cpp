#include <iostream>
using namespace std;
int main(){
	int x[5];
	int y[5];
	for(int i=0;i<3;i++){
		cin>>x[i]>>y[i];
	}
	int xx;
	int yy;
	if(x[0]==x[1]) xx=x[2];
	else if(x[0]==x[2]) xx=x[1];
	else xx=x[0];

	if(y[0]==y[1]) yy=y[2];
	else if(y[0]==y[2]) yy=y[1];
	else yy=y[0];
	printf("%d %d\n",xx,yy);
}
