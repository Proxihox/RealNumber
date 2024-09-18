
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include "../term/term.cpp"
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



class rnum{
    private:
    public:
    term first_term(){
        fa(x,terms){
            return term(x.first)*x.second;
        }
    }
    rnum inverse(rnum num){
        rnum n;
        while(num.terms.size() != 1){
            term temp = num.first_term();
            num -= temp;
            n *= num - temp;
            num *= num-temp;
        }
        return n/(num.first_term());
    }

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

    
    void operator=(rnum const& x){
        terms.clear();
        fa(x,x.terms){
            terms[x.first] = x.second;
        }
    }

    rnum operator+(rnum const& x){
        cout << "called\n";
        rnum res = x;
        desc();
        res.desc();
        fa(i,terms){
            res.terms[i.first] += i.second;
            // term t = i.first;
            // t.desc();
            // cout  << " " << i.second << "\n";
        }
        res.desc();
        return res;
    }
    rnum operator-(rnum const& x){
        rnum res = x;
        fa(i,terms){
            terms[i.first] -= i.second;
        }
        return res;
    }

    rnum operator-=(rnum const& x){
        fa(i,x.terms){
            terms[i.first] -= i.second;
        }
        return *this;
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

    rnum operator*=(rnum const& x){
        rnum res = *this;
        vector<term> a = vectorise(x),b = vectorise();
        fa(i,a){
            fa(j,b){
                term k = i*j;
                res.terms[term(k.irr)] = k.r;
            }
        }
        *this = res;
        return *this;
    }


    rnum operator/(term const& x){
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

    bool operator!=(rnum num){
       fa(i,num.terms){
        if(terms[i.first] != i.second) return true;
       }
       fa(i,terms){
        if(num.terms[i.first] != i.second) return true;
       }
       return false;
    }


};

rnum pow(rnum a,frac b){
    vector<term> f = a.vectorise(a);
    rnum res;
    fa(i,f){
        term k = pow(i,b);
        res.terms[term(k.irr)] += k.r;
    }
    return res;
}