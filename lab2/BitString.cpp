#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include "BitString.h"

//конструкторы
BitString::BitString() {
    _size = 1;
    str = new unsigned char[1];
    str[0] = '0';
}

BitString::BitString(const size_t & n) {
    _size = n;
    str = new unsigned char[_size];
    for(size_t i = 0; i < _size; ++i)
        str[i] = 0;
}

BitString::BitString(const std::initializer_list<unsigned char> &t) {
    _size = t.size();
    str = new unsigned char[_size];
    size_t a = _size - 1;

    for(int elem: t) {
        if(str[elem] != '0' and str[elem] != '1') {
            throw std::invalid_argument("1.BitString must contain only 0 or 1");
            str[a--] = elem; 
        }
    }

}

BitString::BitString(const std::string &t) {
    _size = t.size();
    str = new unsigned char[_size];

    for(int i = 0; i < _size; ++i) {
        if(t[i] != '0' and t[i] != '1') {
            delete[] str;
            throw std::invalid_argument("2.BitString must contain only 0 or 1");
        }
        str[i] = t[i];
    }
}

BitString::BitString(const BitString &other) {
    _size = other._size;
    str = new unsigned char[_size];
    for(size_t i = 0; i < _size; ++i) {
        str[i] = other.str[i];
    }
}

BitString::BitString(BitString &&   other) noexcept {
    _size = other._size;
    str = other.str;
}

//деструктор
BitString::~BitString() noexcept {
    _size = 0;
    delete[] str;
    str = nullptr;
}

//методы//


//геттеры

int BitString::GetSize() {
    return _size;
}

unsigned char* BitString::GetStr() {
    return str;
}

int BitString::change_10() {
    change = 0;
    int base = 1;
    for(int i = _size - 1; i >= 0; --i) {
        if(str[i] == '1') {
            change += base;
        }
        base *= 2;
    }
    return change;
}

//арифметические операции
std::string BitString::plus(const BitString &other) {
    int reverse = this-> change + other.change;
    std::string result;
    while(reverse) {
        if(reverse%2 == 1)
            result.push_back('1');
        else 
            result.push_back('0');
        reverse /= 2;
        
    }
    std::reverse(result.begin(), result.end());

    return result; 
}

std::string BitString::minus(const BitString &other) {
    int reverse = this-> change - other.change;
    if(reverse < 0) {
        return "negative number";
    }
    if(reverse == 0) {
        return "0";
    }
    std::string result;
    while(reverse) {
        if(reverse%2 == 1)
            result.push_back('1');
        else 
            result.push_back('0');
        reverse /= 2;
        
    }
    std::reverse(result.begin(), result.end());    
    return result; 
}

BitString BitString::copy() {
    BitString res;
    for(size_t i = 0; i < _size; ++i) {
        res.str[i] = str[i];
    }
    return res;
}

//операции сравнения

std::string BitString::larger(const BitString &other) {
    if(this -> change > other.change)
        return "true" ;
    else 
        return "false";
}

std::string BitString::smaller(const BitString &other) {
    if(this -> change < other.change)
        return "true" ;
    else 
        return "false";
}

std::string BitString::equal(const BitString &other) {
    if(this -> change == other.change)
        return "true" ;
    else 
        return "false";
}

//операции со битовыми строками

std::string BitString::_and(const BitString &other) {
    std::string ans;
    if(this-> _size != other._size) {
        ans = "Строки имеют разную длину";
        return ans;
    }
    
    for(int i = 0; i < _size; ++i) {
        if(str[i] == '1' and other.str[i] == '1')
            ans.push_back('1');
        else 
            ans.push_back('0');
    }
    return ans;
    
}

std::string BitString::_or(const BitString &other) {
    std::string ans;
    if(this-> _size != other._size) {
        ans = "Строки имеют разную длину";
        return ans;
    }

    for(int i = 0; i < _size; ++i) {
        if(str[i] == '0' and other.str[i] == '0')
            ans.push_back('0');
        else 
            ans.push_back('1');
    }
    return ans;
}

std::string BitString::_xor(const BitString &other) {
    std::string ans;
    if(this-> _size != other._size) {
        ans = "Строки имеют разную длину";
        return ans;
    }

    for(int i = 0; i < _size; ++i) {
        if((str[i] == '0' and other.str[i] == '0') or (str[i] == '1' and other.str[i] == '1'))
            ans.push_back('0');
        else 
            ans.push_back('1');
    }
    return ans;
}

std::string BitString::_not() {
    std::string s;
    for(int i = 0; i < _size; ++i) {
        if(str[i] == '0')
            s.push_back('1');
        else   
            s.push_back('0');
    }
    return s;
}

//uraaa kanikuly rabotay pls    