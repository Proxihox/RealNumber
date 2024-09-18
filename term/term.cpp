
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include "../frac/frac.cpp"
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




class term{
    
    private:
    ll gcd(ll a, ll b){
		int result = min(a, b);
		while (result > 0) {
			if (a % result == 0 && b % result == 0) {
				break;
			}
			result--;
		}
		return result;
	}
    unordered_map<ll,ll> primes(int n) { 
        unordered_map<ll,ll> primefs;
        while (n % 2 == 0){ 
            primefs[2] += 1;
            n = n/2; 
        } 

        for (int i = 3; i <= sqrt(n); i = i + 2){ 
            while (n % i == 0){ 
                primefs[i] += 1;
                n = n/i; 
            } 
        } 
    
        if (n > 2) primefs[n] += 1;
        return primefs;
    }
    
    public:
    ll r;
    unordered_map<ll,frac> irr;
    term(){
        r = 0;
        irr[1] = 1;
    }
    term(ll n){
        r = n;
        //irr[1] = 1;
    }
    term(frac n){
        r = n.numer;
        irr[n.denom] = -1;
    }
    term(unordered_map<ll,frac> x){
        irr = x;
        r = 1;
    }
    void desc(){
        cout << "Rational :" << r << "\n";
        cout << "Irr :\n";
        fa(x,irr){
            cout << x.first << "^";
            x.second.out();
        }
    }
    void consolidate(){ // push everything into irr part
        unordered_map<ll,ll> ps = primes(r);
        fa(x,ps){
            irr[x.first] += x.second;
        }
        r = 1;
    }
    void reduce(){
        fa(x,irr){
            // cout << "!";
            // x.second.out();
            // cout << (int) x.second << "\n";
            //x.second.fractional().out();
            if(x.second > 1){
                r *= pow(x.first,(int) (x.second));
                irr[x.first] = (x.second.fractional());
            }
        }
    }

    double deciform() const {
        if(irr.size() != 0){
            double z = 0;
            fa(x,irr){
                z += pow(x.first,x.second);
            }
            return z*r;
        }
        else return r;
    }
    void print(){
        cout << deciform() << "\n";
    }

    void operator=(term const& num){
        r = num.r;
        irr = num.irr;
    }

    term operator*(term const& num){
        term res = num;
        res.r *= r;
        fa(x,irr){
            res.irr[x.first] += x.second;
        }
        res.reduce();
        return res;
    }
    term operator/(term num){ // fix this
        num.consolidate();
        this->consolidate();
        term res = *this;
        fa(x,irr){
            res.irr[x.first] -= x.second;
        }
        num.reduce();
        this->reduce();
        return res;
    } 
    bool operator==(term num){
        if(num.r != r) return false;
        fa(x,irr){
            if(num.irr[x.first] != x.second){
                return false;
            }
        }
        fa(x,num.irr){
            if(irr[x.first] != x.second){
                return false;
            }
        }
        return true;
    }

    bool operator!=(term num){
        if(num.r != r) return true;
        fa(x,irr){
            if(num.irr[x.first] != x.second){
                return true;
            }
        }
        fa(x,num.irr){
            if(irr[x.first] != x.second){
                return true;
            }
        }
        return false;
    }

    bool operator<(term const& num) const {
        double a = deciform(),b = num.deciform();
        if(a < b) return true;
        else return false;
    }

    bool operator>(term num){
        double a = deciform(),b = num.deciform();
        if(a > b) return true;
        else return false;
    }
};

term pow(term const& a,frac b){
    term res(1);
    term tmp = a;
    tmp.consolidate();
    //cout<< "check1\n";
    fa(x,tmp.irr){
        res.irr[x.first] = x.second*b;
    }
    tmp.reduce();
    res.reduce();
    return res;
}