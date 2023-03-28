#include <iostream>
#include <vector>
#include <unordered_map>
#include <span>
#include <set>

template <typename T>
void display(const std::span<T> sp)
{
    for (const auto &value : sp)
    {
        std::cout << value << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    int N = 0;
    std::cin >> N;

    std::set<int> positions;

    std::vector<int> input(N);
    for (auto &number : input)
    {
        std::cin >> number;
        positions.emplace(number);
    }

    // value -> pressed value
    std::unordered_map<int, int> valueToPressed;
    valueToPressed.reserve(N);

    std::vector<int> sortedPositions;
    sortedPositions.reserve(positions.size());
    std::copy(positions.begin(), positions.end(), std::back_inserter(sortedPositions));

    for (std::size_t i = 0; i < sortedPositions.size(); i++)
    {
        valueToPressed[sortedPositions[i]] = i;
    }

    for (const auto num : input)
    {
        try
        {
            std::cout << valueToPressed.at(num) << ' ';
        }
        catch (std::out_of_range e)
        {
            std::cout << e.what() << '\n';
        }
    }
    std::cout << std::endl;

    return 0;
}