#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

class Node {
    public:
    int val;
    Node *left,*right;
    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll to_number(string s) {
    ll ans = 0;
    int n = s.size(),i;
    for(i=0;i<n;i++) {
        ans = ans*10 + (s[i]-'0');
    }
    
    return ans;
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int t,cs=0;
    cin>>t;
    while(t--) {
        cs++;
        ll n,i,j,k;
        cin>>n;
        vector<ll> v(n);
        unordered_map<ll,ll> mp;
        bool flag = true;
        if(n%2) flag = false;
        for(i=0;i<n;i++) {
            cin>>v[i];
            mp[v[i]]++;
            if(mp[v[i]] > n/2) flag = false;
        }
        sort(v.begin(),v.end());
        vector<ll> arr(n);
        j = 0;
        for(i=0;i<n;i+=2) {
            arr[i] = v[j++];
        }
        
        for(i=1;i<n;i+=2) {
            arr[i] = v[j++];
        }
        
        for(i=1;i<n-1;i++) {
            if((arr[i] < arr[i+1] && arr[i] < arr[i-1]) || (arr[i] > arr[i+1] && arr[i] > arr[i-1])) {
                continue;
            }
            else {
                flag = false;
            }
        }
        
        
        if((arr[0] < arr[1] && arr[0] < arr[n-1]) || (arr[0] > arr[1] && arr[0] > arr[n-1])) {
            ll temp;
        }
        else {
            flag = false;
        }
        
        if((arr[n-1] < arr[0] && arr[n-1] < arr[n-2]) || (arr[n-1] > arr[0] && arr[n-1] > arr[n-2])) {
            ll temp;
        }
        else {
            flag = false;
        }        
        
        if(flag) {
            cout<<"YES\n";
            for(auto it:arr) cout<<it<<" ";
            cout<<endl;
        }
        else {
            cout<<"NO\n";
        }
        
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
