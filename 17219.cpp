#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	map<string, string> map;
	string s1, s2;
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		map.insert(make_pair(s1, s2));
	}
	string temp;
	for(int i=0;i<m;i++){	
		cin>>temp;
		cout<<map[temp]<<'\n';
	}
}
