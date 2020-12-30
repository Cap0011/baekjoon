#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	vector<int> v;
	vector<int> c;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		v.push_back(temp);
		c.push_back(temp);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end())-v.begin());

	int index;
	for(auto x:c){
		index = lower_bound(v.begin(), v.end(), x) - v.begin();
		cout<<index<<' ';
	}
	return 0;
}
