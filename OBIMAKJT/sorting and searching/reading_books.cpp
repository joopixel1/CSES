#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long sum=0;
	int n,tmp,ma=0;
	cin>>n;

	for (int i=0;i<n;i++){
		cin>>tmp;
		ma=max(ma,tmp);
		sum+=tmp;
	}
    
	ma*=2;//m<<=1;
	if (n==1 || sum<ma) sum=ma;
	cout<<sum<<endl;
	return (0);
}