//
// Created by aherrera on 10/12/19.
//

#include "SuperNPuzzle.h"

#include <iostream>
#include <algorithm>
#include <random>
#include <deque>
#include <set>

using namespace std;

void SuperNPuzzle::randInitState() {
  int n = _m * _m - 1;
  for (int i = 0; i <= n; i++)
    _initState.push_back(i);

  random_device rd;
  mt19937 gen(rd());
  auto rand = [&](int a, int b) {
    uniform_int_distribution<int> dist(a, b);
    return dist(gen);
  };


  for (int i = 0; i <= rand(0, n); i++) {
    int j = rand(0, n);
    int k = rand(0, n);
    int temp = _initState[j];
    _initState[j] = _initState[k];
    _initState[k] = temp;
  }
}

int SuperNPuzzle::stateDis(const vector<int> &pState1, const vector<int> &pState2) {
  if (pState1.size() != pState2.size()) {
    cout << "Invalid state.\n";
    return -1;
  }
  int dis = 0;
  for (unsigned long i = 0; i < pState1.size(); i++)
    if (pState1[i] != pState2[i])
      dis++;
  return dis;
}

SuperNPuzzle::SuperNPuzzle(int n) {
  _m = (int) sqrt(n + 1.0);
  if (_m * _m < n + 1) {
    cout << "Invalid size of initial state. An alternate size was used." << endl;
    _m++;
  }

  _goalState.clear();
  for (int i = 0; i < _m * _m - 1; i++)
    _goalState.push_back(i + 1);
  _goalState.push_back(0);

  randInitState();
}

SuperNPuzzle::SuperNPuzzle(const vector<int> &initState) {
  reset(initState);
}

void SuperNPuzzle::reset(const std::vector<int> &initState) {
  unsigned long n = initState.size() - 1;
  bool isValid = true;

  // size checking; the puzzle must be m x m, where n = m*m -1.
  _m = static_cast<int>(sqrt(static_cast<double>(n) + 1.0));
  if (_m * _m < (n + 1)) {
    cout << "Invalid size of initial state. An alternate size was used." << endl;
    _m++;
    isValid = false;
  }

  // Checks if the initial state is valid
  // each number between 0 and n (_m*_m-1) must appear exactly once.
  for (unsigned long i = 0; i <= n; i++) {

    bool found = false;
    for (unsigned long j = 0; j <= n; j++)
      if (initState[j] == i) {
        found = true;
        break;
      }

    if (!found) {
      isValid = false;
      break;
    }

  }

  if (!isValid) {
    cout << "Invalid given initial state. An alternate initial state used.\n";
    randInitState();
  } else
    _initState = initState;

  // re-initializes the target state
  _goalState.clear();
  for (int j = 0; j < _m * _m - 1; j++)
    _goalState.push_back(j + 1);
  _goalState.push_back(0);
}

void SuperNPuzzle::display(const vector<int> &pState) {
  int k = 0;
  for (int i = 0; i < _m; i++) {
    for (int j = 0; j < _m; j++)
      cout << pState[k + j] << "\t";
    k += _m;
    cout << endl;
  }
}

void SuperNPuzzle::display() {
  display(_initState);
}

string SuperNPuzzle::depth_first_search() {
  // Create containers
  deque<SuperState> unexplored;
  set<vector<int>> traveled_states;

  // Push initial state to stack
  SuperState initState;
  initState.state = _initState;
  unexplored.push_back(initState);

  while (!unexplored.empty()) {
    auto current_state = unexplored.back();
    traveled_states.insert(current_state.state);
    unexplored.pop_back();

    if (current_state.state == _goalState)
      return current_state.actions;

    int bLoc = 0;
    for (unsigned long i = 0; i < current_state.state.size(); i++) {
      if (current_state.state[i] == 0) {
        bLoc = static_cast<int>(i);
        break;
      }
    }

    for (const char act : AVAILABLE_ACTIONS) {
      int toSwap = -1;
      switch (act) {

        case 'L':
          if (bLoc % _m != 0)
            toSwap = bLoc - 1;
          break;

        case 'R':
          if (bLoc % _m != _m - 1)
            toSwap = bLoc + 1;
          break;

        case 'U':
          if (bLoc / _m != 0)
            toSwap = bLoc - _m;
          break;

        case 'D':
          if (bLoc / _m != _m - 1)
            toSwap = bLoc + _m;
          break;

        default:
          cout << "Invalid action.\n";
          return "!";

      }
      if (toSwap != -1) {
        SuperState next_state = current_state;
        next_state.state[bLoc] = next_state.state[toSwap];
        next_state.state[toSwap] = 0;
        next_state.actions += act;

        if (traveled_states.find(next_state.state) == traveled_states.end() &&
        std::find(unexplored.begin(), unexplored.end(), next_state) == unexplored.end()) {
          unexplored.push_back(next_state);
        } // if end
      } // if end
    } // for end
  } // while end
  return "!";
} // function end

string SuperNPuzzle::breadth_first_search() {
  // Create containers
  deque<SuperState> unexplored;
  set<vector<int>> traveled_states;

  // Push initial state to queue
  SuperState initState;
  initState.state = _initState;
  unexplored.push_back(initState);

  while (!unexplored.empty()) {
    auto current_state = unexplored.front();
    traveled_states.insert(current_state.state);
    unexplored.pop_front();

    if (current_state.state == _goalState)
      return current_state.actions;

    int bLoc = 0;
    for (unsigned long i = 0; i < current_state.state.size(); i++) {
      if (current_state.state[i] == 0) {
        bLoc = static_cast<int>(i);
        break;
      }
    }

    for (const char act : AVAILABLE_ACTIONS) {
      int toSwap = -1;
      switch (act) {

        case 'L':
          if (bLoc % _m != 0)
            toSwap = bLoc - 1;
          break;

        case 'R':
          if (bLoc % _m != _m - 1)
            toSwap = bLoc + 1;
          break;

        case 'U':
          if (bLoc / _m != 0)
            toSwap = bLoc - _m;
          break;

        case 'D':
          if (bLoc / _m != _m - 1)
            toSwap = bLoc + _m;
          break;

        default:
          cout << "Invalid action.\n";
          return "!";

      }
      if (toSwap != -1) {
        SuperState next_state = current_state;
        next_state.state[bLoc] = next_state.state[toSwap];
        next_state.state[toSwap] = 0;
        next_state.actions += act;

        if (traveled_states.find(next_state.state) == traveled_states.end() &&
            std::find(unexplored.begin(), unexplored.end(), next_state) == unexplored.end()) {
          unexplored.push_back(next_state);
        } // if end
      } // if end
    } // for end
  } // while end
  return "!";
} // function end
