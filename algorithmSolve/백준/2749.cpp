#include <iostream>

using namespace std;

//9471번 피사노 주기와 연계되는 문제이다. 피사노 주기를 통해서 피보나치 수열을 백만으로 나누면 주기는 150만임을 알수 있으므로
//피보나치 수열값을 100만으로 나눈 150만개의 배열을 미리 계산해놓고, 주어진 n을 150만으로 나누어 떨어지는 값을 인덱스로 하여
//배열값을 출력하면 된다.

int cashe[1500010];
long long N;
const int MODNUM = 1000000;

void CalculFibo()
{
    cashe[0] = 0;
    cashe[1] = 1;
    for (int i = 2; i < 1500005; ++i)
        cashe[i] = (cashe[i - 2] + cashe[i - 1]) % MODNUM;
}

void MakeAnswer()
{
    CalculFibo();
    cout << cashe[N % 1500000] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}