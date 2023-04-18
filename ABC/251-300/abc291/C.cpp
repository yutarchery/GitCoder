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
string s;
int x = 0, y = 0;
map<Pii, bool> visited;

int main() {
  cin >> n >> s;
  visited[{x, y}] = true;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      x++;
    } else if (s[i] == 'L') {
      x--;
    } else if (s[i] == 'U') {
      y++;
    } else {
      y--;
    }

    if (visited[{x, y}]) {
      Yes();
      return 0;
    }
    visited[{x, y}] = true;
  }

  No();
  return 0;
}