#include <iostream>
using namespace std;
int main(){
	int x, y, w, h;
	cin>>x>>y>>w>>h;
	int min = h-y;
	if(min>x) min=x;
	if(min>w-x) min=w-x;
	if(min>y) min=y;
	printf("%d\n",min);
}
