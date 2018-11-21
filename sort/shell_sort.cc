#include <vector>
using std::vector;

void shell_sort(vector<int> &vi) {
    int sz=vi.size();
    int h=1;
    while(h<sz/3) {
        h=3*h+1;
    }
    while(h>0) {
        for(int i=0;i<sz;i++) { //依次对序列进行排序
            //各个有序数字序列都是有序的，故此直接从小到大排过即可
            int num=vi[i];
            int j;
            for(j=i-h;j>=0 && vi[j]>num;j-=h) {
                //must be num
                vi[j+h]=vi[j];
            }
            vi[j+h]=num;
        }
        h/=3;
    }
}