#include <iostream>
#define MAX 9999

using namespace std;

// Number of the places
int n = 4;
//Next distan array will give Minimum distance through all the position
int distan[10][10] = {
  {0, 20, 42, 25},
  {20, 0, 30, 34},
  {42, 30, 0, 10},
  {25, 34, 10, 0}
};

int completed_visit = (1 << n) -1;
int DP[16][4];

int tsp(int mark,int position) {
  if(mark==completed_visit) {
    return distan[position][0];
  }

  if(DP[mark][position] != -1) {
     return DP[mark][position];
  }

  //Save min answer
  int answer = MAX;

  //Visit of the unvisited cities and save the minimum shortest path
  for(int city = 0; city < n; city++) {
    //condition to find not visited country
    if((mark&(1 << city)) == 0) {
      int newAnswer = distan[position][city] + tsp( mark|(1 << city),city);
      answer = min(answer, newAnswer);
    }
  }
  return DP[mark][position] = answer;
}

int main() {
  // initialize the DP array
  for(int i = 0; i < (1 << n); i++) {
      for(int j = 0; j < n; j++) {
          DP[i][j] = -1;
      }
  }
  cout << "Minimum Distance Travelling is " << tsp(1,0) << endl << endl;
  return 0;
}