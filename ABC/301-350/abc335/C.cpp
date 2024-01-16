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

int n, q;
vector<Pii> pos;

const char dir[4] = {'R', 'L', 'U', 'D'};
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main() {
  cin >> n >> q;
  for (int i = n; i >= 1; i--) {
    pos.push_back({i, 0});
  }

  for (int i = 0; i < q; i++) {
    int num;
    cin >> num;

    if (num == 1) {
      char c;
      cin >> c;

      Pii t = pos[pos.size() - 1];
      for (int k = 0; k < 4; k++) {
        if (c == dir[k]) {
          pos.push_back({t.first + dx[k], t.second + dy[k]});
        }
      }
    } else {
      int p;
      cin >> p;
      cout << pos[pos.size() - p].first << " " << pos[pos.size() - p].second
           << endl;
    }
  }

  return 0;
}
