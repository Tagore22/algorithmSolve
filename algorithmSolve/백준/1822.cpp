#include <iostream>
#include <set>

using namespace std;

// 풀이.
// 주먹구구식(?) 풀이. set에 A 배열을 집어넣고 다시 B 배열만큼을 제외한다. 그 이후 남아있는
// 수들을 출력한다. 다만 연관 컨테이너를 사용하는만큼 매우 느렸다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n1, n2;
    cin >> n1 >> n2;
    set<int> board;
    int num;
    for (int i = 0; i < n1; ++i)
    {
        cin >> num;
        board.insert(num);
    }
    for (int i = 0; i < n2; ++i)
    {
        cin >> num;
        board.erase(num);
    }
    cout << board.size() << '\n';
    for (auto& ans : board)
        cout << ans << ' ';
    cout << '\n';
    return 0;
}