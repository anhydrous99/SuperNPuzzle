//
// Created by aherrera on 10/12/19.
//

#ifndef SUPERNPUZZLE_SUPERNPUZZLE_H
#define SUPERNPUZZLE_SUPERNPUZZLE_H

#include <vector>
#include <string>


class SuperNPuzzle {
  const std::string AVAILABLE_ACTIONS = "";
  std::vector<int> _goalState;
  std::vector<int> _initState;
  int _steps = 0;
  int _m = 0;

  void randInitState();
  static int stateDis(const std::vector<int> &pState1, const std::vector<int> &pState2);

public:
  explicit SuperNPuzzle(int n = 8);
  explicit SuperNPuzzle(const std::vector<int> &initState);

  std::string depth_first_search();
  std::string breadth_first_search();

  void reset(const std::vector<int> &initState);
  void display(const std::vector<int> &pState);
  void display();
};

#endif //SUPERNPUZZLE_SUPERNPUZZLE_H
