#include <iostream>
#include <vector>
#include <cmath>

static const int MAX_DIFF = 30;

const int calc_avg(const std::vector<int> &v, const int n)
{
    if (n == 0)
    {
        return 0;
    }

    const int cutted_numbers = static_cast<int>(std::round(0.15 * n));

    int temp_sum = 0;
    int min_idx, min_number;
    for (int i = 1; i <= MAX_DIFF; ++i)
    {
        temp_sum += v[i];
        if (temp_sum >= cutted_numbers)
        {
            min_idx = i;
            min_number = temp_sum - cutted_numbers;
            break;
        }
    }
    temp_sum = 0;
    int max_idx, max_number;
    for (int i = MAX_DIFF; i >= 1; --i)
    {
        temp_sum += v[i];
        if (temp_sum >= cutted_numbers)
        {
            max_idx = i;
            max_number = temp_sum - cutted_numbers;
            break;
        }
    }

    int sum = 0;
    for (int i = min_idx; i <= max_idx; ++i)
    {
        if (i == min_idx)
        {
            sum += min_number * i;
        }
        else if (i == max_idx)
        {
            sum += max_number * i;
        }
        else
        {
            sum += v[i] * i;
        }
    }

    return std::round(static_cast<long double>(sum) / (n - 2 * cutted_numbers));
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> v(MAX_DIFF + 1);

    int input;
    for (int i = n; i > 0; --i)
    {
        std::cin >> input;
        v[input]++;
    }

    std::cout << calc_avg(v, n);

    return 0;
}