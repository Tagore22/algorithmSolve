#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 어렵지 않은 문제다. 각 접미사를 얻는다는 것은 앞에서부터 한자리씩 계속 빼는걸 의미하는데
// 이것은 string의 substr()로 쉽게 구현가능하다. 따라서 모든 접미사를 구한후 이것을 정렬하고
// 출력해주면 된다.

// 자세한 설명은 주석으로 남긴다.

string board[1000];
string str;

void MakeAnswer()
{
    int size = str.size();

    // 1. substr()을 이용하여 모든 접미사를 구한다. 문자열의 길이가 최대 1000이기에
    // 최대 1000의 연산량을 소모한다.
    for (int i = 0; i < size; ++i)
        board[i] = str.substr(i);

    // 2. 접미사들을 정렬한후 출력한다. sort()의 시간복잡도가 Nlogn이기에 31000만정도 연산량이
    // 소모된다.
    sort(board, board + size);
    for (int i = 0; i < size; ++i)
        cout << board[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}