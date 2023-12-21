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

int n, t[int(2e5 + 5)], x[int(2e5 + 5)];
vector<int> potion[int(2e5 + 5)];
bool get_potion[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i];
  }

  for (int i = 1; i <= n; i++) {
    if (t[i] == 1) {
      potion[x[i]].push_back(i);
    } else {
      int l = potion[x[i]].size();
      if (l == 0) {
        cout << -1 << endl;
        return 0;
      } else {
        get_potion[potion[x[i]][l - 1]] = true;
        potion[x[i]].erase(potion[x[i]].begin() + l - 1);
      }
    }
  }

  int ans = 0, k = 0;
  vector<int> action;
  for (int i = 1; i <= n; i++) {
    if (t[i] == 1) {
      if (get_potion[i]) {
        k++;
        action.push_back(1);
      } else {
        action.push_back(0);
      }
    } else {
      k--;
    }
    ans = max(ans, k);
  }
  cout << ans << endl;
  for (int i = 0; i < action.size(); i++) {
    cout << action[i];
    if (i == action.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
