#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>

using __int64 = int;
using pair = std::pair<__int64, __int64>;

static std::unordered_map<__int64 , __int64> inputOrder;

/// @brief Compare by value, not the key. Sort by decreasing order of value
struct CompareByValue {
  bool operator()(const pair& lhs, const pair& rhs) const {
    if (lhs.second == rhs.second) {
      return inputOrder[lhs.first] > inputOrder[rhs.first];
    }
    return lhs.second < rhs.second;
  }
};

int main()
{
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  static auto inputCount = 0;
  auto N = 0;
  auto maxValue = 0;

  std::cin >> N >> maxValue;

  /// value to frequency
  std::unordered_map<__int64 , __int64> frequency;

  for (auto i = 0; i < N; i++) {
    __int64 inputValue = 0;
    std::cin >> inputValue;
    frequency[inputValue]++;
    if (inputOrder[inputValue] == 0) {
      inputOrder[inputValue] += ++inputCount;
    }
  }

  std::priority_queue<pair, std::vector<pair>, CompareByValue> valueList;

  for (const auto& [key, value] : frequency) {
    valueList.emplace(key, value);
  }

  while (!valueList.empty()) {
    const auto& temp = valueList.top();
    const auto key = temp.first;
    const auto value = temp.second;
    valueList.pop();
    for (int i = 0; i < value; i++) {
      std::cout << key << ' ';
    }
  }
  std::cout << std::endl;

  return 0;
}