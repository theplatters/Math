//
// Created by franFactorRing on 27.10.22.
//

#ifndef COMPALG_FACTORRING_H
#define COMPALG_FACTORRING_H

#include <iosfwd>
#include <array>

template <class T, T p>
class FactorRing {
private:
    T val;
public:
    FactorRing(){
        val();
    }
    explicit FactorRing(T val) : val(((val % p) + p) % p) {}

    friend FactorRing operator+(T lhs, T rhs){
        return FactorRing(lhs.val + rhs.val);
    }

    friend FactorRing operator+(FactorRing lhs, int rhs){
        return lhs + FactorRing(rhs);
    }

    friend FactorRing operator+(int lhs, FactorRing rhs){
        return rhs + FactorRing(lhs);
    }

    friend FactorRing operator*(FactorRing lhs, FactorRing rhs){
        return FactorRing(lhs.val * rhs.val);
    }

    friend FactorRing operator*(FactorRing lhs, int rhs){
        return FactorRing(lhs.val * rhs);
    }

    friend FactorRing operator*(int lhs, FactorRing rhs){
        return FactorRing(lhs * rhs.val);
    }

    friend FactorRing operator-(FactorRing lhs,FactorRing rhs){
        return FactorRing(lhs.val - rhs.val);
    }


    friend FactorRing operator-(FactorRing lhs,int rhs){
        return FactorRing(lhs.val - rhs);
    }

    friend FactorRing operator-(int lhs,FactorRing rhs){
        return FactorRing(lhs - rhs.val);
    }



    auto operator<=>(const FactorRing& a) const = default;

    FactorRing& operator=(int a){
        setVal(a);
        return *this;
    }

    FactorRing& operator++(){
        val = (val++) % p;
        return *this;
    }

    const FactorRing operator++(int){
        T nv = val;
        return FactorRing(++nv);
    }

    FactorRing& operator--(){
        T nv = val;
        return FactorRing(--nv);
    }

    const FactorRing operator--(int){
        val = (val--) % p;
        return *this;
    }

    friend FactorRing operator/(FactorRing lhs, FactorRing rhs){
        return FactorRing(lhs.val /rhs.val);
    }

    friend FactorRing operator%(FactorRing lhs, FactorRing rhs){
        return FactorRing(lhs.val % rhs.val);
    }

    friend std::array<FactorRing,3l> gcd(FactorRing lhs, FactorRing rhs) {
        auto t = T::gcd(lhs.val,rhs.val);
        return {{t[0]},{t[1]},{t[2]}};
    }


    void setVal(int v) {
        FactorRing::val = v % p;
    }

    friend std::ostream &operator<<(std::ostream &os, const FactorRing &FactorRing) {
        os << FactorRing.val;
        return os;
    }
};


#endif //COMPALG_FACTORRING_H
