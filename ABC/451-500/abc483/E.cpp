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

ll n, m;
char s[int(2e5 + 5)][10];

bool order[10];
const ll mask = 30;
ll ans[3];
map<ll, ll> cnt;

void prepare(int idx, int diff) {
  for (int i = 1; i <= m; i++) {
    order[i] = (i > diff);
  }

  do {
    ll now = 0;
    for (int i = 1; i <= m; i++) {
      now *= 31;
      if (order[i]) {
        now += s[idx][i] - 'a' + 1;
      } else {
        now += mask;
      }
    }

    ans[diff] += cnt[now];
    cnt[now]++;

  } while (next_permutation(order + 1, order + m + 1));

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> s[i][j];
    }

    for (int j = 0; j <= 2; j++) {
      prepare(i, j);
    }
  }

  ans[1] -= m * ans[0];
  ans[2] -= (m * (m - 1) / 2) * ans[0] + (m - 1) * ans[1];
  cout << ans[0] + ans[1] + ans[2] << '\n';

  return 0;
}
