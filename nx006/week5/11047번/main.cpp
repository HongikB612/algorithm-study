#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int N = 0;
    int targetCost = 0;

    std::cin >> N >> targetCost;

    std::vector<int> coins(N);

    for (auto& coin : coins)
    {
        std::cin >> coin;
    }

    std::sort(coins.begin(), coins.end());

    auto coinCount = 0;
    auto remainCost = targetCost;
    while(remainCost != 0)
    {
        coinCount += remainCost / coins.back();
        remainCost %= coins.back();
        coins.pop_back();
    }

    std::cout << coinCount << std::endl;

    return 0;
}