#include <iostream>
using namespace std;
bool paper[130][130]={false};
int white=0;
int blue=0;
void calculate(int x, int y,int n){
	if(n==1){
		if(paper[x][y]) blue++;
		else white++;
		return;
	}
	bool yes=false;
	bool no=false;
	for(int i=x;i<x+n;i++){
		for(int j=y;j<y+n;j++){
			if(paper[i][j]) yes=true;
			else no=true;
		}
	}
	if(!yes) white++;
	else if(!no) blue++;
	else{
		calculate(x, y, n/2);
		calculate(x, y+n/2, n/2);
		calculate(x+n/2, y, n/2);
		calculate(x+n/2, y+n/2, n/2);
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	bool temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>temp;
			paper[i][j]=temp;
		}
	}
	calculate(0,0,n);
	cout<<white<<"\n"<<blue<<"\n";
	return 0;
}
