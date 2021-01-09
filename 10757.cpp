#include <iostream>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin>>a>>b;
	int numa;
	int numb;
	int lena = a.length();
	int lenb = b.length();
	bool check=false;
	string result = "";
	if(lena>lenb){
		for(int i=0;i<lena;i++){
			if(i<lenb){
				numa = a[lena-i-1]-'0';
				numb = b[lenb-i-1]-'0';
				result = to_string((numa+numb+check)%10) + result;
				if(numa+numb+check>9) check=true;
				else check = false;
			}else{
				numa = a[lena-i-1]-'0';
				result = to_string((numa+check)%10) + result;
				if(numa+check>9) check = true;
				else check = false;
			}
		}
		if(check) result = "1"+result;
	}else{
		for(int i=0;i<lenb;i++){
			if(i<lena){
				numa = a[lena-i-1]-'0';
				numb = b[lenb-i-1]-'0';
				result = to_string((numa+numb+check)%10) + result;
				if(numa+numb+check>9) check=true;
				else check = false;
			}else{
				numb = b[lenb-i-1]-'0';
				result = to_string((numb+check)%10) + result;
				if(numb+check>9) check = true;
				else check = false;
			}
		}
		if(check) result = "1"+result;
	}
	cout<<result<<'\n';
}
