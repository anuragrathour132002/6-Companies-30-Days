class StockPrice {
public:
    map<int, int> rec;
    multiset<int> count;

    void update(int t, int p) {
        if (rec.find(t) != rec.end())
            count.erase(count.find(rec[t]));
        rec[t] = p;
        count.insert(p);
    }

    int current() {
        return rec.rbegin()->second;
    }

    int maximum() {
        return *count.rbegin();
    }

    int minimum() {
        return *count.begin();
    }
};