#include <vector>
#include <iostream>
#include <stack>

using std::vector;
using std::swap;
using std::cout;
using std::endl;
using std::stack;

void quick_sort(vector<int> &vi) {
    stack<int> s_edge;
    s_edge.push(0);
    s_edge.push(vi.size()-1);
    while(!s_edge.empty()) {
        int end=s_edge.top();
        s_edge.pop();
        int beg=s_edge.top();
        s_edge.pop();
        if(end<=beg)
            continue;
         int pivot = vi[beg],i=beg+1,j=end;
        while(i<j) {
            while(i<j && vi[i]<= pivot)
                i++;
            while(i<j && vi[j]>pivot)
                j--;
            if(i>=j)
                break;
            swap(vi[i++],vi[j--]);
        }
        int target=(vi[j]>pivot)?j-1:j;
        swap(vi[beg],vi[target]);
        s_edge.push(beg);
        s_edge.push(target-1);
        s_edge.push(target+1);
        s_edge.push(end);
    }
}
