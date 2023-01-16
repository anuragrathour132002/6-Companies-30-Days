int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost = 0) {
    if (needs < 0)
        return INT_MAX;

    int m = inner_product(needs.begin(), needs.end(), price.begin(), cost);

    for (auto &offer : special) {
        if (cost + offer.back() >= m) // pruning
            continue;
        needs -= offer;
        m = min(m, shoppingOffers(price, special, needs, cost + offer.back()));
        needs += offer;
    }

    return m;
}