#include<iostream>
#include<bitset>


int main()
{
    std::cout<<"Md Elias Hassan Naim"<<std::endl;

    int a(0),x;
    a = 0b111;
    std::cout<<"a - > "<<a<<std::endl;

    std::cout<<"set\n";

    std::bitset<8>bits(1 | 8);
    std::cout<<bits<<std::endl;

    bits.set(5);
    std::cout<<bits<<std::endl;
    bits |= 2;
    std::cout<<bits<<std::endl;

    std::cout<<"\nFlip\n";

    bits.flip(2);
    std::cout<<bits<<std::endl;
    bits ^= 4;
    std::cout<<bits<<std::endl;

    std::cout<<"\nReset\n";

    bits.reset(5);
    std::cout<<bits<<std::endl;
    bits &= ~8;
    std::cout<<bits<<std::endl;

    std::cout<<"\nTest\n";

    x = bits.test(1);
    std::cout<<x<<std::endl;

    return 0;
}
