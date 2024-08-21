#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
 
int main(){
	
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i=0; i<n; i++) cin >> x[i];
	multiset<int> d;;
 
 
	for(auto a: x){
		
		auto k = d.upper_bound(a);
		
		if(k != d.end()) d.erase(k);
		
		d.insert(a);
		
	}
 
	cout << d.size();
	
}
