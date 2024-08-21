#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
	
	int n;
	cin >> n;
	vector<int> x(n);
 
	cin >> x[0];
	long long sum = x[0], best = x[0];
	for(int i=1; i<n; i++){
		cin >> x[i];
		sum = max((long long)x[i], sum + (long long)x[i]);
		best = max(best, sum);
		
	}
 
	cout << best;
	
}