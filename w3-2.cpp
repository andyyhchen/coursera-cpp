#include <iostream>
using namespace std; 

class Complex {
public: 
	double real, imag; 
	Complex(double r, double i): real(r), imag(i)
	{
		cout << "complex const\n";
	}
	Complex AddOne()
	{
		this -> real ++;
		return *this;
	}
	void CallAddONe()
	{
		AddOne();
	}
	Complex(Complex &c){
		cout << "cpy constructor\n";
	}
	~Complex()
	{
		cout << "complex destruct\n";
	}
};


class Sample {
public:
	int value;
	void GetValue() const;
	void GetValue();
	void func();
	Sample(int v):value(v)
	{
		this->GetValue();
	}
	~Sample()
	{
		this->GetValue();
	}
};

void Sample::GetValue() const
{
	cout << "const get value" << this->value<< "\n";
}

void Sample::GetValue()
{
	cout << "normal get value \n";
	value = 1;
}

int main()
{

	const Sample s1(1); 
	Sample s2(2); 

	s1.GetValue();
	s2.GetValue();

}