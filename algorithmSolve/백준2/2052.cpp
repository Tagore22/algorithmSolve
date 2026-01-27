#include <iostream>

using namespace std;

// 출력문을 잘 살필 것.

int main()
{
    int N;
    cin >> N;
    double answer = 1;
    for (int i = 1; i <= N; ++i)
        answer /= 2;
    printf("%.*f", N, answer);
    return 0;
}