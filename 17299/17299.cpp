#include <iostream>
#include <vector>

static const int MAX=1'000'000;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr), std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> v(N);
    std::vector<int> cnt(MAX+1,0);
    for(int i=0;i<v.size();++i){
        int num;
        std::cin>>num;
        v[i]=num;
        cnt[num]++;
    }


}