#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n;
string s[5];
const string t[5] = {".###..#..###.###.#.#.###.###.###.###.###.",
                     ".#.#.##....#...#.#.#.#...#.....#.#.#.#.#.",
                     ".#.#..#..###.###.###.###.###...#.###.###.",
                     ".#.#..#..#.....#...#...#.#.#...#.#.#...#.",
                     ".###.###.###.###...#.###.###...#.###.###."};

int judge(int s_idx) {
  for (int j = 0; j <= 9; j++) {
    bool flag = true;
    for (int i = 0; i < 5; i++) {
      for (int k = 0; k < 3; k++) {
        if (s[i][s_idx + k] != t[i][4 * j + 1 + k]) {
          flag = false;
        }
      }
    }

    if (flag) {
      return j;
    }
  }

  return -1;
}

int main() {
  cin >> n;
  for (int i = 0; i < 5; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < n; i++) {
    cout << judge(i * 4 + 1);
  }
  cout << endl;

  return 0;
}
