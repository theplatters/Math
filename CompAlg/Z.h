//
// Created by franzs on 24.10.22.
//

#ifndef COMPALG_Z_H
#define COMPALG_Z_H

#include <ostream>
#include <numeric>
#include <tuple>
#include <array>
#include "gcd.h"

template <int p>
class Z;

template <int p>
std::array<Z<p>,3> gcd(Z<p> a, int b);

template <int p>
class Z {
public:
    Z(){
        val = 0;
    }

    Z(int val) : val(((val % p) + p) % p) {}

    friend Z operator+(Z lhs, Z rhs){
        return Z(lhs.val + rhs.val);
    }

    friend Z operator+(Z lhs, int rhs){
        return lhs + Z(rhs);
    }

    friend Z operator+(int lhs, Z rhs){
        return rhs + Z(lhs);
    }

    friend Z operator*(Z lhs, Z rhs){
        return Z(lhs.val * rhs.val);
    }

    friend Z operator*(Z lhs, int rhs){
        return Z(lhs.val * rhs);
    }

    friend Z operator*(int lhs, Z rhs){
        return Z(lhs * rhs.val);
    }

    friend Z operator-(Z lhs,Z rhs){
        return Z(lhs.val - rhs.val);
    }


    friend Z operator-(Z lhs,int rhs){
        return Z(lhs.val - rhs);
    }

    friend Z operator-(int lhs,Z rhs){
        return Z(lhs - rhs.val);
    }



    auto operator<=>(const Z& a) const = default;

    Z& operator=(int a){
        setVal(a);
      return *this;
    }

    Z& operator++(){
        val = (val++) % p;
        return *this;
    }

    const Z operator++(int){
        return Z(val + 1);
    }

    Z& operator--(){
        val = (val--) % p;
        return *this;
    }

    const Z operator--(int){
        return Z(val - 1);
    }



    void setVal(int v) {
        Z::val = v % p;
    }

    friend std::ostream &operator<<(std::ostream &os, const Z &z) {
        os << z.val;
        return os;
    }

    friend std::array<Z,3> xGCD(Z a, Z b){
        int x,y;
        int gcd = extendedGCD(a.val,b.val,x,y);
        std::array<Z, 3> arr = {Z(gcd),Z(x),Z(y)};
        return arr;
    }

    friend std::array<Z,3> gcd<p>(Z a, int b);

    Z invert();

    friend Z operator/(Z &lhs, Z &rhs) {
        return lhs * rhs.invert();
    }

private:
    int val;

};

template <int p>
std::array<Z<p>, 3> gcd(Z<p> a, int b) {
    int x,y;
    int gcd = extendedGCD(a.val,b,x,y);
    std::array<Z<p>, 3> arr = {Z<p>(gcd),Z<p>(x),Z<p>(y)};
    return arr;
}

template<int p>
Z<p> Z<p>::invert() {
    auto x = gcd(*this, p);
    return {x[1]};
}



#endif //COMPALG_Z_H
