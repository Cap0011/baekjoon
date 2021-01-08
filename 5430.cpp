#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int arr[100005]={0};
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string p;
		int n;
		string num;
		cin>>p>>n>>num;
		int temp=0;
		int index = 0;
		for(int j=1;j<num.length()-1;j++){
			if(num[j]==','){
				arr[index] = temp;
				temp=0;
				index++;
			}
			else{
				temp*=10;
				temp+=num[j]-'0';
			}
		}
		arr[index] = temp;
		bool isReverse = false;
		bool check = true;
		int start = 0;
		int end = n-1;
		for(int j=0;j<p.length();j++){
			if(p[j]=='D'){
				if(n==0){
					check = false;
					break;
				}
				n--;
				if(!isReverse) start++;
				else end--;	
			}else{	
				isReverse = !isReverse;
			}
		}
		if(check){
			if(n==0) cout<<"[]\n";
			else if(isReverse){
				cout<<'[';
				for(int j=end;j>start;j--){
					cout<<arr[j]<<',';
				}
				cout<<arr[start]<<']'<<'\n';
			}else{
				cout<<'[';
				for(int j=start;j<end;j++){
					cout<<arr[j]<<',';
				}
				cout<<arr[end]<<']'<<'\n';
			}
		}else cout<<"error\n";
	}
}
