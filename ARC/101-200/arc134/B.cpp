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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n;
char s[int(2e5 + 5)];

priority_queue<int> que[26];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    que[s[i] - 'a'].push(i);
  }

  int r = n;
  for (int i = 1; i <= n; i++) {
    if (i >= r) {
      break;
    }

    for (int j = 0; j < s[i] - 'a'; j++) {
      if (que[j].empty()) {
        continue;
      }
      int t = que[j].top();
      if (i < t) {
        swap(s[i], s[t]);
        r = t - 1;
        break;
      } else {
        continue;
      }
    }

    for (int j = 0; j < 26; j++) {
      while (!que[j].empty()) {
        int q = que[j].top();
        if (r < q) {
          que[j].pop();
          continue;
        } else {
          break;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << s[i];
  }
  cout << '\n';

  return 0;
}
