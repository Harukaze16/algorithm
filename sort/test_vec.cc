#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> vi;
    cout<<vi.size()<<' '<<vi.capacity()<<endl;
    for(int i=0;i<100;i++) {
        vi.push_back(i);
        cout<<vi.size()<<' '<<vi.capacity()<<endl;
    }
    return 0;
}
