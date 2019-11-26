#include <iostream>
using namespace std;

int main() {
    int r[3][3];
    short int h = 0,v = 0,a = 0,b = 0;
    for(auto i=0;i<3;++i) {
        cin >> r[i][0] >> r[i][1] >> r[i][2];
    }
    for(auto i=0;i<3;++i) {
        h = 0;
        v = 0;
        a += r[i][i];
        b += r[2-i][i];
        for(auto j=0;j<3;++j) {
            h += r[i][j];
            v += r[j][i];
        }
        if(h != 15 || v != 15) break;
    }
    cout << "It is" << (((a-b)|(b-h)|(h-v) == 0)?" ":" not ") << "a Lo Shu Magic Square \n";
}
