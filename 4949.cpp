#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
	int small;
	int big;
	bool type;
	bool check;
	stack<bool> s;
	string buf;
	getline(cin, buf);
	while(buf!="."){
		check=true;
		small=0;
		big=0;
		for(int i=0;i<buf.length();i++){
			if(buf.at(i)=='('){
				s.push(true);
				small++;
			}else if(buf.at(i)==')'){
				if(s.size()==0||!s.top()){
					check=false;
					break;
				}
				else{
					small--;
					s.pop();
				}
			}else if(buf.at(i)=='['){
				s.push(false);
				big++;
			}else if(buf.at(i)==']'){
				if(s.size()==0||s.top()){
					check=false;
					break;
				}
				else{
					big--;
					s.pop();
				}
			}
			if(small<0||big<0){ 
				check=false;
				break;
			}

		}
		if(small!=0||big!=0||!check) printf("no\n");
		else printf("yes\n");
		getline(cin, buf);
	}
}
