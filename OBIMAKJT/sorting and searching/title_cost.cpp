#include <iostream>
#include <string>
#include "stdio.h"
using namespace std;

int main(){

    string n;
    string s;

    cin >> s >> n;

    if((float)s.length()< stof(n)) cout << s.length();
    else cout << n;

    return 0;
}