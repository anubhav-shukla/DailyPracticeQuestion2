class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int maxWeight = 0;
        unordered_map<int, vector<pair<int, int>>> graph;

        for (auto& e : edges) {
            int fromNode = e[0];
            int toNode = e[1];
            int weight = e[2];
            graph[fromNode].push_back({toNode, weight});
            maxWeight = max(maxWeight, weight);
        }

        auto check = [&](int minWeight) {
            priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>> heap;
            heap.push({0, 0});
            unordered_map<int, long long> bestCost;
            while (!heap.empty()) {
                auto [currentCost, currentNode] = heap.top();
                heap.pop();
                if (currentNode == online.size() - 1) {
                    return true;
                }
                if (bestCost.count(currentNode) && bestCost[currentNode] <= currentCost) {
                    continue;
                }
                bestCost[currentNode] = currentCost;
                for (auto& [nextNode, edgeWeight] : graph[currentNode]) {
                    if (currentCost + edgeWeight > k) {
                        continue;
                    }
                    if (!online[nextNode]) {
                        continue;
                    }
                    if (edgeWeight < minWeight) {
                        continue;
                    }
                    heap.push({currentCost + edgeWeight, nextNode});
                }
            }
            return false;
        };
        int left = -1;
        int right = maxWeight + 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right >= 0 ? right : -1;
    }
};
