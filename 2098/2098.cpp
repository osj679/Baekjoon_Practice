#include <iostream>
#include <vector>
#include <climits>

const int INF = INT_MAX;
int N;

void input_W(std::vector<std::vector<int>> &W)
{
    for (auto i = W.begin(); i != W.end(); ++i)
    {
        for (auto j = i->begin(); j != i->end(); ++j)
        {
            std::cin >> *j;
        }
    }
    return;
}

const int dfs(std::vector<std::vector<int>> &W, std::vector<std::vector<int>> &dp, const int start_city, const int now_city, const int visit_city)
{
    if (dp[start_city][visit_city] != INF)
    {
        return dp[start_city][visit_city];
    }

    for (int i = 0; i < N; ++i)
    {
        if (W[i][now_city] == 0 || (visit_city & (1 << i)) == 0 || (i == start_city && visit_city != (1 << i)))
        {
            continue;
        }
        const int calc_pre_min_route = dfs(W, dp, start_city, i, visit_city ^ (1 << i));
        if (calc_pre_min_route == INF)
        {
            continue;
        }
        dp[start_city][visit_city] = std::min(dp[start_city][visit_city], calc_pre_min_route + W[i][now_city]);
    }
    return dp[start_city][visit_city];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    std::cin >> N;

    std::vector<std::vector<int>> W(N, std::vector<int>(N));
    input_W(W);

    std::vector<std::vector<int>> dp(N, std::vector(1 << N, INF));
    for (int i = 0; i < N; ++i)
    {
        dp[i][0] = 0;
    }
    int ans = INF;
    for (int i = 0; i < N; ++i)
    {
        ans = std::min(ans, dfs(W, dp, i, i, (1 << N) - 1));
    }

    std::cout << ans;

    return 0;
}