#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
	
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i=0; i<n; i++) cin >> x[i];
	sort(x.begin(), x.end());
 
	long long sum = 0, ind = -1;
	long long i;
	for(i=1; i>0; i++){
		
		if(ind == n-1 && i>sum) break;
		
		if(i>sum){
			ind++, sum+= (long long)x[ind];
		}
 
		
		
		
		if(x[ind] > i) break;
		else i=sum;
		
	}
 
	cout << i;
	
    return (0);
}