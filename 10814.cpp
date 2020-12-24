#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Member{
	public:
			int age;
			string name;
};
bool cmp(const Member &m1, const Member &m2){
	if(m1.age!=m2.age) return m1.age<m2.age;
	else return false;
}
int main(){
	int n;
	cin>>n;
	vector<Member> v;
	for(int i=0;i<n;i++){
		Member temp;
		string wht;
		cin>>temp.age>>temp.name;
		v.push_back(temp);
	}
	stable_sort(v.begin(), v.end(), cmp);
	for(auto x:v){
		cout<<x.age<<" "<<x.name<<"\n";
	}
}
