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
string s[20];
vector<int> graph[20];

bool visited[20][(1 << 16)], ans[20][(1 << 16)];

bool win_first(bool is_first, int last_idx, int now_idx) {
  if (visited[last_idx][now_idx]) {
    return ans[last_idx][now_idx];
  }

  visited[last_idx][now_idx] = true;
  if (is_first) {
    bool res = false;
    for (int next_idx : graph[last_idx]) {
      if ((now_idx & (1 << next_idx)) == 0) {
        res |= win_first(!is_first, next_idx, now_idx + (1 << next_idx));
      }
    }

    return ans[last_idx][now_idx] = res;
  } else {
    bool res = true;
    for (int next_idx : graph[last_idx]) {
      if ((now_idx & (1 << next_idx)) == 0) {
        if (!win_first(!is_first, next_idx, now_idx + (1 << next_idx))) {
          res = false;
        }
      }
    }

    return ans[last_idx][now_idx] = res;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (s[i][s[i].length() - 1] == s[j][0]) {
        graph[i].push_back(j);
      }
      if (s[j][s[j].length() - 1] == s[i][0]) {
        graph[j].push_back(i);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (win_first(false, i, 1 << i)) {
      cout << "First" << endl;
      return 0;
    }
  }
  cout << "Second" << endl;

  return 0;
}
