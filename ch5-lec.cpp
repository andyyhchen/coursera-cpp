#include <iostream>
using namespace std;


class Bug{
private: 
	int nLegs; int nColor;
public: 
	int nType;
	Bug(int legs, int color)
	{
		nLegs = legs;
		nColor = color;
	}
	void PrintBug(){
		cout << "Bug with nLegs " << nLegs <<" and color " << nColor << endl; 
	}
};


class FlyBug: public Bug{
	int nWings;
public: 
	FlyBug(int legs, int color, int wings);
	void PrintFlyBug(){
		cout << "FlyBug with nLegs " << nLegs <<" and color " << nColor << endl; 
	}
};

FlyBug::FlyBug(int legs, int color, int wings):Bug(legs, color){
	nWings = wings;
}

int main()
{
	Bug b(4, 1);
	FlyBug fb(3,3,5);

}