#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int max[1000005]={0};
	int min[1000005]={0};
	int count[1000005]={0};
	int xcnt=0;
	int ncnt=0;
	int t,k;
	cin>>t;
	char c;
	int num;
	for(int i=0;i<t;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>c>>num;
			if(c=='I'){
				max[++xcnt] = num;
				min[++ncnt] = num;
				count[num]++;
				//arrange max
				if(xcnt>1){
					if()
				}
			}else if(c=='D'){
				if(num==1){
				
				}else if(num==-1){
				
				}
			}
		}
	}
}
