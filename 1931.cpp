#include <iostream>
#include <algorithm>
using namespace std;
struct Meeting{
	int start;
	int end;
};
bool cmp(const Meeting &m1, const Meeting &m2){
	if(m1.end<m2.end){
		return true;
	}else if(m1.end==m2.end){
		return m1.start<m2.start;
	}else{
		return false;
	}
}
int main(){
	Meeting m[100000];
	int n;
	cin>>n; //회의의 수
	for(int i=0;i<n;i++){
		cin>>m[i].start>>m[i].end;
	}
	sort(m, m+n, cmp);

	int cnt=0;
	int endtime=0;

	for(int i=0;i<n;i++){
		if(m[i].start>=endtime){
			endtime=m[i].end;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	
}
