#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int two[505]={0};
	int five[505]={0};
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		two[i] = two[i-1];
		five[i] = five[i-1];
		int temp = i;
		while(true){
			if(temp%5!=0) break;
			five[i]++;
			temp/=5;
		}
		while(true){
			if(temp%2!=0) break;
			two[i]++;
			temp/=2;
		}
	}
	cout<<min(two[n], five[n])<<'\n';
}
