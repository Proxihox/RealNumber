
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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



class frac{

	public:
    ll numer;
	ll denom;
	
	frac(ll a,ll b){
		numer = a;
		denom = b;
	}
	frac(ll a){
		numer = a;
		denom = 1;
	}
	frac(){
		numer = 0;
		denom = 1;
	}

	
	void out(){
		cout << numer << "/" << denom << "\n";
	}
	
	frac operator+(frac const& obj)
    {
        frac res;
        res.numer = numer*obj.denom + obj.numer*denom;
        res.denom = denom*obj.denom;
        return reduced(res);
    }
	frac operator-(frac const& obj)
    {
        frac res;
        res.numer = numer*obj.denom - obj.numer*denom;
        res.denom = denom*obj.denom;
        return reduced(res);
    }

	frac operator*(frac const& obj)
    {
        frac res;
        res.numer = numer*obj.numer;
        res.denom = denom*obj.denom;
        return reduced(res);
    }
	frac operator/(frac const& obj)
    {
        frac res;
        res.numer = numer*obj.denom;
        res.denom = denom*obj.numer;
        return reduced(res);
    }
	frac operator++()
    {
		numer = numer + denom;
        return *this;
    }
	frac operator+=(frac const& obj)
    {
		numer = numer*obj.denom + obj.numer*denom;
        denom = denom*obj.denom;
        *this = reduced(*this);
        return *this;
    }
	frac operator-=(frac const& obj)
    {
		numer = numer*obj.denom - obj.numer*denom;
        denom = denom*obj.denom;
        *this = reduced(*this);
        return *this;
    }
    bool operator==(frac const& obj)
    {
		if(obj.numer == numer and obj.denom == denom) return true;
        else return false;
    }
    bool operator!=(frac const& obj)
    {
		if(obj.numer == numer and obj.denom == denom) return false;
        else return true;
    }
    bool operator>(frac const& obj)
    {   
        if(obj.numer*denom > numer*obj.denom) return false;
        else return true;
    }

    frac fractional(){
        frac res;
        res.numer = numer%denom;
        res.denom = denom;
        return res;
    }


    explicit operator int() const {
        return numer/denom;
    }
    explicit operator double() const {
        return ((double)numer)/denom;
    }


	// To-do more operators like post increment

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

	frac reduced(frac obj){
		frac res;
		ll g = gcd(obj.numer,obj.denom);
		res.numer = obj.numer/g;
		res.denom = obj.denom/g;
		return res;
	}
};


double pow(double x,frac y){
    return pow(pow(x,y.numer),float(1)/y.denom);
}


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
    }
    term(ll n){
        r = n;
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

    term operator=(term const& num){
        term res;
        res.r = num.r;
        res.irr = num.irr;
        return res;
    }

    term operator*(term const& num){
        term res = num;
        res.r*= r;
        fa(x,irr){
            res.irr[x.first] += x.second;
        }
        res.reduce();
        return res;
    }
    term operator/(term const& num){ // fix this
        term res = num;
        res.r /= r;
        fa(x,irr){
            res.irr[x.first] -= x.second;
        }
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

term pow(term a,frac b){
    term res(1);
    a.consolidate();
    //cout<< "check1\n";
    //a.desc();
    fa(x,a.irr){
        res.irr[x.first] = x.second*b;
    }
    a.reduce();
    //res.desc();
    res.reduce();
    return res;
}

class rnum{
    private:
    public:
    map<term,ll> terms;
     rnum(){
        terms = {};
    }
    
    rnum(ll a){
        terms[term(1)] = a;
    }


    rnum(term a){
        terms[term(a.irr)] = a.r;
    }

    void desc(){
        vector<term> b = vectorise();
        bool f = 0;
        fa(i,b){
            i.desc();
        }
        cout << "end\n";
    }

    vector<term> vectorise(){
        vector<term> res;
        fa(x,terms){
            res.push_back(term(x.first)*x.second);
        }
        return res;
    }
    vector<term> vectorise(rnum num){
        vector<term> res;
        fa(x,num.terms){
            res.push_back(term(x.first)*x.second);
        }
        return res;
    }
    rnum operator+(rnum const& x){
        rnum res = x;
        fa(i,terms){
            terms[i.first] += i.second;
        }
        return res;
    }
    rnum operator-(rnum const& x){
        rnum res = x;
        fa(i,terms){
            terms[i.first] -= i.second;
        }
        return res;
    }

    rnum operator*(rnum const& x){
        rnum res = 0;
        vector<term> a = vectorise(x),b = vectorise();
        fa(i,a){
            fa(j,b){
                term k = i*j;
                res.terms[term(k.irr)] = k.r;
            }
        }
        return res;
    }

    bool operator==(rnum num){
       fa(i,num.terms){
        if(terms[i.first] != i.second) return false;
       }
       fa(i,terms){
        if(num.terms[i.first] != i.second) return false;
       }
       return true;
    }

};

rnum pow(rnum a,frac b){
    vector<term> f = a.vectorise(a);
    rnum res(0);
    fa(i,f){
        term k = pow(i,b);
        res.terms[term(k.irr)] += k.r;
    }
    return res;
}

int main(){
    rnum a(2);
    rnum b(2);
    frac d(1,2);
    a = pow(a,d);
    b = b + a;
    b = b *a;
    a = a + 1;
    a = a*2;
    a.desc();
    b.desc();
    cout << (a == b) << "\n";
}