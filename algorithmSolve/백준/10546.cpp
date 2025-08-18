#include <iostream>
#include <set>

using namespace std;

// 풀이.
// 문자열이 아닌 char 배열에 xor 연산을 통해서 모든 문자열들을
// 저장후 다시 xor 연산을 통해서 문자들을 지우는 방식으로도 풀 수 있다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    multiset<string> board;
    for (int iter = 0; iter < N; ++iter)
    {
        string str;
        cin >> str;
        board.insert(str);
    }
    for (int iter = 0; iter < N - 1; ++iter)
    {
        string str;
        cin >> str;
        board.erase(board.find(str));
    }
    cout << *(board.begin()) << '\n';
    return 0;
}