#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>

const int calc_diff(const std::string &ls, const std::string &rs)
{
    int diff = 0;
    for (int i = 0; i < 4; ++i)
    {
        diff += ls[i] == rs[i] ? 0 : 1;
    }
    return diff;
}

const int find_ans(std::vector<std::string> &v)
{
    static const int INF = INT_MAX;
    int ans = INF;
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = i + 1; j < v.size(); ++j)
        {
            for (int k = j + 1; k < v.size(); ++k)
            {
                int diff = calc_diff(v[i], v[j]);
                diff += calc_diff(v[i], v[k]);
                diff += calc_diff(v[j], v[k]);
                ans=std::min(ans,diff);
            }
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int N;
        std::cin >> N;
        std::vector<std::string> v;
        std::string temp;
        for (int j = 0; j < N; ++j)
        {
            std::cin >> temp;
            v.push_back(temp);
        }
        std::cout << find_ans(v) << '\n';
    }

    return 0;
}