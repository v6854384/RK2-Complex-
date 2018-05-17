#include <iostream> 
#include <string> 
#include <sstream> 
#include <fstream> 

using namespace std; 

template <class T> 
class Complex{ 
  private: 
    std::pair<T, T>* Pair; 
  public: 
    Complex(); 
    Complex(T a); 
    Complex(T a, T b); 
    Complex(const Complex<T>& c); 
    auto swap_(Complex<T>& c) -> void; 
    auto operator=(const Complex<T>& c) -> Complex<T>&; 
    auto operator+(const Complex<T>& c) -> Complex<T>; 
    auto operator-(const Complex<T>& c) -> Complex<T>; 
    auto operator*(const Complex<T>& c) -> Complex<T>; 
    auto operator/(const Complex<T>& c) -> Complex<T>; 
    auto operator!() -> Complex<T>; 
    auto operator==(const Complex<T>& c) -> bool; 
    auto operator!=(const Complex<T>& c) -> bool; 
    auto operator[](T index) -> T; 
    static Complex<T> from_string(const string& str); 
    template <class T1> 
    friend auto operator«(ostream&, const Complex<T1>& c) -> ostream&; 
    template <class T2,class T3> 
    friend auto operator»(T2&, Complex<T3>& c) -> istream&; 
    ~Complex(); 
}; 
template <class T> 
Complex<T>::Complex(){ 
  Pair=new pair<T,T>(); 
} 
template <class T> 
Complex<T>::Complex(T a){ 
  Pair=new pair<T,T>(a,0); 
} 
template <class T> 
Complex<T>::Complex(T a, T b){ 
  Pair=new pair<T,T>(a,b); 
} 
template <class T> 
Complex<T>::Complex(const Complex<T>& c){ 
  Pair=new pair<T,T>(c.Pair->first,c.Pair->second); 
} 
template <class T> 
auto Complex<T>::swap_(Complex<T>& c) -> void{ 
  swap(Pair->first,c.Pair->first); 
  swap(Pair->second,c.Pair->second); 
} 
template <class T> 
auto Complex<T>::operator=(const Complex<T>& c) -> Complex<T>&{ 
  Pair->first=c.Pair->first; 
  Pair->second=c.Pair->second; 
  return *this; 
} 
template <class T> 
auto Complex<T>::operator+(const Complex<T>& c) -> Complex<T>{ 
  return Complex<T>{Pair->first+c.Pair->first,Pair->second+c.Pair->second}; 
} 
template <class T> 
auto Complex<T>::operator-(const Complex<T>& c) -> Complex<T>{ 
  return Complex<T>{Pair->first-c.Pair->first,Pair->second-c.Pair->second}; 
} 
template <class T> 
auto Complex<T>::operator*(const Complex<T>& c) -> Complex<T>{ 
  return Complex<T>{Pair->first*c.Pair->first,Pair->second*c.Pair->second}; 
} 
template <class T> 
auto Complex<T>::operator/(const Complex<T>& c) -> Complex<T>{ 
  return Complex<T>{Pair->first/c.Pair->first,Pair->second/c.Pair->second}; 
} 
template <class T> 
auto Complex<T>::operator!() -> Complex<T>{ 
  return Complex<T>{Pair->first,-Pair->second}; 
} 
template <class T> 
auto Complex<T>::operator==(const Complex<T>& c) -> bool{ 
  return Pair->first==c.Pair->first && Pair->second==c.Pair->second; 
} 
template <class T> 
auto Complex<T>::operator!=(const Complex<T>& c) -> bool{ 
  return !(*this==c); 
} 

template <class T> 
auto Complex<T>::operator[](T index) -> T{ 
  if(index==0) 
    return Pair->first; 
  else if(index==1) 
    return Pair->second; 
} 
template <class T> 
Complex<T> Complex<T>::from_string(const string& str) { 
  Complex<T> c; 
  stringstream ss{str}; 
  ss»c; 
  return c; 
} 
template <class T1> 
auto operator«(ostream& os, const Complex<T1>& c) -> ostream&{ 
  os«c.Pair->first«","«c.Pair->second; 
  return os; 
} 
template <class T2,class T3> 
auto operator»(T2& in, Complex<T3>& c) -> istream&{ 
  in»c.Pair->first»c.Pair->second; 
  return in; 
} 
template <class T> 
Complex<T>::~Complex(){ 
  delete Pair; 
}
