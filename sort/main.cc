#include <iostream>
#include <vector>
#include <random>

#include "header.h"

using namespace std; 

int main() {
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0,50);
    e.seed(10);
    for(int i=0;i<50;i++) {
        vector<int> vi;
        for(int j=0;j<50;j++)
            vi.push_back(u(e));
        cout<<"before sort\n";
        for(int i=0;i<50;i++)
            cout<<vi[i]<<" ";
        cout<<endl;
        
        shell_sort(vi);
        cout<<"after sort\n";
        for(int i=0;i<50;i++)
            cout<<vi[i]<<" ";
        cout<<endl;
    }
}
