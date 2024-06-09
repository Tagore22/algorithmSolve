#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 풀이.
// 1822번의 더 빠른 풀이.
// set을 사용하지 않고 이분 탐색을 직접 사용하는 풀이다. 각 A와 B 배열을 입력받고
// A 배열을 순회하며 B 배열에 존재하지 않는 수들을 출력한다. set을 사용하지 않았기에
// 속도는 2배이상 빨랐다. 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n1, n2;
    cin >> n1 >> n2;
    int board1[500000], board2[500000];
    for (int i = 0; i < n1; ++i)
        cin >> board1[i];
    for (int i = 0; i < n2; ++i)
        cin >> board2[i];
    sort(board1, board1 + n1);
    sort(board2, board2 + n2);
    int num = 0;
    string answer = "";
    for (int i = 0; i < n1; ++i)
    {
        if (!binary_search(board2, board2 + n2, board1[i]))
        {
            ++num;
            answer += to_string(board1[i]) + " ";
        }
    }
    cout << num << '\n';
    cout << answer << '\n';
    return 0;
}