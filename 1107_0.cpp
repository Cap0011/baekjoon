#include <iostream>
#include <cstring>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool btn[10];
	memset(btn, true, sizeof btn);
	int n, m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int temp;
		cin>>temp;
		btn[temp]=false;
	}
}
