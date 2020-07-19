#include <iostream>
using namespace std;


class CCar; 
class CTyre; 
class CEngine;
class CDriver;


class Crectangle
{
private: 
	int w, h, id;
	static int TotalArea;
	static int TotalNumber;
	static int CurrentId;

public:
	Crectangle(int w_, int h_, int id);
	Crectangle(Crectangle &);
	~Crectangle();
	static Crectangle Add(Crectangle &, Crectangle &);
	static void PrintTotal();
};

int Crectangle::TotalNumber = 0;
int Crectangle::TotalArea = 0;
int Crectangle::CurrentId = 0;

Crectangle Crectangle::Add(Crectangle &a, Crectangle &b)
{
	Crectangle c(a.w+b.w, a.h+b.h, CurrentId++);
	return c;
}

Crectangle::Crectangle(Crectangle &r)
{
	TotalArea += r.w * r.h;
	TotalNumber ++;
	w = r.w; h = r.h;
	id = CurrentId++;

}

Crectangle::Crectangle(int w_, int h_, int id_=0)
{
	w = w_; h = h_;
	TotalArea += w * h;
	TotalNumber ++;
	id = CurrentId++;
	cout << "construct rectangle id: " << id << "\n";

}

Crectangle::~Crectangle()
{
	TotalArea -= w * h;
	TotalNumber --;
	cout << "destruct rectangle id: "<< id << "\n";
}

void Crectangle::PrintTotal()
{
	cout << TotalNumber << "," << TotalArea << "\n";
}


class CTyre
{
private:
	int radius, width;
public: 
	CTyre(int r, int w):radius(r), width(w){}
};

class CEngine
{

};


class CDriver
{
public: 
	void ModifyCar(CCar *);
};



class CCar
{
private: 
	int price; 
	CTyre tyre; 
	CEngine engine;

friend void CDriver::ModifyCar(CCar *);

public:
	CCar(int, int, int);
	~CCar();
};










CCar::CCar(int p, int tr, int tw): price(p), tyre(tr, tw)
{

};

CCar::~CCar()
{

}

void CDriver::ModifyCar(CCar *pcar)
{
	pcar -> price += 1000;
}
int main()
{
	CCar car(20000, 17, 225);
	return 0;
}