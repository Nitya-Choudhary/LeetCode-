
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // Available servers: {weight, index}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> available;

        // Busy servers: {freeTime, weight, index}
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>> busy;

        int n = servers.size();

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans;
        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {

            time = max(time, (long long)i);

            // Release all servers that have finished
            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [freeTime, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If no server is available, wait
            if (available.empty()) {

                time = get<0>(busy.top());

                // Release servers available at this time
                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [freeTime, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Select server with minimum weight, then minimum index
            auto [weight, index] = available.top();
            available.pop();

            ans.push_back(index);

            // Assign task and calculate server's next free time
            busy.push({time + tasks[i], weight, index});
        }

        return ans;
    }
};
