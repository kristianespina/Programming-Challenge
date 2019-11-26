#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main() {
    string w;
    cin >> w;
    int k=w.length(), l = int(ceil((w.length()+1)/2)),z=0;
    for(auto i=0;i<l;++i) for(auto j=0;j<k/2+1;++j) ((j<l-i-1)?cout<< " ":(j==k/2)?cout << "\n":cout<< w[z++] << " ");
    return 0;
}
