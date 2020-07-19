#include <iostream> 

using namespace std; 

class String{
private: 
	char *str; 
public:
	String(): str(NULL){}
	const char *c_str(){return str;}
	char *operator= (const char*s);
	String& operator= (const String &s);
	~String();
};

char * String::operator=(const char* s)
{
	if(str) delete [] str;
	if(s)
	{
		str = new char[strlen(s)+1];
		strcpy(str,s);
	}else
		str = NULL;

	return str; 
}

String& String::operator=(const String &s)
{
	if (str == s.str) return *this;
	if(str)
	{
		delete [] str;
		cout << "deleted" << endl;
	}
	str = new char[strlen(s.str)+1];
	cout << str << endl;

	strcpy(str, s.str);
	cout << strlen(s.str) << " " << strlen (str) << endl;


	return *this; 
}

String::~String(){
	if (str) delete [] str; 
}


class A{
	int a;
public: 
	A() {a=0;}
	friend void showA(A&);
};

void showA(A& x){
	cout << "A::a=" << x.a << endl;
}



/*
Dynamic array 
properties: 
arr[], length 

methods:
overload =, [] (n = a[i], a[i]=4)
constructor, copying constructor, push_back

*/

class CArray{
	int size;
	int *ptr; 

public:
	CArray(int s=0);
	CArray(CArray& A);
	~CArray();
	void push_back(int v);
	CArray& operator=(const CArray& a);
	int length() {return size;}
	int& operator[](int i);
};

CArray::CArray(int s):size(s)
{
	if(s==0)
		ptr = NULL;
	else
		ptr = new int[s];
}
int& CArray::operator[](int i)
{
	return ptr[i];
}

CArray::CArray(CArray &a)
{
	if(!a.ptr)
	{
		ptr = NULL;
		size = 0;
		return;
	}
	ptr = new int[a.size];
	memcpy(ptr, a.ptr, sizeof(int) * a.size);
	size = a.size; 
}

CArray::~CArray()
{
	if(ptr) delete [] ptr;
}

CArray& CArray::operator=(const CArray& a)
{
	if(ptr == a.ptr) return *this;
	if(a.ptr == NULL)
	{
		if(ptr) delete [] ptr; 
		ptr = NULL;
		size = 0;
		return *this;
	}
	if(size < a.size)
	{
		if(ptr) delete [] ptr; 
		ptr = new int[a.size];
	}
	memcpy(ptr, a.ptr, sizeof(int) * a.size);
	size = a.size; 
	return *this;
}

void CArray::push_back(int v)
{
	if(ptr)
	{
		int *tmpPtr = new int[size+1];
		memcpy(tmpPtr, ptr, sizeof(int) * size);
		delete [] ptr;
		ptr = tmpPtr;
	}
	else
	{
		ptr = new int [1];
	}
	ptr[size++] = v;
}

class CStudent
{
public: 
	int nAge;
	CStudent(int age=10):nAge(age){}
};


ostream& operator<<(ostream& o, const CStudent& s)
{
	o << s.nAge;
	return o;
}

int main()
{
	CStudent s1; 
	cout << s1 << endl;

	
}