#include <iostream>
#include <random>
#include <algorithm>
#include "SuperNPuzzle.h"
using namespace std;

int main() {
  // Create input vectors that are the same as given
  vector<int> v1 = {0,1,2,4,5,3,7,8,6};
  vector<int> v2 = {1,2,3,4,6,8,7,5,0};
  vector<int> v3 = {8,5,0,4,6,3,7,2,1};

  // Create puzzles
  SuperNPuzzle puzzle1(v1);
  SuperNPuzzle puzzle2(v2);
  SuperNPuzzle puzzle3(v3);
  SuperNPuzzle puzzle4;
  SuperNPuzzle puzzle5;

  return 0;
}