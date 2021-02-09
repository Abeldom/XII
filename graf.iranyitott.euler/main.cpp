#include <fstream>
#include <iostream>

using namespace std;

ifstream in("input.txt");

int main() {
  int n;
  in >> n;
  int matrix[n][n];

  //matrix lenullazasa
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrix[i][j] = 0;
    }
  }

  int db;
  in >> db;
  int from, to;
  //iranyitott graf beolvasasa
  for (int i = 0; i < db; i++) {
    in >> from >> to;
    matrix[from-1][to-1] = 1;
  }

  int bejovo[n] = {0};
  int kimeno[n] = {0};

//csucsokbol kimeno es bemeno elek kiszamolasa
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      bejovo[i] += matrix[j][i];
      kimeno[i] += matrix[i][j];
    }
  }

  int szaml = 0;
  for (int i = 0; i < n; i++) {
    // cout << bejovo[i] << " " << kimeno[i] << endl;
    
    if (bejovo[i] != kimeno[i]) {
      szaml++;
    }
    if (szaml > 2) {
      break;
    }
  }

  if (szaml > 2) cout << "nem";

  cout << "euleri";

  return 0;
}