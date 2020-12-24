#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main(){
	int n;
	cin>>n;
	string buf;
	deque<int> deque;
	for(int i=0;i<n;i++){
		cin>>buf;
		if(buf=="push_front"){
			int temp;
			cin>>temp;
			deque.push_front(temp);
		}else if(buf=="push_back"){
			int temp;
			cin>>temp;
			deque.push_back(temp);
		}else if(buf=="pop_front"){
			if(deque.size()==0) printf("-1\n");
			else{ 
				printf("%d\n",deque.front());
				deque.pop_front();
			}
		}else if(buf=="pop_back"){
			if(deque.size()==0) printf("-1\n");
			else{
				printf("%d\n",deque.back());
				deque.pop_back();
			}
		}else if(buf=="size"){
			printf("%ld\n",deque.size());
		}else if(buf=="empty"){
			if(deque.empty()) printf("1\n");
			else printf("0\n");
		}else if(buf=="front"){
			if(deque.empty()) printf("-1\n");
			else printf("%d\n",deque.front());
		}else if(buf=="back"){
			if(deque.empty()) printf("-1\n");
			else printf("%d\n",deque.back());
		}
	}
}
