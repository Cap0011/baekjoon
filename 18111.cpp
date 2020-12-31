#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, B;
	cin>>N>>M>>B;
	int area[505][505]={0};
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>area[i][j];
		}
	}
	int time, max;
	int min=-1;
	int remove, add;
	for(int h=0;h<=256;h++){
		remove = 0;
		add = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				int xi = area[i][j] - h;
				if(xi>0) remove+=xi;
				else add-=xi;
			}
		}
		if(remove+B>=add){
			time = remove*2 + add;
			if(min==-1||min>=time){
				min = time;
				max = h;
			}
		}
	}
	cout<<min<<' '<<max<<'\n';
}
