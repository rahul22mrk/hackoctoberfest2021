struct SegmentTree {
    /********************* CHANGE DEF AND MERGING STEP *************************/
    int n;
    vector<int> seg;
    int def = 0;

    // l, r are the query points
    // lo, hi are the array ranges
    // in is the index in the segment tree
    // in == 0 refers to the root node
    void build(int n) {
        this -> n = n;
        seg.assign(4 * n, def);
    }

    void build(vector<int> nums) {
        this -> n = nums.size();
        seg.assign(4 * n, def);
        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i];
        }
        build(arr, 0, 0, n - 1);
    }

    void build(int n, int* arr) {
        this -> n = n;
        seg.assign(4 * n, def);
        build(arr, 0, 0, n - 1);
    }

    void build(int* arr, int in, int lo, int hi) {
        // Reaching a leaf node
        if (lo == hi) {
            seg[in] = arr[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        build(arr, 2 * in + 1, lo, mid);
        build(arr, 2 * in + 2, mid + 1, hi);

        // Merging the two children
        seg[in] = seg[2 * in + 1] + seg[2 * in + 2];
        //seg[in] = max(seg[2 * in + 1], seg[2 * in + 2]);
    }


    // Finding the index in the segment tree which corresponds to pos in array
    void update(int in, int lo, int hi, int pos, int val) {
        if (lo == hi) {
            seg[in] = val;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if (pos <= mid) {
            update(2 * in + 1, lo, mid, pos, val);
        } else {
            update(2 * in + 2, mid + 1, hi, pos, val);
        }

        seg[in] = seg[2 * in + 1] + seg[2 * in + 2];
        //seg[in] = max(seg[2 * in + 1], seg[2 * in + 2]);
    }


    // call this method as query(0, 0, n-1, l, r);
    int query(int in, int lo, int hi, int l, int r) {
        // segment completely outside range
        if (lo > r || hi < l)
            return def;

        // segment completely inside range
        if (l <= lo && r >= hi)
            return seg[in];

        int mid = lo + (hi - lo) / 2;

        int left = query(2 * in + 1, lo, mid, l, r);
        int right = query(2 * in + 2, mid + 1, hi, l, r);

        return left + right;
        //return max(left, right);
    }

    // query for arr[l..r]
    int query(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }

    void update(int pos, int val) {
        update(0, 0, n - 1, pos, val);
    }
};