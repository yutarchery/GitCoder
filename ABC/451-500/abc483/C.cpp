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

int n, m, a[int(2e5 + 5)], b[int(2e5 + 5)];

set<Pii> now;
int cnt[int(2e5 + 5)];
vector<int> seconds[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    now.insert({0, i});
  }

  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
    seconds[a[i]].emplace_back(b[i]);

    now.erase({cnt[a[i]], a[i]});
    cnt[a[i]]++;
    now.insert({cnt[a[i]], a[i]});
  }

  for (int i = 1; i <= n; i++) {
    for (int j : seconds[i]) {
      now.erase({cnt[i], i});
      cnt[i]--;
      now.insert({cnt[i], i});

      now.erase({cnt[j], j});
      cnt[j]++;
      now.insert({cnt[j], j});
    }

    auto iter = now.end();
    iter--;

    int max_cnt = (*iter).first;
    iter = now.lower_bound({max_cnt, 0});

    cout << (*iter).second << '\n';

    for (int j : seconds[i]) {
      now.erase({cnt[i], i});
      cnt[i]++;
      now.insert({cnt[i], i});

      now.erase({cnt[j], j});
      cnt[j]--;
      now.insert({cnt[j], j});
    }
  }

  return 0;
}
