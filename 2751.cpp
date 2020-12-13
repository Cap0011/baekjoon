#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, temp;
	vector<int> v;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.begin()+n);
	for(auto x:v){
		printf("%d\n",x);
	}
}
