#include <iostream>
using namespace std;
int main(){
	int a,b,c;
	bool check;
	cin>>a;
	while(a!=0){
		check=false;
		cin>>b>>c;
		if(a>b&&a>c){
			if(a*a==b*b+c*c) check=true;
		}else if(b>a&&b>c){
			if(b*b==a*a+c*c) check=true;
		}else if(c>a&&c>b){
			if(c*c==a*a+b*b) check=true;
		}

		if(check) printf("right\n");
		else printf("wrong\n");
		cin>>a;
	}
}
