#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// K번째 문자를 구하는 재귀 문제다. 이럴 때에는 보통 i번째에서 N개를
// 만들 수 있음을 이용해 K를 줄여나가야 하는데 예를 들어 N이 8이라고
// 해보자. S(1)가 그보다 가장 첫번째로 큰 10개를 가지고 있기에 우선
// S(2)부터는 생각할 필요도 없다. 그러면 S(0)의 개수보다는 크고 S(1)의
// 개수보다는 작은 상태이니 가운데 moo부터 오른쪽 moo안에 N번째가 존재한다는
// 것인데 이를 현재 N이 1인지, 혹은 idx + 3인지로 가운데 moo인지 구별할 수 있고,
// 그렇지 않다면 오른쪽 moo에 위치하므로 다시 재귀를 사용하여 N - idx - 3을
// 넘겨 구할 수 있다.

// 자세한 설명은 주석으로 남긴다.

int N;
vector<int> board = { 0, 3, };

// N번째 글자를 찾아내는 재귀함수.
char FindIdx(int num)
{
    int idx;
    for (int i = 0; i < board.size(); ++i)
    {
        if (board[i] >= num)
        {
            idx = i - 1;
            break;
        }
    }

    num -= board[idx];
    if (num == 1)
        return 'm';
    else if (num <= idx + 3)
        return 'o';
    else
        return FindIdx(num - idx - 3);
}

int main()
{
    cin >> N;
    long long cur = 4, prevnum = 3;
    while (prevnum <= 1000000000)
    {
        prevnum *= 2;
        prevnum += cur;
        ++cur;
        board.push_back(prevnum);
    }

    cout << FindIdx(N) << '\n';
    return 0;
}