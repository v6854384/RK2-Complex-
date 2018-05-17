#include <iostream> 
#include "complex.hpp" 

using namespace std; 

int main() 
{ 
Complex<int> c1{}; 
Complex<int> c2{3}; 
Complex<int> c3{1, 4}; 

cout « c1 « endl; 
cout « c2 « endl; 
cout « c3 « endl; 

Complex<int> c4{c3}; 
Complex<int> c5; 

c5 = c4; 

cout « c4 « endl; 
cout « c5 « endl; 

cout « c2 + c5 « endl; 
cout « c2 - c5 « endl; 
cout « c2 * c5 « endl; 
cout « c2 / c5 « endl; 

cout « boolalpha; 
cout « (c2 != c5) « endl; 
cout « (c3 == c5) « endl; 
 
cout « c5[0] « "," « c5[1] « endl; 

cin » c1; 
ofstream output{ "complex.bin" }; 
output « c1; 

ifstream input{ "complex.bin" }; 
input » c1; 

cout « c1 « endl; 

auto c6 = Complex<int>::from_string("1 2"); 

cout « c6 « endl; 

c1.swap_(c6); 

cout « c1 « endl; 

cout « !c1 « endl; 

cout « c5[2] « endl; 

return 0; 

}
