#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
/*
int solve(int target, int start, int end){
	while(start<=end){
		int mid = (start+end)/2;
		if(v[mid]==target){
			int cnt = 1;
			for(int i=mid-1;;i--){
				if(v[i]==target){
					cnt++;
				}else{
					break;
				}
			}
			for(int i = mid+1;;i++){
				if(v[i]==target){
					cnt++;
				}else{
					break;
				}
			}
			return cnt;
		}
		else if(v[mid]>target){
			return solve(target, start, mid-1);
		}
		else{
			return solve(target, mid+1, end);
		}
	}
	return 0;
}
*/
int main(){
	int n, m, temp;
	vector<int> tar;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		v.push_back(temp);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>temp;
		tar.push_back(temp);
	}
	sort(v.begin(), v.begin()+n);
	
	for(auto x: tar){
		auto upper = upper_bound(v.begin(), v.end(), x);
		auto lower = lower_bound(v.begin(), v.end(), x);
		printf("%d ", upper-lower);
	}
}
