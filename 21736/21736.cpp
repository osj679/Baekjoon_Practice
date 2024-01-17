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
    static const std::pair<int, int> init_pair(-1, -1);
    static const std::vector<const std::pair<const int, const int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    std::pair<int, int> pos = {-1, -1};
    for (int i = 0; i < matrix.size() && pos == init_pair; ++i)
    {
        for (int j = 0; j < matrix[i].size() && pos == init_pair; ++j)
        {
            if (matrix[i][j] == 'I')
            {
                pos.first = j;
                pos.second = i;
            }
        }
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