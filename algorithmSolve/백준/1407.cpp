#include <iostream>

using namespace std;

long long A, B;

long long Calcul(long long num)
{
    long long answer = 0;
    long long now = 1;
    while (num > 0)
    {
        if (num % 2 != 0)
            answer += (num / 2 + 1) * now;
        else
            answer += num / 2 * now;
        num /= 2;
        now *= 2;
    }
    return answer;
}

void MakeAnswer()
{
    cout << Calcul(B) - Calcul(A - 1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}