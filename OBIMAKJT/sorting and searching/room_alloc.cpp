#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
 
#define fi get<0>
#define se get<1>
#define th get<2>
 
using namespace std;
 
int find(vector< tuple<int, int, int> > li, tuple<int, int, int> z);
 
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector< tuple<int, int, int> > p;
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a, cin >> b;
		tuple<int, int, int> c = make_tuple(a, b, i);
		p.push_back(c);
	}
	sort(p.begin(), p.end());
	
	
	vector<int> x(n);
	vector< tuple<int, int, int> > s;
	s.push_back(p[0]), x[ th(p[0]) ] = 1;
	
	
	 for(int i=1; i<n; i++){
        int j;
        
        if((j = find(s, p[i])) > -1) s[j] = p[i];
        else s.push_back(p[i]);
    
        x[ th(p[i]) ] = (j>-1) ? j+1 : s.size();
    
    }    
 
    cout << s.size() << endl;
    for(int i=0; i<n; i++) cout << x[i] << " ";
    cout << endl;
    
    return (0);
}
 
int find(vector< tuple<int, int, int> > li, tuple<int, int, int> z){
    
    int i=0;
    for(auto f: li){
        
      if ( !(fi(z)>=fi(f) && fi(z)<=se(f)) 
        && !(se(z)>=fi(f) && se(z)<=se(f)) ){
            return i;
      }
      i++;
    }
    
    return -1;
}