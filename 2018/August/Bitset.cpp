#include<bits/stdc++.h>
//#include<bitset>
using namespace std;


int main()
{
    std::cout<<"Md Elias Hassan Naim\n"<<std::endl;
    int a(0),x;
    a = 0b111;
    cout<<"a -> "<<a<<endl;

    bitset<20>bits1;                    ///0 based index
    bitset<20>bits2(15);                ///decimal to binary
    bitset<20>bits3(string("1100"));    ///string to binary

    printf("bits1 - > %d\n",bits1);
    cout<<"bits1 - > "<<bits1<<endl;
    cout<<"bits2 - > "<<bits2<<endl;
    cout<<"bits3 - > "<<bits3<<endl;

    bitset<8>bits;
    bits[0]=1;
    bits[2]=1;
    bits[4]=bits[2];
    bits[6]=1;
    bits[7]=1;
    cout<<bits<<endl;
    bits[0]=bits[1];
    bits[4]=0;
    cout<<bits<<endl;

    int numberofOne = bits.count();
    cout<<"numberofOne - > "<<numberofOne<<endl;

    int numberofZero = bits.size()-numberofOne;
    cout<<"numberofZero - > "<<numberofZero<<endl;

    cout<<"bool representation of "<<bits<<" - > ";
    for(int i=bits.size()-1;i>=0;i--)
        cout<<bits.test(i)<<" ";
    cout<<endl;

    bitset<3>bits4,bits5(7);

    if(!bits4.any())    /// is One Exist ??
        printf("bits4 has no bit set\n");
    if(!bits5.none())   /// is Zero Exist ??
        printf("bits5 has all bit set\n");

    cout<<endl;
    cout<<"Set - Reset\n"<<endl;
    cout<<bits.set()<<endl;     ///set bit all
    cout<<bits.set(4,0)<<endl;  ///set in [pos] = 0
    cout<<bits.set(4)<<endl;    ///set bit is position
    cout<<bits.reset(4)<<endl;  ///reset bit in position
    cout<<bits.set(4,1)<<endl;  ///set in [pos] = 1
    cout<<bits.reset()<<endl;   ///reset bit all

    cout<<endl;
    cout<<"Flip\n"<<endl;
    cout<<bits.flip(4)<<endl;
    cout<<bits.flip()<<endl;

    printf("\nOperation\n\n");

    bitset<8>temp(1 | 8);
    cout<<temp<<endl;
    temp |= 4;
    cout<<temp<<endl;
    temp ^= 4;
    cout<<temp<<endl;
    temp &= ~8;
    cout<<temp<<endl;
    x = temp.test(4);
    cout<<x<<endl;

    return 0;
}
