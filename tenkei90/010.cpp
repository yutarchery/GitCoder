#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;
#define fi first
#define se second 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N, C, P[2][int(1e5 + 5)];
int Q, L, R, A[int(1e5 + 5)], B[int(1e5 + 5)];

int main(){
  cin >> N;
  for (int i = 1; i <= N; i++){
    cin >> C; C--;
    cin >> P[C][i];

    for (int j = 0; j < 2; j++){
      P[j][i] += P[j][i - 1];
    }
  }

  cin >> Q;
  for (int i = 0; i < Q; i++){
    cin >> L >> R;
    A[i] = P[0][R] - P[0][L - 1];
    B[i] = P[1][R] - P[1][L - 1];
  }

  for (int i = 0; i < Q; i++){
    cout << A[i] << " " << B[i] << endl;
  }

  return 0;
}