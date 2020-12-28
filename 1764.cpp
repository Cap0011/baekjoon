#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> listen;
vector<string> result;
bool check(string buf, int start, int end){
	while(start<=end){
		int mid = (start+end)/2;
		if(listen[mid]==buf) return true;
		else if(listen[mid]<=buf) return check(buf, mid+1, end);
		else return check(buf, 0, mid-1);
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin>>n>>m;
	string buf;
	for(int i=0;i<n;i++){
		cin>>buf;
		listen.push_back(buf);
	}
	sort(listen.begin(),listen.end());
	for(int i=0;i<m;i++){
		cin>>buf;
		if(check(buf, 0, listen.size())) result.push_back(buf);
	}
	sort(result.begin(), result.end());
	cout<<result.size()<<"\n";
	for(auto x:result){
		cout<<x<<"\n";
	}
}
