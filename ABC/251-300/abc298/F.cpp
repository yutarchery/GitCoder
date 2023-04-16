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
int r[int(2e5 + 5)], c[int(2e5 + 5)];
ll x[int(2e5 + 5)];

map<Pii, ll> values;

map<int, ll> sum_row_map, sum_column_map;
map<int, bool> used_row, used_column;
vector<int> rows, columns;
vector<Pli> sum_row, sum_column;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> r[i] >> c[i] >> x[i];
    values[{r[i], c[i]}] = x[i];

    sum_row_map[r[i]] += x[i];
    sum_column_map[c[i]] += x[i];

    if (!used_row[r[i]]) {
      rows.push_back(r[i]);
      used_row[r[i]] = true;
    }
    if (!used_column[c[i]]) {
      columns.push_back(c[i]);
      used_column[c[i]] = true;
    }
  }

  for (int i = 0; i < rows.size(); i++) {
    sum_row.push_back({sum_row_map[rows[i]], i});
  }
  sort(sum_row.begin(), sum_row.end(), greater<Pli>());
  for (int i = 0; i < columns.size(); i++) {
    sum_column.push_back({sum_column_map[columns[i]], i});
  }
  sort(sum_column.begin(), sum_column.end(), greater<Pli>());

  ll ans = 0;
  for (int i = 0; i < sum_row.size(); i++) {
    if (ans >= sum_row[0].first + sum_column[0].first) {
      break;
    }

    for (int j = 0; j < sum_column.size(); j++) {
      ll value =
          values[{rows[sum_row[i].second], columns[sum_column[j].second]}];
      if (value > 0) {
        ans = max(ans, sum_row[i].first + sum_column[j].first - value);
      } else {
        ans = max(ans, sum_row[i].first + sum_column[j].first);
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}