
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
        fa(i,b){
            i.desc();
        }
        cout << "end\n";
    }
    void out(){
        cout << "Starting out\n";
        vector<term> b = vectorise();
        cout << "Vector_ size: " << b.size() << "\n";
        bool f = false;
        fa(i,b){
            if(f) cout << "+";
            else f = true;
            i.out();
        }
        cout << "\n";
    }

    vector<term> vectorise(){
        vector<term> res;
        cout << "Vector size: " << terms.size() << "\n";
        fa(x,terms){
            // cout << "loopy\n";
            // term(x.first).out();
            term t = term(x.first);
            res.push_back(t*x.second);
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
        rnum res = x;
        fa(i,terms){
            res.terms[i.first] += i.second;
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

    rnum operator-=(rnum const& x){
        fa(i,x.terms){
            terms[i.first] -= i.second;
        }
        return *this;
    }

    rnum operator*(rnum x){
        rnum res = 0;
        vector<term> a = x.vectorise(),b = vectorise();
        fa(i,a){
            fa(j,b){
                term k = i*j;
                res.terms[term(k.irr)] = k.r;
            }
        }
        return res;
    }

    rnum operator*=(rnum x){
        rnum res = *this;
        vector<term> a = x.vectorise(),b = vectorise();
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
        vector<term> a = {x},b = vectorise();
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
    cout << "Started power\n";
    vector<term> f = a.vectorise();
    rnum res;
    fa(i,f){
        term k = pow(i,b);
        k.out();
        res.terms[term(k.irr)] += k.r;
    }
    return res;
}