//
// Created by franz on 26.10.22.
//

#ifndef COMPALG_POLYNOMIAL_H
#define COMPALG_POLYNOMIAL_H

#include <list>
#include <algorithm>
#include <map>
#include <ostream>
#include <iostream>

template<typename T>
class Polynomial;


template<typename T>
class Polynomial {
private:
    std::map<unsigned int, T> coefficients;

public:
    Polynomial(const std::map<unsigned int, T> coefficients) : coefficients(coefficients) {
    }

    Polynomial(std::initializer_list<std::pair<unsigned int, T>> init) {
        for (const auto &[a, b]: init) {
            coefficients[a] = b;
        }
    }

    int deg() {
        if(coefficients.empty()) return -1;
        auto it = coefficients.rbegin();
        while (it->second == 0 && it != coefficients.rend()) it++;
        return (it != coefficients.rend() ? it->first : -1);
    }

    friend Polynomial operator+(Polynomial lhs, Polynomial rhs) {
        std::map<unsigned int, T> sum;
        auto higherDegree = (lhs.deg() > rhs.deg() ? lhs : rhs);
        auto lowerDegree = (lhs.deg() <= rhs.deg() ? lhs : rhs);
        for (const auto [k, c]: higherDegree.coefficients) {
            sum[k] = c + (lowerDegree.coefficients.contains(k) ? lowerDegree.coefficients[k] : 0);
        }
        return {sum};
    }

    friend Polynomial operator*(Polynomial lhs, Polynomial rhs) {
        std::map<unsigned int, T> prod;
        for (auto i = lhs.coefficients.begin(); i != lhs.coefficients.end(); ++i) {
            for (auto j = rhs.coefficients.begin(); j != rhs.coefficients.end(); ++j) {
                if (!prod.contains(i->first + j->first)) prod[i->first + j->first] = i->second * j->second;
                else prod[i->first + j->first] = prod[i->first + j->first] + i->second * j->second;
            }
        }
        return {prod};
    }

    friend Polynomial operator-(Polynomial lhs, Polynomial rhs) {
        std::map<unsigned int, T> sum;
        auto higherDegree = (lhs.deg() > rhs.deg() ? lhs : rhs);
        auto lowerDegree = (lhs.deg() <= rhs.deg() ? lhs : rhs);
        for (const auto [k, c]: higherDegree.coefficients) {
            sum[k] = c - (lowerDegree.coefficients.contains(k) ? lowerDegree.coefficients[k] : 0);
        }
        return {sum};
    }

    friend Polynomial operator/(Polynomial &lhs, Polynomial &rhs) {
        std::map<unsigned int, T> div = lhs.coefficients;
        std::map<unsigned int, T> quotient;
        std::map<unsigned int, T> rem;

        for (int i = lhs.deg() - rhs.deg(); i >= 0; --i) {
            quotient[i] = div[i + rhs.deg()] / rhs.coefficients[rhs.deg()];
            for (int j = rhs.deg(); j >= 0; --j) {
                div[i + j] = div[i + j] - rhs.coefficients[j] * quotient[i];
            }
        }
        return {quotient};
    }

    friend Polynomial operator%(Polynomial &lhs, Polynomial &rhs) {
        std::map<unsigned int, T> div = lhs.coefficients;
        std::map<unsigned int, T> quotient;
        std::map<unsigned int, T> rem;

        for (int i = lhs.deg() - rhs.deg(); i >= 0; --i) {
            quotient[i] = div[i + rhs.deg()] / rhs.coefficients[rhs.deg()];
            for (int j = rhs.deg(); j >= 0; --j) {
                div[i + j] = div[i + j] - rhs.coefficients[j] * quotient[i];
            }
        }

        for (int i = rhs.deg() - 1; i >= 0; --i) {
            rem[i] = div[i];
        }
        return {rem};
    }

    auto operator<=>(const Polynomial& a) const = default;


    friend std::array<Polynomial,3l> gcd(Polynomial lhs, Polynomial rhs) {
        Polynomial u{{0,0}};
        Polynomial t{{0,0}};
        Polynomial s = {{0,1}};
        Polynomial v = {{0,1}};
        while(rhs.deg() >= 0 || (rhs.coefficients[0] != 0 && rhs.deg() == 0)){
            auto q = lhs/rhs;
            auto b1 = rhs;
            rhs = lhs % rhs;
            lhs = b1;
            auto u1 = u;
            u = s - (q * u);
            s = u1;
            auto v1 = v;
            v = t - q * v;
            t = v1;
        }

        return {lhs,s,t};
    }

    friend std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial) {
        for (const auto &[k, val]: polynomial.coefficients) {
            os << val << " * x ^" << k << " + ";
        }
        return os;
    }
};


#endif //COMPALG_POLYNOMIAL_H
