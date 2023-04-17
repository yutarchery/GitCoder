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
double x[int(2e5 + 5)];
vector<double> pos, neg, candidate;

void make_candidate() {
  for (int i = 0; i < 3; i++) {
    if (i < pos.size()) {
      candidate.push_back(pos[i]);
    }
    if (3 <= int(pos.size()) - 1 - i) {
      candidate.push_back(pos[pos.size() - 1 - i]);
    }

    if (i < neg.size()) {
      candidate.push_back(neg[i]);
    }
    if (3 <= int(neg.size()) - 1 - i) {
      candidate.push_back(neg[neg.size() - 1 - i]);
    }
  }
  return;
}

double m = 1e9, M = -1e9;

void solve(int i, int j, int k) {
  double value = (candidate[i] + candidate[j] + candidate[k]) /
                 (candidate[i] * candidate[j] * candidate[k]);

  m = min(m, value);
  M = max(M, value);
  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    if (x[i] > 0) {
      pos.push_back(x[i]);
    } else {
      neg.push_back(x[i]);
    }
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());

  make_candidate();

  for (int i = 0; i < candidate.size(); i++) {
    for (int j = i + 1; j < candidate.size(); j++) {
      for (int k = j + 1; k < candidate.size(); k++) {
        solve(i, j, k);
      }
    }
  }

  cout << setprecision(32) << m << endl;
  cout << setprecision(32) << M << endl;

  return 0;
}