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
		nkey.insert(make_pair(i,buf));
		skey.insert(make_pair(buf,i));
	}
	int key;
	for(int i=0;i<m;i++){
		cin>>buf;
		if(buf.at(0)>='0'&&buf.at(0)<='9'){
			key = stoi(buf);
			cout<<nkey[key]<<"\n";
		}
		else cout<<skey[buf]<<"\n";
	}
}
