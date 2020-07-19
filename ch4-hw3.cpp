/*
#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
*/

class Array2{

private: 
    int h, w; 
    int **iar;

public:
    Array2(): h(0), w(0), iar(NULL){}
    Array2(int m, int n): h(m), w(n)
    {
        iar = new int*[h];
        for(int i = 0; i < h; i++)
            iar[i] = new int [w];
    }
    ~Array2()
    {
        if(iar)
        {
            for(int i = 0; i < h; i++)
                delete [] iar[i];
            delete [] iar;
        }
    }
    int*& operator[](int m)
    {
        return iar[m];
    }
    const int operator()(int m, int n)
    {
        return iar[m][n];
    }
    Array2& operator=(const Array2& a)
    {
        if(iar == a.iar) return *this;
        if(iar)
        {
            for(int i = 0; i < h; i++)
                delete [] iar[i];

            delete [] iar; 
        }
        if(a.iar)
        {
            h = a.h; w = a.w;
            iar = new int* [h];
            for(int i = 0; i < h; i++)
            {
                iar[i] = new int [w];
                for(int j = 0; j < w; j++)
                    iar[i][j] = a.iar[i][j];
            } 
        }
        else
        {
            iar = 0;
            h = w = 0;
        }

        return *this;

    }
};

/*
int main() {
    Array2 a(3,4);
    int i,j;
    
    for( i = 0;i < 3; ++i )
        for( j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b; b = a;
    for( i = 0;i < 3; ++i ) {
        for( j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    
    return 0;
}
*/