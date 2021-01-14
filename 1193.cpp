#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x;
	cin>>x;

	int sum=0;
	int index=0;
	for(int i=1;;i++){
		sum+=i;
		index = i;
	}
	int a, b;
	if(x%2==1){
		a=index+1;
		b=1;
		for(int i=0;i<x-sum;i++){
			a--;
			b++;
		}
	}else{
		a = 1;
		b = index+1;
		for(int i=0;i<x-sum;i++){
			a++;
			b--;
		}
	}
	cout<<a<<'/'<<b<<'\n';
	return 0;
}
