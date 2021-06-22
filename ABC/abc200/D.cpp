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

int N, A[205], sum[300];

int calcSum(int num){
  int ans = 0;
  for (int i = 1; i <= N; i++){
    if (num % 2 != 0){
      ans += A[i];
    }
    num /= 2;
    ans %= 200;
  }
  return ans;
}

int display(int num){
  vector <int> ans;
  for (int i = 1; i <= N; i++){
    if (num % 2 != 0){
      ans.push_back(i);
    }
    num /= 2;
  }

  cout << ans.size();
  for (int i : ans) cout << " " << i;
  cout << endl;
  return 0;
}

int solve(){
  for (int i = 1; i < (1 << N); i++){
    sum[i] = calcSum(i);
  }

  for (int i = 1; i < (1 << N); i++){
    for (int j = i + 1; j < (1 << N); j++){
      if (sum[i] == sum[j]){
        Yes();
        display(i);
        display(j);
        return 0;
      }
    }
  }
  No();
  return 0;
}

int main(){
  cin >> N;
  for (int i = 1; i <= N; i++){
    cin >> A[i]; A[i] %= 200;
  }
  N = min(N, 8);
  solve();
  return 0;
}