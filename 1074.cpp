#include <iostream>
#include <cmath>
using namespace std;
bool done = false;
int N, r, c;
long long cnt=0;
long long search(int n, int x, int y){
	if(done) return 0;
	if(n==1){
		if(x==r&&y==c){
			done = true;
			return cnt;
		}
		if(x==r&&y+1==c){
			done = true;
			return cnt+1;
		}
		if(x+1==r&&y==c){
			done = true;
			return cnt+2;
		}
		if(x+1==r&&y+1==c){
			done = true;
			return cnt+3;
		}
		return 0;
	}
	int alt = (int)pow(2,n-1);
	if(r<x+alt&&c<y+alt){
		return search(n-1, x, y);
	}
	else if(r<x+alt&&c>=y+alt){ 
		cnt+=(int)pow(alt,2);
		return search(n-1, x, y+alt);
	}
	else if(r>=x+alt && c<y+alt){ 
		cnt+=(int)pow(alt,2)*2;
		return search(n-1, x+alt, y);
	}
	else{ 
		cnt+=(int)pow(alt,2)*3;
		return search(n-1, x+alt, y+alt);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N>>r>>c;

	long long result = search(N,0,0);
	cout<<result<<'\n';

	return 0;
}
