#include <iostream>

using namespace std;

int N;

int Calcul(int num)
{
    return num / 100 * 78;
}

void MakeAnswer()
{
    cout << Calcul(N) << ' ';
    cout << Calcul(N / 100 * 20) + (N / 100 * 80) << '\n';
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