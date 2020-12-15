#include <iostream>
using namespace std;
long long lan[10000];
long long k, n;
long long calculate(long long length){
	long long sum = 0;
	for(int i=0;i<k;i++){
		if(lan[i]>=length){
			sum += lan[i]/length;
		}
	}
	return sum;
}
long long search(long long target, long long start, long long end){
	while(start<=end){
		long long mid = (start+end)/2;
		long long val = calculate(mid);
		if(val>=target&&calculate(mid+1)<target){
			return mid;
		}else if(val<target){
			return search(target,start,mid-1);
		}else{
			return search(target,mid+1, end);
		}
	}
	return -1;
}
int main(){
	cin>>k>>n;
	long long max=0;
	for(int i=0;i<k;i++){
		cin>>lan[i];
		if(max<lan[i]){
			max = lan[i];
		}
	}
	long long result = search(n,1,max);
	printf("%lld\n",result);
}
