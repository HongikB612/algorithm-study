#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

class FashionManager
{
public:
  explicit FashionManager(const std::size_t numberOfWears) : numberOfWears(numberOfWears) {}

  void storeWears() {
    for (std::size_t i = 0; i < numberOfWears; i++) {
      std::string type;
      std::string wearing;
      std::cin >> wearing >> type;

      wearType[type].emplace_back(wearing);
    }
  }

  [[maybe_unused]]
  void displayStatus() const {
    for(const auto& pair : wearType) {
      std::cout << "key = " << pair.first << '\n';
      for (const auto& value : pair.second) {
        std::cout << value << ' ';
      }
      std::cout << std::endl;
    }
  }

  [[nodiscard]] int calculateNumberOfCases() const {
    return std::accumulate(
        wearType.begin(), wearType.end(), 1,
        [](int product, const auto& kvp)
        { return product * (kvp.second.size() + 1); }) - 1;
    // -1 is for null set (naked body)
  }

private:
  std::unordered_map<std::string, std::vector<std::string> > wearType;

  std::size_t numberOfWears;
};

int main()
{
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::size_t testCase = 0;
  std::cin >> testCase;

  for (auto test = 0; test < testCase; test++) {
    std::size_t numberOfWears = 0;
    std::cin >> numberOfWears;

    FashionManager manager(numberOfWears);
    manager.storeWears();
    const auto result = manager.calculateNumberOfCases();
    std::cout << result << '\n';
  }

  return 0;
}