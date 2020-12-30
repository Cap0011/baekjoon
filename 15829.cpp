#include <iostream>
#include <cmath>
using namespace std;
int main(){
	unsigned long long temp;
	unsigned long long sum=0;
	int n;
	cin>>n;
	string buf;
	cin>>buf;
	long long r = 31;
	long long M = 1234567891;
	for(int i=0;i<n;i++){
		temp = buf.at(i)-'a'+1;
		for(int j=0;j<i;j++){
			temp*=r;
			temp%=M;
		}
		sum+=temp;
		sum%=M;
	}
	printf("%lld\n",sum);
}
