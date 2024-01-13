#include <iostream>
#include <cmath>

using namespace std;

// 풀이.
// 분할 정복과 재귀를 이용한 문제다. 문자열을 3등분하여 가운데 부분은 공백으로 바꾸고 나머지 두부분을 다시
// 재귀 함수를 통하여 다시 나누기를 반복한다. 만약 문자열의 길이가 1이라서 더이상 3등분을 할수 없다면
// - 를 출력하고 탈출하면 된다.

// 자세한 설명은 주석으로 남긴다.

int N;

// 반복되는 재귀 함수.
void MakeStr(int from, int to)
{
    // from == to라면 현재 길이는 1이므로 더이상 3으로 나눌수없다.
    // 따라서 - 를 출력하고 탈출한다.
    if (from == to)
    {
        cout << '-';
        return;
    }
    // 현재 길이를 3등분하여 앞부분을 재귀함수로 호출한다.
    int size = (to - from + 1) / 3;
    MakeStr(from, from + size - 1);
    // 가운데 부분은 공백으로 바꾼다.
    for (int i = 0; i < size; ++i)
        cout << ' ';
    // 뒷부분을 호출한다.
    MakeStr(to - size + 1, to);
}

void MakeAnswer()
{
    while (cin >> N)
    {
        MakeStr(0, pow(3, N) - 1);
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}