#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
bool check[10005]={false};
int bf[10005][2]={};
int d[5];
int dbl(int num){
	return 2*num%10000;
}
int sub(int num){
	if(num==0) return 9999;
	else return num-1;
}
int left(){
	return 1000*d[1]+100*d[2]+10*d[3]+d[0];
}
int right(){
	return 1000*d[3]+100*d[0]+10*d[1]+d[2];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int tar;
		int a, b;
		memset(check, false, sizeof check);
		memset(bf, 0, sizeof bf);
		queue<int> q;
		cin>>a>>b;
		q.push(a);
		check[a]=true;
		while(q.size()>0){
			int tmp = q.front();
			d[0]=tmp/1000;
			d[1]=tmp/100%10;
			d[2]=tmp/10%10;
			d[3]=tmp%10;
			int val = dbl(tmp);
			if(!check[val]){
				check[val]=true;
				q.push(val);
				bf[val][0]=tmp;
				bf[val][1]=1;
				if(val==b) break;
			}
			val = sub(tmp);
			if(!check[val]){
				check[val]=true;
				q.push(val);
				bf[val][0]=tmp;
				bf[val][1]=2;
				if(val==b) break;
			}
			val = left();
			if(!check[val]){
				check[val]=true;
				q.push(val);
				bf[val][0]=tmp;
				bf[val][1]=3;
				if(val==b) break;
			}
			val = right();
			if(!check[val]){
				check[val]=true;
				q.push(val);
				bf[val][0]=tmp;
				bf[val][1]=4;
				if(val==b) break;
			}
			q.pop();
		}
		int tmp=b;
		string str="";
		while(true){
			if(bf[tmp][1]==1) str = 'D'+str;
			else if(bf[tmp][1]==2) str = 'S'+str;
			else if(bf[tmp][1]==3) str = 'L'+str;
			else if(bf[tmp][1]==4) str = 'R'+str;
			tmp = bf[tmp][0];
			if(tmp==a) break;
		}
		cout<<str<<'\n';
	}
	return 0;
}
