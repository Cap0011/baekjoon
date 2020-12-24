#include <iostream>
#include <vector>
using namespace std;
int table[1005];
void move(int index, int num){
	for(int i=index;i<num;i++){
		table[i]=table[i+1];
	}
	return;
}
int main(){
	int n, k;
	vector<int> v;
	cin>>n>>k;
	int cnt=0;
	int index=0;
	for(int i=0;i<n;i++){
		table[i]=i+1;
	}
	while(n>0){
		index = (index+k-1)%(n--);
		v.push_back(table[index]);
		move(index,n);
	}
	printf("<");
	for(auto x:v){
		if(x==v.back()) printf("%d>\n",x);
		else printf("%d, ",x);
	}
}
