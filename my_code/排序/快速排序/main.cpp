#include <iostream>


using namespace std;

int quicksort(int v[], int left, int right)
{
        if(left < right){
                int key = v[left];
                int low = left;
                int high = right;
                while(low < high){
                        while(low < high && v[high] > key){
                                high--;
                        }
                        v[low] = v[high];
                        while(low < high && v[low] < key){
                                low++;
                        }
                        v[high] = v[low];
                }
                v[low] = key;
                quicksort(v,left,low-1);
                quicksort(v,low+1,right);
        }
}
int main()
{
    int buf[6]={6,2,7,3,8,9};
    int i;
    quicksort(buf,0,5);
    for(i=0;i<=5;i++)
        cout<<buf[i]<<" ";
}
