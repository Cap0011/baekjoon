#include <iostream>
using namespace std;
int main(){
	int index=0;
	int board[100005]={0};
	int k;
	cin>>k;
	int temp;
	for(int i=0;i<k;i++){
		cin>>temp;
		if(!temp)board[--index]=0;
		else{
			board[index]=temp;
			index++;
		}
	}
	int sum=0;
	for(int i=0;i<index;i++){
		sum+=board[i];
	}
	printf("%d\n",sum);
}
