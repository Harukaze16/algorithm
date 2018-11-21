//归并排序
#include <vector>

using std::vector;

void binary_sort(vector<int> &vi,int beg,int end);

void binary_sort(vector<int> &vi){
    binary_sort(vi,0,vi.size()-1);
}
void binary_sort(vector<int> &vi,int beg,int end) {
    if(end<=beg)
        return;
    int mid=(end-beg)/2+beg;
    binary_sort(vi,beg,mid);
    binary_sort(vi,mid+1,end);
    
    //合并有序数组
    vector<int> temp(end-beg+1);
    int i=beg,j=mid+1,index=0;
    while(i<=mid && j<=end) {
        if(vi[i]<=vi[j])
            temp[index++] = vi[i++];
        else
            temp[index++] = vi[j++];
    }
    while(i<=mid) 
        temp[index++] = vi[i++];
    while(j<=end)
        temp[index++] = vi[j++];
    
    for(int curi=beg;curi<=end;curi++)
        vi[curi] = temp[curi-beg];
}