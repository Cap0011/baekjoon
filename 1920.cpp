#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<int> tar;

bool binary_search(int target, int start, int end){
	while(start<=end){
		int mid = (end+start)/2;
		if(v[mid]==target) return true;
		else{
			if(v[mid]>target){
				return binary_search(target, start, mid-1);
			}else{
				return binary_search(target, mid+1, end);
			}
		}
	}
	return false;
}
int main(){
	int n, m, temp;
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
	bool result;
	for(auto x:tar){
		result = binary_search(x, 0, n-1);
		printf("%d\n", result);
	}
}
