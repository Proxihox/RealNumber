
#include <bits/stdc++.h>
#include <iostream>
//#include <boost/variant.hpp>
#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define vl vector<ll> 
#define vvl vector<vl> 
#define vpll vector<pll>
#define vvpll vector<vpll>
#define pb push_back
#define loop(n,i) for(ll i = 0; i < n; i++)
#define fa(i,v) for(auto &i:v)
using namespace std;

//using VarType = boost::variant<float,irr>;

class irr{
    map<ll,float> n;
    private:
    ll gcd(ll a, ll b){
    // Find Minimum of a and b
		int result = min(a, b);
		while (result > 0) {
			if (a % result == 0 && b % result == 0) {
				break;
			}
			result--;
		}
		return result;
	}
    unordered_map<ll,float> primes(int n) { 
        unordered_map<ll,float> primefs;
        while (n % 2 == 0) 
        { 
            primefs[2] += 1;
            n = n/2; 
        } 
    
        // n must be odd at this point. So we can skip 
        // one element (Note i = i +2) 
        for (int i = 3; i <= sqrt(n); i = i + 2) 
        { 
            // While i divides n, print i and divide n 
            while (n % i == 0) 
            { 
                primefs[i] += 1;
                n = n/i; 
            } 
        } 
    
        // This condition is to handle the case when n 
        // is a prime number greater than 2 
        if (n > 2) primefs[n] += 1;
        return primefs;
    }

    float deciform(){
        float x = 1;
        fa(t,n){
            x *= pow(t.first,t.second);
        }
        return x;
    }
    float deciform(irr num){
        float x = 1;
        fa(t,num.n){
            x *= pow(t.first,t.second);
        }
        return x;
    }
    
    public:
    irr(){
        n;
    }
    irr(ll a){
        unordered_map<ll,float> f = primes(a);
        fa(x,f){
            n[x.first] +=x.second; 
        }
    }

    void print(){
        cout << deciform() << "\n";
    }

    void desc(){
        fa(x,n){
            cout << x.first << "^" << x.second << "\n";
        }
    }

    irr operator*(irr const& obj)
    {
        irr res;
        res.n = n;
        fa(x,obj.n){
            res.n[x.first] += x.second;
        }
        return res; 
    }
    // irr operator++(int a)
    // {
    //     fa(x,n){
    //         n[x.first] += x.second;
    //     }
    //     return *this; 
    // }
    irr operator*(ll const& num)
    {
        irr res;
        res.n = n;
        irr obj(num);
        fa(x,obj.n){
            res.n[x.first] += x.second;
        }
        return res;
    }
    // irr operator+(ll const& num)
    // {
    //     double f = deciform();
    //     f += num;
    //     return irr(f);
    // }
    irr operator/(irr const& obj)
    {
        irr res;
        res.n = n;
        fa(x,obj.n){
            res.n[x.first] -= x.second;
        }
        return res;
    }
    irr operator/(ll const& num)
    {
        irr res;
        res.n = n;
        irr obj(num);
        fa(x,obj.n){
            res.n[x.first] -= x.second;
        }
        return res;
    }
    bool operator==(ll const& num)
    {
        double x = deciform();
        if(x == num) return true;
        else return false;
    }
    bool operator==(irr const& num)
    {
        double x = deciform();
        double y = deciform(num);
        if(x == y) return true;
        else return false;
    }

    void exp(float b){
        fa(x,n){
            n[x.first] = x.second*b;
        }
    }

};

irr pow(irr a,float b){
    a.exp(b);
    return a;
}

int main(){
	irr a(2);
    irr b(8);
    a = (pow(a,float(1)/2));
    a = a*2;
    a = pow(a,2);
    cout << (a == b) << "\n";
    double c = 2;
    double d = 8;
    c = (pow(c,float(1)/2));
    c = c*2;
    c = pow(c,2);
    cout << (c == d) << "\n";
}