
class Solution {
public:
    void floydWarshall(std::vector<std::vector<int>> &dist) {
        int n = dist.size();
        const int INF = 100000000;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        long long intermediate_dist = (long long)dist[i][k] + dist[k][j];
                        if (dist[i][j] > intermediate_dist) {
                            dist[i][j] = intermediate_dist;
                        }
                    }
                }
            }
        }
    }
};
