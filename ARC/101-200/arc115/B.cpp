#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;
#define fi first
#define se second 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N;
ll C[505][505], A[505], B[505];

int displayAns(){
  cout << A[0];
  for (int i = 1; i < N; i++) cout << " " << A[i];
  cout << endl;

  cout << B[0];
  for (int i = 1; i < N; i++) cout << " " << B[i];
  cout << endl;
  
  return 0;
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cin >> C[i][j];
    }
  }

  for (int i = 0; i < N - 1; i++){
    for (int j = 0; j < N - 1; j++){
      if (C[i][j] - C[i][j + 1] != C[i + 1][j] - C[i + 1][j + 1]){
        No(); return 0;
      }
    }
  }

  Yes();
  int minNum = 1e9, minI = 0, minJ = 0;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      if (minNum > C[i][j]){
        minNum = C[i][j];
        minI = i; minJ = j;
      }
    }
  }

  for (int i = minI - 1; i >= 0; i--){
    A[i] = A[i + 1] + (C[i][0] - C[i + 1][0]);
  }
  for (int i = minI + 1; i < N; i++){
    A[i] = A[i - 1] + (C[i][0] - C[i - 1][0]);
  }

  for (int j = 0; j < N; j++){
    B[j] = C[0][j] - A[0];
  }
  displayAns();


  return 0;
}