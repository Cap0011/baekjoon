#include <iostream>
using namespace std;
int cnt=0;

void hanoi(int num, int from, int to, int other){
	if(num==1){
		cnt++;
		return;
	}else{
		hanoi(num-1, from, other, to);
		hanoi(1, from, to, other);
		hanoi(num-1, other, to, from);
	}
}
void hanoi_print(int num, int from, int to, int other){
	if(num==1){
		printf("%d %d\n",from, to);
		return;
	}else{
		hanoi_print(num-1, from, other, to);
		hanoi_print(1, from, to, other);
		hanoi_print(num-1, other, to, from);
	}
}
int main(){
	int n;
	cin>>n;
	hanoi(n,1,3,2);
	printf("%d\n",cnt);
	hanoi_print(n, 1, 3, 2);
}
