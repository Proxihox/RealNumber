
#include <bits/stdc++.h>
#include <iostream>
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
	friend ostream& operator<<(ostream& os, const frac& obj) {
        os << obj.numer << "/" << obj.denom;
        return os;
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
	frac operator%(ll const& obj)
    {
        frac res;
		ll x = (numer/denom)%obj;
		return frac(x) + fractional();
    }
	frac operator++(int)
    {
        frac temp = *this;
        numer = numer + denom;
        return temp;
    }
	frac operator--(int)
    {
        frac temp = *this;
        numer = numer - denom;
        return temp;
    }
	frac operator++()
    {
		numer = numer + denom;
        return *this;
    }
	frac operator--()
    {
		numer = numer - denom;
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
	bool operator<(frac const& obj)
    {   
        if(obj.numer*denom < numer*obj.denom) return false;
        else return true;
    }
	bool operator>=(frac const& obj)
    {   
        if(obj.numer*denom >= numer*obj.denom) return false;
        else return true;
    }
	bool operator<=(frac const& obj)
    {   
        if(obj.numer*denom <= numer*obj.denom) return false;
        else return true;
    }


	// To-do more operators like post increment



	frac fractional(){
        frac res;
        res.numer = numer%denom;
        res.denom = denom;
        return res;
    }

    explicit operator int() const {
        return numer/denom;
    }
	explicit operator ll() const {
        return numer/denom;
    }
    explicit operator double() const {
        return ((double)numer)/denom;
    }



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

int main(){
	frac a(5,3),b(2,5);
	frac c = a+b;
	cout << c << "\n";
	c = a*b;
	cout << c << "\n";
	c = a-b;
	cout << c << "\n";
	c = a/b;
	cout << c << "\n";
	cout << c-- << "\n";
	cout << --c << "\n";
	cout << ++c << "\n";
	cout << c++ << "\n";
}