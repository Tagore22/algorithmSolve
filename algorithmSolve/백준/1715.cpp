#include <iostream>
#include <set>

using namespace std;

//풀이
//모든 수들은 한번씩 무조건 더해져가며 그 수가 줄어들기에 가장 작은 수부터 더해가며 없애야 최종값이 줄어든다.
//결과적으로, multiset에(중복된 값이 있을수 있으므로) 입력값들을 저장하여 정렬한후 앞에서 2개씩을 제거하여
//더하고 그 덧셈값을 다시 저장하는 것을 multiset에 단 하나의 원소만 남을때까지 반복한다.
//그 마지막 원소값이 바로 최종값임으로 출력한다.

multiset<int> board;
int N;

void MakeAnswer()
{
    int answer = 0;
    while (board.size() > 1)
    {
        int first = *board.begin();
        board.erase(board.begin());
        int second = *board.begin();
        board.erase(board.begin());

        board.insert(first + second);
        answer += first + second;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        board.insert(num);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}