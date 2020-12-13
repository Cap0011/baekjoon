#include <iostream>
#include <vector>
using namespace std;

int n;
int count = 0;
vector<int> v;
bool board[15][15] = {false};

bool check(int target){
	for(auto x:v){
		if(x==target){
			return false;
		}
	}
	for(int i=1;i<=v.size();i++){
		for(int j=1; j<=n ; j++){
			if(board[i][j]==true){
				if((v.size()+1-i)==(target-j)||(v.size()+1-i)==(j-target)){
					return false;
				}
				break;
			}
		}
	}
	return true;
}
void solve(){
	if(v.size()==n){
		count++;
		return;
	}else{
		for(int i=1;i<=n;i++){
			if(check(i)){
				v.push_back(i);
				board[v.size()][i]=true;
				solve();
				board[v.size()][i]=false;
				v.pop_back();
			}
		}
	}
}
int main(){
	cin>>n;
	solve();
	printf("%d\n", count);
	return 0;
}
