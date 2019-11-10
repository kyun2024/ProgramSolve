#include <iostream>
#include <iomanip>

using namespace std;

double e=0.0;

template <int N>
struct Factorial{
    enum { value = N * Factorial<N-1>::value};
};

template <>
struct Factorial<0>{
    enum { value = 1 };
};

template <int N>
void forloop(){
    e += 1.0/Factorial<N>::value;
    cout << N << " " << setprecision(10) << e << endl;
    forloop<N+1>();
}

template<>
void forloop<8>(){
    e += 1.0/Factorial<8>::value;
    cout << 8 << " " << left << setw(11) << std::setfill('0') << e << endl;
    forloop<9>();
}

template <>
void forloop<10>(){
    //Done
}

int main(){
    cout << "n e" << endl << "- -----------" << endl;
    forloop<0>();
}