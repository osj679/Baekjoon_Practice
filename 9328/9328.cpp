// Creator: OhSeungJae on 01/25/2024
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

// print maximum number of document that can be taken
void solve()
{
    int h, w;
    std::cin >> h >> w;
    // '.' : empty, '*' : wall, '$' : documnet, '#' : door, 'a'~'z' : key, 'A'~'Z' : door
    std::vector<std::vector<char>> map(h + 2, std::vector<char>(w + 2, '*'));

    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            std::cin >> map[i][j];
        }
    }

    std::vector<bool> key(26, false);
    std::string keyring;
    std::cin >> keyring;
    for (auto i = keyring.begin(); i != keyring.end(); ++i)
    {
        key[*i - 'a'] = true;
    }

    int ans = 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        solve();
    }

    return 0;
}