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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int n, q;
priority_queue<Pii> pque[int(2e5 + 5)];
priority_queue<Pii, vector<Pii>, greater<Pii> > all;

int belong[int(2e5 + 5)];
int rate[int(2e5 + 5)];

void optimizeQueue(int queIndex){
  while (!pque[queIndex].empty()){
    Pii p = pque[queIndex].top();
    if (belong[p.se] == queIndex){
      break;
    }else{
      pque[queIndex].pop();
    }
  }

  if (!pque[queIndex].empty()){
    all.push({pque[queIndex].top()});
  }
}

void move(int c, int d){
  int b = belong[c];
  belong[c] = d;

  optimizeQueue(b);
  pque[d].push({rate[c], c});
  all.push(pque[d].top());
}

void solve(){
  while (!all.empty()){
    Pii p = all.top();

    int person = p.se;
    int b = belong[person];

    if (pque[b].empty()){
      all.pop();
    }else if (pque[b].top() != p){
      all.pop();
    }else{
      cout << p.fi << endl;
      break;
    }
  }
}

int main(){
  cin >> n >> q;
  for (int i = 1; i <= n; i++){
    int a, b; cin >> a >> b;
    pque[b].push({a, i});
    rate[i] = a;
    belong[i] = b;
  }

  for (int i = 1; i <= int(2e5); i++){
    if (!pque[i].empty()){
      all.push(pque[i].top());
    }
  }

  for (int i = 0; i < q; i++){
    int c, d; cin >> c >> d;
    move(c, d);
    solve();
  }

  return 0;
}