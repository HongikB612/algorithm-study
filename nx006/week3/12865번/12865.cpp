#include <iostream>
#include <vector>
#include <algorithm>

struct Item
{
    int value;
    int weight;
};

class DPmanager
{
public:
    DPmanager(const std::size_t numberOfItems, const int maxWeight) : numberOfItems(numberOfItems), maxWeight(maxWeight) {
        dp.resize(numberOfItems + 1);
        std::for_each(dp.cbegin(), dp.cend(), [&](auto iter){
            iter.resize(maxWeight + 1);
        });
        items.reserve(numberOfItems);
    }

    auto inputItems() {
        items.emplace_back(0, 0); // index 0 -> empty item
        for (std::size_t i = 0; i < numberOfItems; i++) {
            int weight = 0;
            int value = 0;
            std::cin >> weight >> value;
            items.emplace_back(weight, value);
        }
    }

    auto displayDp() const {
        std::for_each(dp.cbegin(), dp.cend(), [&](const auto iter){
            std::for_each(iter.cbegin(), iter.cend(), [&](const auto num){
                std::cout << num << " ";
            });
            std::cout << std::endl;
        });
    }

    void calculateMaxValue() {
        knapsack_dp();
    }

    auto getMaxValue() {
        return *dp.cend()->end();
    }
private:
    std::vector< std::vector<int> > dp;
    std::vector< Item > items;
    int value;
    int weight;

    int maxWeight;
    std::size_t numberOfItems;

    void knapsack_dp() {
        // itemIndex stands for column index
        for (std::size_t itemIndex = 1; itemIndex < items.size(); itemIndex++) {
            // weightIndex stands for row index
            for (std::size_t weightIndex = 0; weightIndex < maxWeight + 1; weightIndex++) {
                if (weightIndex - items[itemIndex].weight < 0) continue;
                dp[itemIndex][weightIndex] = std::max(
                    dp[itemIndex - 1][weightIndex], // NS(n-1, w) + 0
                    dp[itemIndex - 1][weightIndex - items[itemIndex].weight] + items[itemIndex].value
                );
            }
        }
    }
};

int main()
{
    int numberOfItems = 0;
    int maximumWeight = 0;
    std::cin >> numberOfItems >> maximumWeight;
    DPmanager kn(numberOfItems, maximumWeight);
    kn.inputItems();
    kn.calculateMaxValue();
    kn.displayDp();
    std::cout << kn.getMaxValue() << std::endl;

    return 0;
}