#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include "SuperNPuzzle.h"
#include "extern/memory_usage.h"

using namespace std;

int main() {
  using namespace chrono;
  typedef high_resolution_clock hrc;

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

  unsigned long steps;
  unsigned long max_mem;
  std::string actions;

  start = hrc::now();
  actions = puzzle1.Astar_search(steps, max_mem, 1000, 100);
  end = hrc::now();
  auto puzzle1_dur = end - start;
  return 0;
}