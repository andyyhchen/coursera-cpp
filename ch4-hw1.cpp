/*
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:    
    double r,i;
public:    
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
*/

    Complex& operator=(const char *s){
 		char num[100];
 		int len = 0;
 		while(*s != '+') num[len++] = *s++;
 		num[len] = '\0';
 		double nr = atof(num);

 		len = 0;
 		s++; 
 		while(*s != 'i') num[len++] = *s++;
 		num[len] = '\0';
 		double ni = atof(num);

 		r = nr; 
 		i = ni;
 		return *this;
    }

// 在此处补充你的代码
/*};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
*/