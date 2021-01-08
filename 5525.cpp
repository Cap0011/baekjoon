#include <iostream>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M; 
	string S;
	cin>>N>>M>>S;
	int cnt=0;
	int result=0;
	bool check=false;
	bool toggle=false;
	for(int i=0;i<M;i++){
		if(check){
			if(toggle&&S[i]=='I'){
				if(cnt==N){
					result++;
					cnt--;
				}
				toggle=!toggle;
			}else if(!toggle&&S[i]=='O'){
				toggle=!toggle;
				cnt++;
			}else if(S[i]=='I'){
				cnt = 0;
				toggle = false;
				check = true;
			}else{
				check = false;
			}
		}else if(S[i]=='I'){ 
			cnt = 0;
			toggle = false;
			check = true;
		}
	}
	cout<<result<<'\n';
}
