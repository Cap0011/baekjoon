#include <iostream>
using namespace std;
int main(){
	int t;
	int apt[20][20]={0};
	cin>>t;
	int k,n;
	for(int i=0;i<=14;i++){
		for(int j=0;j<=14;j++){
			if(i==0) apt[i][j]=j;
			else if(j!=0) apt[i][j]=apt[i-1][j]+apt[i][j-1];
		}
	}
	for(int i=0;i<t;i++){
		cin>>k>>n;
		printf("%d\n",apt[k][n]);
	}
}
