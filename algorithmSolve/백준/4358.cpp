#include <iostream>
#include <map>
#include <string>

using namespace std;

// 풀이
// 이 문제의 핵심은
//
// 1. 변수타입의 상관관계(승격)
// 2. 소수 N번째까지 출력하기
//
// 이 2가지이다. 첫번째 조건은 나누기에서 사용되는데 나무의 총 그루수 혹은 어떤 나무 수 K 둘중 하나가 부동소수점 타입이 아니라면
// 정확한 답이 나오지 않는다. 예를 들어 1 / 3 을 구할때 둘다 int형이라면 0이 나와서 0.3333을 구해야 하는 정답을 구할수 없다.
// 그래서 나무의 총 그루수를 뜻하는 tree_num은 double로 구현했다.

// 두번째 조건은 precision()과 fixed로 간단히 해결할수 있다.

map<string, int> board;
double tree_num = 0;

// 직접적으로 답을 구하는 함수. 총 그루수에서 현재 나무 K의 그루수를 나누고 100을 곱해 백분율을 구한후 출력한다.
void MakeAnswer()
{
    cout.precision(4);
    cout << fixed;
    for (auto iter = board.begin(); iter != board.end(); ++iter)
        cout << iter->first << ' ' << iter->second / tree_num * 100 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    while (getline(cin, str))
    {
        ++board[str];
        ++tree_num;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}