#include <iostream>

using namespace std;

int main()
{
    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;

    int first = A % C != 0 ? A / C + 1 : A / C;
    int second = B % D != 0 ? B / D + 1 : B / D;

    int answer = L - max(first, second);
    cout << answer << '\n';
    return 0;
}