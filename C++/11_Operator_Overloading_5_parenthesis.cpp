#include<iostream>
using namespace std;

class Matrix{
    int val;
    int ar[4][4];
public:
    Matrix()
    {
        val = 0;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                ar[i][j]=0;
    }
    int& operator()(int row,int col);
    const int& operator()(int row,int col) const;
    void operator()();
    int& operator()(int v);
};

int& Matrix::operator()(int row,int col)
{
    return ar[row][col];
}

void Matrix::operator()()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cout<<ar[i][j]<<" ";
        cout<<endl<<endl;
    }
}

int& Matrix::operator()(int v)
{
    val += v;
    return val;
}

int main()
{
    Matrix mat;

    int cnt = 0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            mat(i,j)= ++cnt;

    mat();

    cout<<mat(10)<<endl;
    cout<<mat(20)<<endl;

    return 0;
}
