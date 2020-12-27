#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Point{
public:
		int x;
		int y;
		void print(){
			printf("%d %d\n",this->x, this->y);
		}
};
bool cmp(Point &p1, Point &p2){
	if(p1.y!=p2.y) return p1.y<p2.y;
	else return p1.x<p2.x;
}
int main(){
	int n;
	vector<Point> v;
	cin>>n;
	int x, y;
	for(int i=0; i<n ;i++){
		cin>>x>>y;
		Point temp;
		temp.x = x;
		temp.y = y;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),cmp);
	for(auto x:v){
		x.print();
	}
}
