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

int n, s[int(3e5 + 5)], t[int(3e5 + 5)];

int cnt[int(6e5 + 5)], idx[int(6e5 + 5)];

ll ans = 1;
vector<int> graph[int(3e5 + 5)];
bool visited[int(3e5 + 5)], judge[int(3e5 + 5)];

void solve(int start) {
  queue<int> que;
  que.push(start);
  visited[start] = true;

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int j : graph[q]) {
      if (!visited[j]) {
        visited[j] = true;
        judge[j] = !judge[q];
        que.push(j);
      } else {
        if (judge[j] == judge[q]) {
          ans = 0;
        }
      }
    }
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> t[i];
    cnt[s[i]]++;
    cnt[t[i] + 1]--;

    idx[s[i]] = i;
    idx[t[i]] = i;
  }

  for (int i = 1; i <= 2 * n; i++) {
    cnt[i] += cnt[i - 1];

    if (cnt[i] >= 3) {
      cout << 0 << '\n';
      return 0;
    }
  }

  set<int> st;
  for (int i = 1; i <= 2 * n; i++) {
    auto iter = st.find(idx[i]);

    if (iter == st.end()) {
      for (int j : st) {
        graph[idx[i]].emplace_back(j);
        graph[j].emplace_back(idx[i]);
      }
      st.insert(idx[i]);
    } else {
      st.erase(idx[i]);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i]) {
      continue;
    }

    ans = (ans * 2) % MOD2;
    solve(i);
  }

  cout << ans << '\n';

  return 0;
}
