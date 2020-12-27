#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int> skey;
	map<int, string> nkey;
	int n, m;
	cin>>n>>m;
	string buf;
	for(int i=1;i<=n;i++){
		cin>>buf;
		nkey[i]=buf;
		skey[buf]=i;
	}
	cout<<nkey.find(1)->second;
	int key;
	for(int i=0;i<m;i++){
		cin>>buf;
		key = stoi(buf);
		if(key<=n) cout<<nkey.find(key)->second<<"\n";
		else cout<<skey.find(buf)->second<<"\n";
	}
}
