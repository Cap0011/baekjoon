#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	int n, temp;
	int cnt[10000]={0};
	int max=0;
	double sum=0;
	vector<int> v;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		v.push_back(temp);
		cnt[5000+temp]++;
		sum+=temp;
	}
	sort(v.begin(), v.end());
	for(int i=-4000;i<=4000;i++){
		if(max<cnt[5000+i]) max=cnt[5000+i];
	}
	int num=0;
	int third;
	for(int i=-4000;i<=4000;i++){
		if(max==cnt[5000+i]){
			third=i;
			if(++num==2) break;
		}
	}
	sum/=(double)n;
	int first=floor(sum+0.5);
	int second = (n%2==0)?(v[n/2]+v[n/2-1])/2:v[n/2];
	int fourth = v.back()-v.front();
	printf("%d\n%d\n%d\n%d\n", first, second, third, fourth);
}
