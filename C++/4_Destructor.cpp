#include <iostream>
using namespace std;


class IntArray
{
private:
	int *m_array;
	int m_length;

public:
	IntArray(int length)
	{
		m_array = new int[length];
		m_length = length;
	}

	~IntArray() // destructor
	{
		// Dynamically delete the array we allocated earlier
		cout<<"Delete Array\n";
		delete[] m_array;
	}

	void setValue(int index, int value) { m_array[index] = value; }
	int getValue(int index) { return m_array[index]; }

	int getLength() { return m_length; }
};

int main()
{
    IntArray Arr(10);
    {
        IntArray br = Arr;
    }
    cout<<endl;

	IntArray ar(10);
	for (int i=0; i < 10; i++)
		ar.setValue(i, i+1);

	cout << "The value of element 5 is: " << ar.getValue(5)<<endl;

	return 0;
}
