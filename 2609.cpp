#include <iostream>
using namespace std;
int main(){
	int n, m;
	cin>>n>>m;
	int max, min;
	max=1;
	for(int i=2;i<=n;i++){
		if(n%i==0&&m%i==0) max=i;
	}
	min=max*(n/max)*(m/max);
	printf("%d\n%d\n",max, min);
}
