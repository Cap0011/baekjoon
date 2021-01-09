#include <iostream>
using namespace std;
int tree[100005] = {};
void swap(int a, int b){
	int temp = tree[a];
	tree[a] = tree[b];
	tree[b] = temp;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int p;
	int size=0;
	for(int i=0;i<n;i++){
		cin>>p;
		if(p!=0){
			tree[++size] = p;
			int tar = size;
			while(abs(tree[tar])<=abs(tree[tar/2])){
				if(tar==1) break;
				if(abs(tree[tar])==abs(tree[tar/2])&&tree[tar]>=tree[tar/2]) break;
				swap(tar, tar/2);
				tar/=2;
			}
		}else{
			if(size){
				cout<<tree[1]<<'\n';
				tree[1] = tree[size];
				tree[size--] = 0;
				if(size<=1) continue;
				int tar = 1;
				while(abs(tree[tar])>=abs(tree[tar*2])||(tar*2+1)<=size&&abs(tree[tar])>=abs(tree[tar*2+1])){
					if(size<tar*2+1||abs(tree[tar*2])<abs(tree[tar*2+1])){
						if(abs(tree[tar])==abs(tree[tar*2])&&tree[tar]<=tree[tar*2]) break;
						tar*=2;
					}else if(abs(tree[tar*2])==abs(tree[tar*2+1])){
						if(tree[tar*2]<tree[tar*2+1]) tar*=2;
						else tar = tar*2+1;
					}
					else{
						if(abs(tree[tar])==abs(tree[tar*2+1])&&tree[tar]<=tree[tar*2+1]) break;
						tar = tar*2+1;
					}
					swap(tar, tar/2);
					if(tar*2>size) break;
				}
			}else{
				cout<<"0\n";
			}
		}
	}
}
