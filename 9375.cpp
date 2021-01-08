#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, n;
	string name, type;
	cin>>t;
	for(int i=0;i<t;i++){
		string str[35] = {};
		int cnt[35]= {0};
		cin>>n;
		int count = 0;
		for(int j=0;j<n;j++){
			cin>>name>>type;
			int check = -1;
			for(int k = 0;k<count;k++){
				if(str[k]==type){
					check = k;
					break;
				}
			}
			if(check>=0) cnt[check]++;
			else{
				str[count] = type;
				cnt[count++]++;
			}
		}
		int result=1;
		for(int j=0;j<count;j++){
			result*=(cnt[j]+1);
		}
		result-=1;
		cout<<result<<'\n';
	}
}
