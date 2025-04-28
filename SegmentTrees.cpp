// Karthikeyan
class SegmentTree{
    vector<int> seg;
    SegmentTree(int n){
        seg.resize(4*n+1);
    }
    void build(int index, int low, int high, vector<int>& arr){
        if(low == high){
            seg[index] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);
        seg[index] = min(seg[2*index+1],seg[2*index+2]);
    }
    int query(int index,int low,int high,int l,int r){
        // complete overlap {l,low,high,r}
        if (low>=l && r>=high){
            return seg[index];
        }
        // no overlap {low,high}{l,r} or {l,r}{low,high}
        if(high<=l || r<=low){
            return INT_MAX;
        }
        // partial overlap
        int mid = (low+high)/2;
        int left = query(2*index+1,low,mid,l,r);
        int right = query(2*index+2,mid+1,high,l,r);
        return min(left,right);
    }
    void update(int index,int low,int high,int i,int value){
        if(low == high){
            seg[index] = value;
            return ;
        }
        int mid = (low+high)/2;
        if(i<=mid) update(2*index+1,low,mid,i,value);
        else update(2*index+2,mid+1,high,i,value);
        seg[index] = min(seg[2*index+1],seg[2*index+2]);
    }
};


// Striver
class SGTree {
	vector<int> seg;
public:
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}

	void build(int ind, int low, int high, int arr[]) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}

		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}

	int query(int ind, int low, int high, int l, int r) {
		// no overlap
		// l r low high or low high l r
		if (r < low || high < l) return INT_MAX;

		// complete overlap
		// [l low high r]
		if (low >= l && high <= r) return seg[ind];

		int mid = (low + high) >> 1;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return min(left, right);
	}
	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] = val;
			return;
		}

		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
};
