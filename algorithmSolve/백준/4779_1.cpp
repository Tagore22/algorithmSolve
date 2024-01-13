#include <iostream>
#include <cmath>

using namespace std;

// 4779번의 더 나은 풀이.
// 처음 string을 모두 공백으로 만든후 각 재귀 호출시 길이가 1인 상태일때만
// 그 부분을 - 으로 교체해주면 된다. 이후 string을 한번에 출력한다.
// 모든 배열의 원소를 하나씩 출력하는 것보다 string 계열로 한번에 출력하는 것이
// 훨씬 빠르다.

// 자세한 설명은 주석으로 남긴다.

string str;
int N;

// 반복되는 재귀 함수.
void MakeStr(int from, int to)
{
    // 현재 길이가 1이라면 현재 원소를 - 로 바꾸고 탈출한다.
    if (from == to)
    {
        str[from] = '-';
        return;
    }
    int size = (to - from + 1) / 3;
    // 앞부분과 뒷부분만 실행한다. 가운데 부분은
    // 변경될일이 없기에 무시한다.
    MakeStr(from, from + size - 1);
    MakeStr(to - size + 1, to);
}

void MakeAnswer()
{
    while (cin >> N)
    {
        // 매번 string을 초기화해주어야 한다.
        str.clear();
        int num = pow(3, N);
        str.resize(num, ' ');
        MakeStr(0, num - 1);
        cout << str << '\n';
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