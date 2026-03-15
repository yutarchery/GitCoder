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
char s[1005][1005];

vector<int> graph[1005];
int input_cnt[1005];
int ans[1005];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (s[i][j] == 'x') {
        graph[j].push_back(i);
        input_cnt[i]++;
      } else if (s[i][j] == 'o') {
        graph[i].push_back(j);
        input_cnt[j]++;
      }
    }
  }

  queue<int> que;
  for (int i = 1; i <= n; i++) {
    if (input_cnt[i] == 0) {
      que.push(i);
    }
  }

  int now = n;
  while (!que.empty()) {
    int q = que.front();
    que.pop();

    ans[q] = now;
    now--;
    for (int next : graph[q]) {
      input_cnt[next]--;
      if (input_cnt[next] == 0) {
        que.push(next);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (ans[i] == 0) {
      No();
      return 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i][j] == '?') {
        if (ans[i] > ans[j]) {
          s[i][j] = 'o';
        } else {
          s[i][j] = 'x';
        }
      }
    }
  }

  Yes();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << s[i][j];
    }
    cout << '\n';
  }

  return 0;
}
