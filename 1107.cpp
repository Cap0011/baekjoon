#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool check[10];
	memset(check, true, sizeof check);

	string n;
	int m;
	vector<int> v;
	cin>>n>>m;
	int temp;
	for(int i=0;i<m;i++){
		cin>>temp;
		check[temp]=false;
	}
	if(m==10){
		cout<<abs(stoi(n)-100)<<'\n';
		return 0;
	}
	int num;
	for(int i=0;i<n.length();i++){
		num = n[i] - '0';
		if(i==0){
			if(check[num]){
				v.push_back(num);
				if(num!=0) v.push_back(0);
			}
			else{
				int low = 100;
				int up = 100;
				for(int j=num-1;j>=num-10;j--){
					if(check[abs(j)]||j==0){
						low=abs(j);
						break;
					}
				}
				for(int j=num+1;j<num+10;j++){
					if(check[j]){
						up=abs(j%10);
						break;
					}
				}
				if(abs(num-low)==abs(up-num)){
					v.push_back(low);
					v.push_back(up);
				}else{
					int result = abs(num-low)<abs(up-num)?low:up%10;
					v.push_back(result);
				}
			}
		}else{
			int lim = v.size();
			for(int t=0;t<lim;t++){
				v[t]*=10;
				if(check[num]) v[t]+=num;
				else{
					int low = 100;
					int up = 100;
					for(int j=num-1;j>num-10;j--){
						if(check[abs(j)]||v[t]==0&&j==0){
							low=j;
							break;
						}
					}
					for(int j=num+1;j<num+10;j++){
						if(check[j%10]){
							up=j;
							break;
						}
					}
					if(abs(num-low)==abs(up-num)){
						if(check[(v[t]+up)/10%10]) v.push_back(v[t]+up);
						if(check[(v[t]+low)/10%10]) v[t]+=low;
					}else{
						int result = abs(num-low)<abs(up-num)?low:up;
						if(check[(v[t]+result)/10%10]) v[t]+=result;
						else{
							if(result!=low) v[t]+=low;
							else v[t]+=up;
						}
					}
				}
			}
		}
	}
	num = stoi(n);
	int min = abs(num-100);
	int len;
	for(auto x:v){
		cout<<x<<' ';
		len = to_string(x).length();
		if(len+abs(x-num)<min) min = len+abs(x-num);
	}
	cout<<min<<'\n';
	return 0;
}
