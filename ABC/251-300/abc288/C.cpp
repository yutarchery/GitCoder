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

int n, m, a, b;
int group[int(2e5 + 5)], cnt[int(2e5 + 5)];

int find_parent(int a) {
  if (a == group[a]) {
    return a;
  }

  int ga = find_parent(group[a]);
  return group[a] = ga;
}

void unite(int a, int b) {
  int ga = find_parent(a), gb = find_parent(b);
  group[a] = min(ga, gb);
  group[b] = min(ga, gb);
  group[max(ga, gb)] = min(ga, gb);
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    group[i] = i;
  }

  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    unite(a, b);
  }

  for (int i = 1; i <= n; i++) {
    cnt[find_parent(i)]++;
  }

  int ans = m;
  for (int i = 1; i <= n; i++) {
    ans -= max(0, cnt[i] - 1);
  }
  cout << ans << endl;

  return 0;
}
