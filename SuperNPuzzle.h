//
// Created by aherrera on 10/12/19.
//

#ifndef SUPERNPUZZLE_SUPERNPUZZLE_H
#define SUPERNPUZZLE_SUPERNPUZZLE_H

#include <vector>
#include <string>


class SuperNPuzzle {
  struct SuperState {
    std::string actions;
    std::vector<int> state;
  };

  const std::string AVAILABLE_ACTIONS = "RLDU";
  std::vector<int> _goalState;
  std::vector<int> _initState;
  int _steps = 0;
  int _m = 0;

  void randInitState();
  static int stateDis(const std::vector<int> &pState1, const std::vector<int> &pState2);
  inline void display_stats(const SuperState &state, size_t mem, unsigned long steps);
public:
  explicit SuperNPuzzle(int n = 8);
  explicit SuperNPuzzle(const std::vector<int> &initState);

  std::string depth_first_search(unsigned long &steps, size_t &mem, int stats_interval, unsigned long step_limit);
  std::string breadth_first_search(unsigned long &steps, size_t &mem, int stats_interal, unsigned long step_limit);
  std::string Astar_search(unsigned long &steps, size_t &mem, int stats_interval, unsigned long step_limit);

  void reset(const std::vector<int> &initState);
  inline void display(const std::vector<int> &pState);
  inline void display();
};

#endif //SUPERNPUZZLE_SUPERNPUZZLE_H
