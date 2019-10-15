#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include "SuperNPuzzle.h"
#include "extern/memory_usage.h"

using namespace std;
using namespace chrono;
typedef high_resolution_clock hrc;

void test_battery(SuperNPuzzle &puzzle, const string &puzzle_name) {
  size_t max_mem;
  unsigned long steps;

  cout << "Running puzzle: " << puzzle_name << endl;

  cout << " A* search\n";
  auto start = hrc::now();
  std::string Astar_result = puzzle.Astar_search(steps, max_mem, 1000, 200000);
  auto end = hrc::now();
  auto Astar_duration = end - start;
  auto Astar_mem = max_mem;
  auto Astar_steps = steps;

  cout << "breadth first search\n";
  start = hrc::now();
  std::string breadth_result = puzzle.breadth_first_search(steps, max_mem, 1000, 200000);
  end = hrc::now();
  auto breadth_duration = end - start;
  auto breadth_mem = max_mem;
  auto breadth_steps = steps;

  cout << "depth first search\n";
  start = hrc::now();
  std::string depth_result = puzzle.depth_first_search(steps, max_mem, 1000, 200000);
  end = hrc::now();
  auto depth_duration = end - start;
  auto depth_mem = max_mem;
  auto depth_steps = steps;

  cout << "Puzzle: " << puzzle_name << " - solution mode: A*\n";
  cout << "A* duration: " << duration_cast<milliseconds>(Astar_duration).count() << " milliseconds\n";
  cout << "A* max memory usage: " << Astar_mem / 1000 << " KB\n";
  cout << "A* steps to solution: " << Astar_steps << endl;

  cout << "Puzzle: " << puzzle_name << " - solution mode: breadth\n";
  cout << "duration: " << duration_cast<milliseconds>(breadth_duration).count() << " milliseconds\n";
  cout << "max memory usage: " << breadth_mem / 1000 << " KB\n";
  cout << "steps to solution: " << breadth_steps << endl;

  cout << "Puzzle: " << puzzle_name << " - solution mode: depth\n";
  cout << "duration: " << duration_cast<milliseconds>(depth_duration).count() << " milliseconds\n";
  cout << "max memory usage: " << depth_mem / 1000 << " KB\n";
  cout << "steps to solution: " << depth_steps << endl;

  cout << "Press any key to continue...\n";
  cin.get();
}

int main() {
  // Create input vectors that are the same as given
  vector<int> v1 = {0, 1, 2, 4, 5, 3, 7, 8, 6};
  vector<int> v2 = {1, 2, 3, 4, 6, 8, 7, 5, 0};
  vector<int> v3 = {8, 5, 0, 4, 6, 3, 7, 2, 1};

  // Create puzzles
  SuperNPuzzle puzzle1(v1);
  SuperNPuzzle puzzle2(v2);
  SuperNPuzzle puzzle3(v3);
  SuperNPuzzle puzzle4;
  SuperNPuzzle puzzle5;

  // Calculate how long it takes to get size of process in memory
  auto start = hrc::now();
  size_t mem_usage = getCurrentRSS();
  auto end = hrc::now();
  // Show how much memory is being used and how long it took
  cout << "Current memory usage: " << mem_usage / 1000 << " KB and it took "
       << duration_cast<microseconds>(end - start).count() << " microseconds\n";

  test_battery(puzzle1, "puzzle1");
  test_battery(puzzle2, "puzzle2");
  test_battery(puzzle3, "puzzle3");
  test_battery(puzzle4, "puzzle4");
  test_battery(puzzle5, "puzzle5");
  return 0;
}
