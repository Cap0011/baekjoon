#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
bool check[10];
string n;
vector<string> v;
int find_down(int num){
	for(int i=num-1;i>=0;i--){
		if(check[i]) return i;
	}
	return 999;
}
int find_up(int num){
	for(int i=num+1;i<10;i++){
		if(check[i]) return i;
	}
	return 999;
}
int fin_down(int num){
	for(int i=num-1;i>num-10;i--){
		if(i<0){
			if(check[i+10]) return i;
		}else{
			if(check[i]) return i;
		}
	}
	return 999;
}
int fin_up(int num){
	for(int i=num+1;i<num+10;i++){
		if(i>9){
			if(check[i-10]) return i;
		}else{
			if(check[i]) return i;
		}
	}
	return 999;
}
bool isPoss(int num){
	for(int i=0;i<to_string(num).length();i++){
		if(!check[num%10]) return false;
		num/=10;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(check, true, sizeof check);
	int m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int temp;
		cin>>temp;
		check[temp]=false;
	}
	if(m==10){
		cout<<abs(100-stoi(n))<<'\n';
		return 0;
	}
	int num=n[0]-'0';
	if(check[num]){
		v.push_back(to_string(num));
		if(num!=0) v.push_back("0");
	}else{
		int up = find_up(num);
		int down = find_down(num);
		if(abs(up-num)==abs(num-down)){
			v.push_back(to_string(down));
			v.push_back(to_string(up));
		}
		else if(abs(up-num)>abs(num-down)) v.push_back(to_string(down));
		else v.push_back(to_string(up));
		if(up!=0&&down!=0) v.push_back("0");
	}
	for(int i=1;i<n.length()-1;i++){
		num = n[i] - '0';
		int up = find_up(num);
		int down = find_down(num);
		int lim = v.size();
		for(int j=0;j<lim;j++){
			if(check[num]){
				v[j]+=to_string(num);
			}else{
			if(abs(up-num)==abs(num-down)){
				v.push_back(v[j]+to_string(down));
				v[j]+=to_string(up);
			}
			else if(abs(up-num)>abs(num-down)) v[j]+=to_string(down);
			else v[j]+=to_string(up);
			}
		}
	}
	num = n[n.length()-1]-'0';
	int f_up = fin_up(num);
	int f_down = fin_down(num);
	int up = find_up(num);
	int down = find_down(num);
	int lim = v.size();
	for(int i=0;i<lim;i++){
		if(check[num]) v[i]+=to_string(num);
		else{
			if(!isPoss(stoi(v[i])*10+f_up)) f_up=up;
			if(!isPoss(stoi(v[i])*10+f_down)) f_down=down;
			if(abs(f_up-num)==abs(num-f_down)){
				v.push_back(to_string(stoi(v[i])*10+f_down));
				v.push_back(to_string(stoi(v[i])*10+f_up));
			}
			else if(abs(f_up-num)>abs(num-f_down)) v[i]=to_string(stoi(v[i])*10+f_down);
			else v[i]=to_string(stoi(v[i])*10+f_up);
		}
	}
	/*
	for(int j=0;j<v.size();j++){
		cout<<v[j]<<' ';
	}
	cout<<'\n';
	*/
	int tar = stoi(n);
	int min = abs(tar-100);
	for(int i=0;i<v.size();i++){
		int temp = stoi(v[i]);
		if(min>to_string(temp).length()+abs(temp-tar)) min=to_string(temp).length()+abs(temp-tar);
	}
	cout<<min<<'\n';
	return 0;
}
