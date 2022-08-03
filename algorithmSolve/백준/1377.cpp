#include <iostream>
#include <algorithm>

using namespace std;

const int MAXNUM = 500000;
pair<int, int> board[MAXNUM];
int N;

//처음엔 단순히 바로 앞 숫자가 현 숫자보다 크다면 맨 뒤로 밀려나는 버블정렬의 성질로 인해
//앞 수가 크면 answer + 1 을 하였으나 다시 생각해보면 1,5,6,2 같은 경우는 두번 정렬이 되어야함에도
//바로 앞수가 큰 경우는 6,2,밖에 없어 틀린 알고리즘이 되었다.
//진짜 정답은 버블정렬시 앞수가 크면 뒷수가 앞수와 위치를 옮기는것 즉, 앞으로 한칸 밀리는걸 이용하는건데
//앞으로 밀려나는건 각 정렬시 단한번밖에 성립되지 않기 때문이다.
//이러한 성질을 이용하여 실제 정렬된 배열과 정렬되지 않은 배열의 원소 위치를 비교하여 가장 많이 밀린 수+1이
//정답이 된다.

void MakeAnswer()
{
    sort(board, board + N);
    int answer = 0;
    for (int i = 0; i < N - 1; ++i)
        answer = max(answer, board[i].second - i);
    cout << answer + 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        board[i] = make_pair(a, i);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}