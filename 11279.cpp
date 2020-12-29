#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int temp;
	int cnt=0;
	int tree[100005]={0};
	for(int i=0;i<n;i++){
		cin>>temp;
		if(!temp){
			if(!cnt) cout<<"0\n";
			else{
				cout<<tree[1]<<"\n";
				tree[1] = tree[cnt--];
				int ta = 1;
				while(tree[ta]<tree[ta*2]||tree[ta]<tree[ta*2+1]){
					if(ta*2>cnt) break;
					ta = (tree[ta*2]>=tree[ta*2+1]) ? ta*2 : ta*2+1;
					tree[ta/2] = tree[ta];
					tree[ta] = tree[cnt+1];
				}
			}
		}else{
			tree[++cnt] = temp;
			int ta = cnt;
			int buf;
			while(tree[ta]>tree[ta/2]){
				if(ta==1) break;
				buf = tree[ta];
				tree[ta] = tree[ta/2];
				ta/=2;
				tree[ta] = buf;
			}
		}
	}
	return 0;
}
