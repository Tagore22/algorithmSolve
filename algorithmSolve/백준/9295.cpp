#include <iostream>

using namespace std;

// 풀이.
// 두 주사위의 합을 각 케이스 번호와 함께 출력하는 문제.
// Input()을 호출하지 않았더니 28ms까지 속도가 떨어졌다. 코드수 줄이려고 그랬었으나
// 역시 호출해야겠다.

int T, a, b;

void MakeAnswer()
{
    for (int iter = 1; iter <= T; ++iter)
    {
        cin >> a >> b;
        cout << "Case " << iter << ": " << a + b << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}