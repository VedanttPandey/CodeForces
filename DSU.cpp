struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int leader(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = leader(parent[x]); // path compression
    }

    bool areSame(int x, int y) {
        return leader(x) == leader(y);
    }

    void merge(int x, int y) {
        int l1 = leader(x), l2 = leader(y);
        if (l1 != l2) {
            if (size[l1] < size[l2]) swap(l1, l2);
            parent[l2] = l1;
            size[l1] += size[l2];
        }
    }
};
