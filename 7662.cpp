#include <iostream>
#include <queue>
#include <functional>
#include <set>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	multiset<int> set;
	multiset<int>::iterator it;
	int t,k;
	cin>>t;
	char c;
	int num;
	for(int i=0;i<t;i++){
		cin>>k;
		set.clear();
		for(int j=0;j<k;j++){
			cin>>c>>num;
			if(c=='I'){
				set.insert(num);
			}else if(c=='D'){
				if(!set.empty()){
					if(num==1){
						auto tt = set.end();
						tt--;
						set.erase(tt);
					}else if(num==-1){
						set.erase(set.begin());
					}
				}
			}
		}
		if(set.empty()) cout<<"EMPTY"<<'\n';
		else{
			auto tt = set.end();
			tt--;
			cout<<(*tt)<<' '<<(*set.begin())<<'\n';
		}
	}
}
