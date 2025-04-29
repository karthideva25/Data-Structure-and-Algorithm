#include <iostream>
#include <vector>
using namespace std;
class FenwickTree{
    vector<int> tree;
    int size;
    public:
    FenwickTree(int n,vector<int>& arr){
        size = n+1;
        tree.resize(size,0);
        for(int i=0;i<n;i++){
            update(i + 1, arr[i]);
        }
    }
    // if i'm changing value in 5th index and which index should affect
    // currentvalue + value --> add value in tree
    void update(int index, int value){
        while(index<size){
            tree[index]+=value;
            index += (index & (-index));
        }
    }
    int sum(int index){
        int s = 0;
        while(index>0){
            s += tree[index];
            index = index - (index & (-index));
        }
        return s;
    }
    int rangeSum(int left, int right){
        return sum(right)-sum(left-1);
    }
    int getValue(int index) {
        return sum(index) - sum(index - 1);  // Gets value at a single point
    }
    void replace(int index, int newValue) {
        int currentValue = getValue(index);
        int delta = newValue - currentValue;
        update(index, delta);
    }
};
int main() {
    vector<int> vec = {1,0,2,1,1,3,0,4,2,5,2,2,3,1,0,2};
    FenwickTree ft(vec.size(),vec);
    cout << ft.rangeSum(0,16) << endl;
    ft.replace(16,1);
    cout << ft.rangeSum(0,16) << endl;
    return 0;
}
