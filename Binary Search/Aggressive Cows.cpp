#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(vector<int>& stalls, int cows, int dist) {
    int countCows = 1;
    int lastPlaced = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPlaced >= dist) {
            countCows++;
            lastPlaced = stalls[i];

            if (countCows >= cows)
                return true;
        }
    }

    return false;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls.front();

    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, cows, mid)) {
            ans = mid;
            low = mid + 1;   // try larger distance
        } else {
            high = mid - 1;  // reduce distance
        }
    }

    return ans;
}
