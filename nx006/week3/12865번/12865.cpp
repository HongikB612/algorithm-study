#include <iostream>
#include <vector>
#include <algorithm>

class Item
{
public:
    Item(const int value, const int weight) : value(value), weight(weight) {}
    inline int getValue() const { return value; }
    inline int getWeight() const { return weight; }

private:
    int value;
    int weight;
};

class DPManager
{
public:
    DPManager(const std::size_t numberOfItems, const int maxWeight)
        : numberOfItems(numberOfItems),
          maxWeight(maxWeight)
    {
        dp.resize(numberOfItems + 1);
        for (auto &row : dp)
        {
            row.resize(maxWeight + 1);
        }

        items.reserve(numberOfItems);
    }

    auto inputItems()
    {
        items.emplace_back(0, 0); // index 0 -> empty item
        for (std::size_t i = 0; i < numberOfItems; i++)
        {
            int weight = 0;
            int value = 0;
            std::cin >> weight >> value;
            items.emplace_back(value, weight);
        }
    }

    auto displayDp() const -> void
    {
        for (const auto &row : dp)
        {
            for (const auto value : row)
            {
                std::cout << value << ' ';
            }
            std::cout << std::endl;
        }
    }

    inline void calculateMaxValue()
    {
        knapsack_dp();
    }

    inline auto getMaxValue() const
    {
        return dp.back().back();
    }

private:
    std::vector<std::vector<int>> dp;
    std::vector<Item> items;

    const int maxWeight;
    const std::size_t numberOfItems;

    void knapsack_dp()
    {
        // itemIndex stands for column index
        for (int itemIndex = 1; itemIndex < items.size(); itemIndex++)
        {
            // weightIndex stands for row index
            for (int weightIndex = 1; weightIndex < maxWeight + 1; weightIndex++)
            {
                // for case of bad access
                if (weightIndex - items[itemIndex].getWeight() < 0)
                {
                    dp[itemIndex][weightIndex] = dp[itemIndex - 1][weightIndex];
                    continue;
                }
                dp[itemIndex][weightIndex] = std::max(
                    dp[itemIndex - 1][weightIndex],                                                             // NS(n-1, w) + 0
                    dp[itemIndex - 1][weightIndex - items[itemIndex].getWeight()] + items[itemIndex].getValue() // NS(n-1, w - w[n]) + v[n]
                );
            }
        }
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int numberOfItems = 0;
    int maximumWeight = 0;
    std::cin >> numberOfItems >> maximumWeight;
    DPManager kn(numberOfItems, maximumWeight);
    kn.inputItems();
    kn.calculateMaxValue();

    std::cout << kn.getMaxValue() << std::endl;

    return 0;
}