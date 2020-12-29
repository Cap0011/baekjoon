#include <iostream>
using namespace std;
int main(){
	unsigned long long temp;
	unsigned long long sum=0;
	int n;
	cin>>n;
	string buf;
	cin>>buf;
	for(int i=0;i<n;i++){
		temp = buf.at(i)-'a'+1;
		for(int j=0;j<i;j++){
			temp*=31;
		}
		sum+=(temp)%1234567891;
		sum%=1234567891;
	}
	printf("%lld\n",sum);
}
