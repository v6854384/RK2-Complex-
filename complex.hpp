#include <iostream> 
#include <string> 
#include <sstream> 
#include <fstream> 

using namespace std; 

template <class T> //шаблон класса (шаблон Т, где Т- это опререденный тип данных) (int в нашем случае)
class Complex{ 
  private: 
    std::pair<T, T>* Pair; //указатель типа pair, где pair - это структура данных, класс хранящий в себе два значения
  public: 
    Complex(); //пустой конструктор
    Complex(T a); //конструктор с одним значением
    Complex(T a, T b); //с  двумя
    Complex(const Complex<T>& c); //конструктор коипрования
    auto swap_(Complex<T>& c) -> void; //обмен полями у двух объектов класса
    auto operator=(const Complex<T>& c) -> Complex<T>&; //перегрузка операторов
    auto operator+(const Complex<T>& c) -> Complex<T>; //
    auto operator-(const Complex<T>& c) -> Complex<T>; //
    auto operator*(const Complex<T>& c) -> Complex<T>; //
    auto operator/(const Complex<T>& c) -> Complex<T>; //
    auto operator!() -> Complex<T>; //
    auto operator==(const Complex<T>& c) -> bool; //
    auto operator!=(const Complex<T>& c) -> bool; //
    auto operator[](T index) -> T; //перегрузка оператора получения по индексу
    static Complex<T> from_string(const string& str); //преобразование типа
    template <class T1> //новый шаблон для дружественных функций
    friend auto operator«(ostream&, const Complex<T1>& c) -> ostream&; //перегрузка операторов для загрузки в поток
    template <class T2,class T3>  //шаблоны для выгрузки из потока
    friend auto operator»(T2&, Complex<T3>& c) -> istream&; //перегрузка операторов для выгрузки из потока
    ~Complex(); //деструктор
}; //далее идет реализация
template <class T> //даем ф-ии понять, в какой тип данных ей необходимо развернутся
Complex<T>::Complex(){ //показываем, что ф-ия принадлежит классу
  Pair=new pair<T,T>();  //выделяем динамически память для укзаателя pair
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
