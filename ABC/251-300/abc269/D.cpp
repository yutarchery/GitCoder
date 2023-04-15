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
int x[2005], y[2005];
bool painted[2005][2005], visited[2005][2005];

int di[6] = {-1, -1, 0, 0, 1, 1};
int dj[6] = {-1, 0, -1, 1, 0, 1};

void solve(int xi, int yi) {
  visited[xi][yi] = true;

  for (int k = 0; k < 6; k++) {
    int next_xi = xi + di[k], next_yi = yi + dj[k];

    if (painted[next_xi][next_yi] && !visited[next_xi][next_yi]) {
      solve(next_xi, next_yi);
    }
  }

  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    x[i] += 1001;
    y[i] += 1001;
    painted[x[i]][y[i]] = true;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[x[i]][y[i]]) {
      ans++;
      solve(x[i], y[i]);
    }
  }

  cout << ans << endl;

  return 0;
}