#include <iostream>
#include <vector>
#include <queue>

void input_matrix(std::vector<std::vector<char>> &matrix)
{
    for (auto i = matrix.begin(); i != matrix.end(); ++i)
    {
        for (auto j = i->begin(); j != i->end(); ++j)
        {
            std::cin >> *j;
        }
    }
    return;
}

const std::string find_ans(const std::vector<std::vector<char>> &matrix)
{
    int ans = 0;
    std::pair<int, int> init_pair(-1, -1);
    const std::vector< std::pair<int, int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    std::pair<int, int> pos = {-1, -1};
    for (int i = 0; i < matrix.size() && pos == init_pair; ++i)
    {
        for (int j = 0; j < matrix[i].size() && pos == init_pair; ++j)
        {
            if (matrix[i][j] == 'I')
            {
                pos.first = i;
                pos.second = j;
            }
        }
    }

    std::vector<std::vector<int>> route_save(matrix.size(), std::vector<int>(matrix[0].size(), -1));

    std::queue<std::pair<int, int>> q;
    q.push(pos);
    route_save[pos.first][pos.second] = 0;

    while (!q.empty())
    {
        const std::pair<int, int> now_pos(q.front());
        q.pop();
        if (matrix[now_pos.first][now_pos.second] == 'P')
        {
            ++ans;
        }
        for (int i = 0; i < 4; ++i)
        {
            std::pair<int, int> next_pos(now_pos);
            next_pos.first += move[i].first;
            next_pos.second += move[i].second;
            if (next_pos.first < 0 || next_pos.first >= matrix.size() || next_pos.second < 0 || next_pos.second >= matrix[0].size() || matrix[next_pos.first][next_pos.second] == 'X' || route_save[next_pos.first][next_pos.second] != -1)
            {
                continue;
            }
            route_save[next_pos.first][next_pos.second] = route_save[now_pos.first][now_pos.second] + 1;
            q.push(next_pos);
        }
    }

    if (ans == 0)
    {
        return "TT";
    }
    else
    {
        return std::to_string(ans);
    }
}

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<char>> matrix(N, std::vector<char>(M));
    input_matrix(matrix);

    std::cout << find_ans(matrix);
    return 0;
}