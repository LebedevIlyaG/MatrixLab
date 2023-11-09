

#include "Vector.h"

int main()
{
    int n, m, k, count;

    n = 5;

    TVector<int> A(n);
    A.Random();

    std::cout << A << std::endl << std::endl;

    TVector<int> B = A;
    B.Random();
    std::cout << B << std::endl << std::endl;

    TVector<int> C;

    C = A + B;

    std::cout << C << std::endl << std::endl;

    return 0;
}