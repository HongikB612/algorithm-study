#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>

enum {
  LOSE,
  WIN,
};

class GameManager
{
public:
  GameManager() = default;
  ~GameManager() = default;

  void setGameScoreRule() {
    std::cin >> gameCase >> hackedPlayerNumber;
    std::cin >> winningScore >> losingScore >> targetScore;
  }

  void hackPlayer() {
    hackedPlayers.reserve(hackedPlayerNumber);
    for (int i = 0; i < hackedPlayerNumber; i++) {
      std::string playerName;
      char info = 'L';
      std::cin >> playerName >> info;
      if (info == 'W') {
        hackedPlayers[playerName] = WIN;
      } else {
        hackedPlayers[playerName] = LOSE; // assign 0
      }
    }
  }

  void play() {
    for (int i = 0; i < gameCase; i++) {
      std::string playerName;
      std::cin >> playerName;

      if (hackedPlayers[playerName] == WIN) {
        rating += winningScore;
        if (rating >= targetScore) {
          levelUp = true;
          break;
        }
      } else {
        // rating cannot be negative
        rating = std::max(0, rating - losingScore);
      }
    }
  }

  [[nodiscard]]
  auto isLevelUp() const {
    return levelUp;
  }

private:
  std::unordered_map<std::string, int> hackedPlayers;
  int gameCase = 0;
  int hackedPlayerNumber = 0;
  int winningScore = 0;
  int losingScore = 0;
  int targetScore = 0;

  int rating = 0;
  bool levelUp = false;
};

int main() {
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  GameManager manager;

  manager.setGameScoreRule();
  manager.hackPlayer();
  manager.play();
  if (manager.isLevelUp()) {
    std::cout << "I AM NOT IRONMAN!!" << std::endl;
  } else {
    std::cout << "I AM IRONMAN!!" << std::endl;
  }

  return 0;
}