#include <iostream>

using namespace std;

// 풀이.
// 처음에 b의 위치를 옮기기 위해 붙어있는 b와 떨어져 있는 b를 고려하는 등 너무 어렵게 접근했다.
// 실제 풀이는 그냥 주어진 문자열중 붙어 있는 a들을 만들기 위해 슬라이드 윈도우의 원리를 이용하여
// a의 개수들만큼 2중 순회하여 b의 최소값을 구하면 된다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    int ssize = str.size(), anum = 0;
    // a개의 개수를 구한다.
    for (int i = 0; i < ssize; ++i)
        if (str[i] == 'a')
            ++anum;
    // 원형 배열처럼 앞뒤가 연결되어 있다고 문제에 제시되어 있기에 문자열을 두번 반복하여
    // 구현한다.
    str += str;

    int answer = 1000001;
    // 맨 처음부터 마지막까지 순회하며 a개수만큼의 길이를 가진 각 문자열중 b가 등장하는 최소값을 구한다.
    for (int i = 0; i < ssize; ++i)
    {
        int bnum = 0;
        for (int j = 0; j < anum; ++j)
        {
            if (str[i + j] == 'b')
                ++bnum;
        }
        answer = min(answer, bnum);
    }

    cout << answer << '\n';
    return 0;
}