#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ff first
#define ss second
#define MP make_pair
#define PB push_back
#define ll long long
#define f(i,x,n) for(ll i=x;i<n;i++)
#define fd(i,x,n) for(ll i=n-1;i>=x;i--)
#define ld long double
#define sorta(a,n) sort(a,a+n);
#define sortve(v) sort(v.begin(),v.end());
#define sortvdec(v) sort(v.begin(),v.end(),greater<ll>());
#define inarr(arr,n) for(long long i=0;i<n;i++)cin>>arr[i];
#define prinarr(arr) {for(long long x:arr)cout<<x<<" ";} cout<<"\n";
#define cout1(a) cout<<a<<"\n";
#define cout2(a,b) cout<<a<<" "<<b<<"\n";
#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n";
#define maxE(v) *max_element(v.begin(),v.end())
#define minE(v) *min_element(v.begin(),v.end())
#define sumV(v,x) accumulate(v.begin(),v.end(),x)
#define slower(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define supper(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define setprec(n) cout<<fixed<<setprecision(8)<<n<<"\n";
const int mod=1000000007;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


long long power(long long x,long long y){  
    long long ans=1;
    x%=mod;
    while(y>0){
        if(y&1) ans=(ans*x)%mod;
        y>>=1;
        x=(x*x)%mod;
    }
    return ans;
}


ll isPrime(ll n){
    if(n<=1) return 0;
    for (int i = 2; i*i <=n; i++)
    {
        if(n%i==0) {return 0;
        break;}
    }
    return 1;
}

ll lcm(ll a, ll b){  
    return (a*b)/(__gcd(a, b));  
} 

string decimal_to_binary(long long n){
    string s=bitset<32>(n).to_string();
    return s;
}

ll binary_to_decimal(string s){
    ll d=stoi(s,0,2); // 2 is d base of input nd from 0th index
    return d;
}

ll dig_sum(ll n){
    ll sum=0;
    string s=to_string(n);
    f(i,0,s.size()){
        sum+=s[i]-'0';
    }
    return sum;
}

vector<bool> prime_array(ll n){                         
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}
int main(){


    #ifdef LOCAL_PROJECT
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    vector<bool> p=prime_array(10000000);
    // ll pre[10000002]={};
    vector<ll> pre(10000002);
    f(i,2,10000002)pre[i]=pre[i-1]+p[i];
    pre[1]=1;
    
    
    ll t;cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll r=n/2;
        ll ans=pre[n]-pre[r];
        ans++;
        cout1(ans)
    }    
}