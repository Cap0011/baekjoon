#include <iostream>
#include <vector>
using namespace std;

int main(){
	char buf[51];
	cin>>buf;
	
	vector<int> num;
	vector<char> op;
	int sum, temp;
	sum=0;

	op.push_back('+');
	for(int i=0;i<51;i++){
		if(buf[i]=='+'||buf[i]=='-'){
			op.push_back(buf[i]);
			num.push_back(sum);
			sum=0;
		}else if((buf[i]>='0')&&(buf[i]<='9')){
			sum = sum*10 + buf[i]-'0';
		}else{
			num.push_back(sum);
			break;
		}
	}
	int cnt=0;
	int result=0;
	bool check=false;
	for(auto x:num){
		if(check){
			if(op[cnt]=='-'){
				result-=x;
			}else{
				result-=x;
			}
		}else{
			if(op[cnt]=='-'){
				result-=x;
				check = true;
			}else{
				result+=x;
			}
		}
		cnt++;
	}
	printf("%d\n", result);

}
