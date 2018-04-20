#include <complex.hpp>
int main() {  
  Complex c1{};
  Complex c2{3};
  Complex c3{1, 4};
  
  cout << c1 << endl;
  cout << c2 << endl;
  cout << c3 << endl;
  
  Complex c4{c3};
  Complex c5;
  c5 = c4;
  
  cout << c4 << endl;
  cout << c5 << endl;
  
  cout << c2 + c5 << endl;
  cout << c2 - c5 << endl;
  cout << c2 * c5 << endl;
  cout << c2 / c5 << endl;
  
  cout << boolalpha;
  cout << (c2 != c5) << endl;
  cout << (c3 == c5) << endl;
  
  cout << static_cast<double>(c5) << endl;
  cout << c5[0] << "," << c5[1] << endl;
  
  cin >> c1;
  ofstream output{ "complex.bin" };
  
  ifstream input{ "complex.bin" };
  input >> c1;
  
  auto c6 = Complex::from_string("(1,2)");
  cout << c6 << endl;
  
  c1.swap(c6); 
  cout << c1 << endl;
  
  cout << !c1 << endl;
  cout << c5[2] << endl;
}
