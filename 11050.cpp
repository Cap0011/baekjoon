#include <iostream>
using namespace std;
int main(){
	int n, k;
	cin>>n>>k;
	int top=1;
	int bottom=1;
	for(int i=n;i>=n-k+1;i--){
		top*=i;
	}
	for(int i=1;i<=k;i++){
		bottom*=i;
	}
	printf("%d\n",top/bottom);
}
