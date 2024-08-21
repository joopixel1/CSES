#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> li(n);

    for (int i=0; i<li.size(); i++) li[i] = i+1;
    
    for(int i=1; li.size()>0; i = i+2){
        cout << li[i] << " ";
        li.erase(li.begin()+i);
    }


    return (0);
}

10
3 47
5 11
1 70
2 100
2 41
2 66
5 80
4 84
5 81
5 40