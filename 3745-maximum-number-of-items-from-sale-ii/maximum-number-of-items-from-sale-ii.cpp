class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);
        int minPrice = INT_MAX;

        for (auto &item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        // Count how many item types can be obtained for free
        // from each factor.
        vector<int> gain(n + 1, 0);

        for (int f = 1; f <= n; f++) {
            for (int j = f; j <= n; j += f) {
                gain[f] += freq[j];
            }
            gain[f]--; // exclude the item itself
        }

        // Bonus purchases: each costs price and gives 2 items.
        vector<pair<int, int>> bonus;

        for (auto &item : items) {
            int factor = item[0];
            int price = item[1];

            // A bonus purchase is worth considering only if
            // its cost per item <= cheapest normal purchase.
            if (gain[factor] > 0 && 1LL * price <= 2LL * minPrice) {
                bonus.push_back({price, gain[factor]});
            }
        }

        sort(bonus.begin(), bonus.end());

        long long ans = 0;

        // Buy the most cost-effective bonus purchases first.
        for (auto &[price, count] : bonus) {
            if (budget < price)
                break;

            int buy = min(count, budget / price);

            ans += 2LL * buy;
            budget -= buy * price;
        }

        // Spend remaining budget on cheapest normal items.
        ans += budget / minPrice;

        return (int)ans;
    }
};