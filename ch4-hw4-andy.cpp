#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;


#define MAXN 210

class Bign{

private: 
	int len;
	bool is_neg;
	int s[MAXN];
	char str[MAXN];

public: 
	Bign(const char* string="");
	Bign(int n);
	~Bign(){};
	Bign& operator=(const Bign& x);
	bool operator==(const Bign& x);
	Bign operator+(const Bign& x);
	Bign operator-(const Bign& x);
	Bign operator*(const Bign& x);
	Bign operator/(const Bign& x);
	bool operator>=(const Bign& x);
	static Bign scaling(Bign x, int exp);
	friend ostream& operator<<(ostream &os, const Bign& x);

};
Bign::Bign(int n)
{
	if(n < 0) {n=-n; is_neg=true;}
	else is_neg=false;

	memset(s, 0, MAXN * sizeof(int));
	memset(str, 0, MAXN * sizeof(char));
	int k = 0;
	while(n)
	{
		s[k++] = n%10;
		n /= 10;
	}
	len = k;
	for(int i = 0; i < len; i++)
		str[len-i-1] = s[i]+'0';
	if(len == 0) len++;
	str[len] = '\0';
}
Bign::Bign(const char* string)
{
	memset(s, 0, MAXN * sizeof(int));
	memset(str, 0, MAXN * sizeof(char));

	len = strlen(string);
	for(int i = 0; i < len; i++)
	{
		str[i] = string[i];
		s[len - i - 1] = int(str[i]-'0');
	}
	str[len] = '\0';
	is_neg = false;
}

ostream& operator<<(ostream &os, const Bign& x)
{
	if(x.is_neg) os << "-";
	for(int k = x.len - 1; k >= 0; k--)
		os << x.s[k];
	return os;
}

bool Bign::operator==(const Bign& x)
{
	if(this == &x) return true; 
	if (len != x.len || is_neg != x.is_neg) return false; 
	if(strcmp(str, x.str)) return false;
	for(int i = 0; i < len; i++)
	{
		if(s[i] != x.s[i]) return false; 
	}
	return true; 
}

Bign& Bign::operator=(const Bign& x)
{
	if(this == &x) return *this;
	memset(s, 0, MAXN*sizeof(int));
	memset(str, 0, MAXN*sizeof(char));
	is_neg = x.is_neg;
	len = x.len;
	for(int i = 0; i < len; i++)
	{
		s[i] = x.s[i];
		str[i] = x.str[i];
	}
	str[len] = '\0';
	return *this;
}

Bign Bign::operator+(const Bign& x)
{
	Bign a; 
	a = *this; 
	if(x.is_neg) return a - x;
	int length = max(a.len, x.len);
	for(int i = 0; i < length; i++)
	{
		a.s[i] += x.s[i];
		a.s[i+1] += a.s[i]/10;
		a.s[i] = a.s[i]%10;
	}
	if(a.s[length]) length++;
	a.len = length;
	a.is_neg = false;
	for(int i = a.len-1; i >= 0; i--)
		a.str[i] = char(a.s[a.len-1-i]+'0');
	a.str[a.len] = '\0';
	return a;
}

bool Bign::operator>=(const Bign& x)
{
	if(*this == x) return true;
	if(len > x.len) return true; 
	if(len < x.len) return false; 
	if(strcmp(str, x.str)>0) return true;
	return false; 
}

Bign Bign::operator-(const Bign& x)
{
	Bign a, b;
	if(*this >= x) {a=*this; b=x; a.is_neg=false;}
	else {a=x; b=*this; a.is_neg=true;}
	for(int i = 0; i < a.len; i++)
	{
		a.s[i] -= b.s[i];
		if(a.s[i] < 0)
		{
			a.s[i] += 10;
			a.s[i+1] --;
		}
	}
	while(!a.s[a.len-1] && a.len > 1) a.len--;
	for(int i = 0; i < a.len; i++)
		a.str[i] = char(a.s[a.len-1-i]+'0');
	a.str[a.len] = '\0';

	return a;

}

Bign Bign::operator*(const Bign& x)
{
	Bign c; 
	c.len = len + x.len + 1;
	for (int i = 0; i < len; i++)
	{			
		for (int j = 0; j < x.len; j++)
		{
			c.s[i + j] += s[i] * x.s[j];
			c.s[i + j + 1] += c.s[i + j] / 10;				
			c.s[i + j] = c.s[i + j] % 10;
		}
	}
	while(!c.s[c.len-1] && c.len > 1) c.len--;
	for(int i = 0; i < c.len; i++)
		c.str[i] = char(c.s[c.len-1-i]+'0');
	c.str[c.len] = '\0';

	return c;
}

Bign Bign::scaling(Bign x, int exp)
{
	static Bign ten("10");
	for(int i = 0; i < exp; i++)
		x = x * ten; 
	return x; 
}

Bign Bign::operator/(const Bign& x)
{
	static Bign n[11];
	for (int i = 0; i < 11; i++) {n[i] = Bign(i);}
	Bign c("0");
	if(*this==x) return n[1];
	if(!(*this >= x)) {return n[0];}
	Bign tmp = *this;
	for(int i = len-x.len; i >= 0; i--)
	{
		int t=0; 
		while(tmp >= n[t]*Bign::scaling(x, i)){t++;};
		tmp = tmp - n[t-1]*Bign::scaling(x, i);
		c = c + Bign::scaling(n[t-1], i);
	}
	return c;
}

/*
void test()
{
	bool pass = true; 
	for(int i = 0; i < 50; i++)
	{
		int a = rand() % 10000, b = rand() % 10000;
		Bign ba(a), bb(b);
		if(!(Bign(a/b) == ba/bb)) pass =false;
		if(!(Bign(a*b) == ba*bb)) pass = false;

		if(!(Bign(a-b) == ba-bb)) pass = false;
		if(!(Bign(a+b) == ba+bb)) pass = false;
	}
	if(pass) cout << "passed" << endl;
}
*/

int main()
{

	char s1[MAXN], s2[MAXN];
	char oper;
	cin >> s1 >> oper >> s2; 
	Bign a(s1), b(s2), c;
	switch (oper)
	{
		case '+':
			c = a + b;
			break;
		case '-':
			c = a - b;
			break;
		case '*':
			c = a * b;
			break;
		case '/':
			c = a / b;
			break;
	}
	
	cout << c << endl;

}