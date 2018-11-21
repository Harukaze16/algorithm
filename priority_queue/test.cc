#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vi;
    vi.push_back(13);
    vi.push_back(15);
    vector<int> vi2(vi);
    return 0;
}
