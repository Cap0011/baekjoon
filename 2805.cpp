#include <iostream>
using namespace std;
long long tree[1000000];
long long n, m;
long long calculate(long long height){
	long long sum = 0;
	for(int i=0;i<n;i++){
		if(tree[i]>height){
			sum+=tree[i]-height;
		}
	}
	return sum;
}
long long search(long long target, long long start, long long end){
	while(start<=end){
		long long mid = (start+end)/2;
		if(calculate(mid)>=target&&calculate(mid+1)<target){
			return mid;
		}else if(calculate(mid)<target){
			return search(target, start, mid-1);
		}else{
			return search(target, mid+1, end);
		}
	}
	return -1;
}
int main(){
	cin>>n>>m;
	long long max=0;
	for(int i=0;i<n;i++){
		cin>>tree[i];
		if(max<tree[i]){
			max = tree[i];
		}
	}
	long long result = search(m, 0, max-1);
	printf("%lld\n", result);
}
