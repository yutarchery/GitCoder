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

int q, num;
char c;

int h = 1, w = 1;
vector<char> ans[int(1.5e6 + 5)], now;

int main() {
  cin >> q;
  while (q--) {
    cin >> num;
    if (num == 1) {
      cin >> c;
      w++;
      now.push_back(c);
    } else if (num == 2) {
      for (int i = now.size() - 1; i >= 0; i--) {
        ans[h].push_back(now[i]);
      }
      now.resize(0);

      w = 1;
    } else {
      for (int i = now.size() - 1; i >= 0; i--) {
        ans[h].push_back(now[i]);
      }
      now.resize(0);

      h++;
      w = 1;
    }
  }
  for (int i = now.size() - 1; i >= 0; i--) {
    ans[h].push_back(now[i]);
  }

  cout << h << " " << w << endl;

  int start = 0, goal = 0;
  for (int i = 1; i <= h; i++) {
    cout << "# ";
    for (int j = ans[i].size() - 1; j >= 0; j--) {
      cout << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}
