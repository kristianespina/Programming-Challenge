#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    // Get Input
    size_t num=0;
    int peak = 0;
    cin >> num;
    int data[num];
    int diff[num];

    int difference = 0;
    int qdiff=0;
    for(auto i = 0; i < num; ++i) {
        cin >> data[i];
        peak = ((data[i])>peak)?data[i]:peak;
        if (i>0) {
            qdiff = abs(data[i] - data[i-1]);
            difference += (qdiff>0)?qdiff-1:qdiff;
        }

        diff[i] = (i>0)?data[i] - data[i-1]:0; 
    }

    // Create Base Graph
    string graph[peak+1];
    for(auto i = 0; i < peak+1; ++i) for (auto j = 0; j < num+difference; ++j) graph[i].append((i!=peak)?" ":"=");
    
    // Add Details
    int base = 0;
    for(auto i = 0; i < num; ++i) {
        if(diff[i] != 0) {
            for(auto j = 0; j<abs(diff[i])-1;j++) {
                if(diff[i] > 0)
                    graph[peak-data[i-1]-1-j].replace(base+i+j,1,"/");
                else
                    graph[peak-data[i-1]+j+1].replace(base+i+j,1,"\\");
            }
            base += abs(diff[i])-1;
        }
        graph[peak - data[i]].replace(i+base,1,".");
    }
    
    // Print Graph
    for (auto i = 0; i < peak+1; ++i) cout << graph[i] << "\n";
    return 0;
}
