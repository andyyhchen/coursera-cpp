#include <string>
#include <iostream>
using namespace std; 

int main()
{

	char name[50];
	int age, id, s1, s2, s3, s4;
	char mark;

	cin.getline(name, 50, ',');
	cin >> age >> mark >> id >> mark >> s1 >> mark >> s2 >> mark >> s3 >> mark >> s4;
	cout << name << "," << age << "," << id << "," << (s1+s2+s3+s4)/4<<"\n";

	return 0;
}