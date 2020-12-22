#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string s1, string s2){
	if(s1.length() < s2.length()) return true;
	else if(s1.length()==s2.length()) return s1<s2;
	else return false;
}
int main(){
	int n;
	cin>>n;
	vector<string> v;
	string buf;
	for(int i=0;i<n;i++){
		cin>>buf;
		v.push_back(buf);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n-1;i++){
		if(v[i]==v[i+1]) continue;
		else cout<<v[i]<<endl;
	}
	cout<<v[n-1]<<endl;
}
