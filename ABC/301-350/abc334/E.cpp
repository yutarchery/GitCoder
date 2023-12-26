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

int h, w;
char s[1005][1005];
int group[1005][1005];

int group_count = 0;
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

ll my_pow(ll a, ll n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return my_pow(a * a % MOD2, n / 2);
  } else {
    return (a * my_pow(a, n - 1)) % MOD2;
  }
}

void dfs(int i, int j) {
  group[i][j] = group_count;
  for (int k = 0; k < 4; k++) {
    if (group[i + di[k]][j + dj[k]] == 0 && s[i + di[k]][j + dj[k]] == '#') {
      dfs(i + di[k], j + dj[k]);
    }
  }
  return;
}

int search(int i, int j) {
  set<int> tmp;
  for (int k = 0; k < 4; k++) {
    if (group[i + di[k]][j + dj[k]] > 0) {
      tmp.insert(group[i + di[k]][j + dj[k]]);
    }
  }

  return (group_count + 1) - tmp.size();
}

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (group[i][j] == 0 && s[i][j] == '#') {
        group_count++;
        dfs(i, j);
      }
    }
  }

  ll red_count = 0, green_sum = 0;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (s[i][j] == '.') {
        red_count++;
        green_sum += search(i, j);
        green_sum %= MOD2;
      }
    }
  }

  cout << green_sum * my_pow(red_count, MOD2 - 2) % MOD2 << endl;

  return 0;
}
