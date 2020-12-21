#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(i>=1&&i<=99) cnt++;
		else{
			int a = i/100;
			int b = (i/10)%10;
			int c = i%10;
			if(a-b==b-c) cnt++;
		}
	}
	printf("%d\n",cnt);
}
