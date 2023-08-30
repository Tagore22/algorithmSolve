#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 주어진 문자열들중 반드시 단 하나는 뒤집었을때 같은 문자열이 속해있다.
// 이것의 길이와 가운데 문자를 출력하는 문제다.
// 처음에는 set을 사용해서 발견 즉시 반환하는 형식으로 풀까 생각했었으나
// 그렇게 한다면 입력을 다 받지 못하고 끝나느 경우가 생겨서 불가능했다.
// 결국 100 * 100 = 1만의 경우를 모두 순회하는 아래 풀이로 풀었다.
// 한가지 틀린점이 있었는데 cur을 초기화하는 과정에서 처음에는 참조자로 했었는데
// 그러면 뒤에 reverse()를 하였을때 원본이 바뀌어서 틀린답이 나왔다.

// 자세한 설명은 주석으로 남긴다.

string board[100];
int N;

void MakeAnswer()
{
    // 모든 문자열들을 순회하여 뒤집은후 같은 문자열이 존재하는지 확인한다.
    for (int i = 0; i < N; ++i)
    {
        string cur = board[i];
        reverse(cur.begin(), cur.end());
        for (int j = 0; j < N; ++j)
        {
            // 같다면 문자열의 길이와 가운데 문자를 출력한다.
            if (cur == board[j])
            {
                cout << cur.size() << ' ' << cur[cur.size() / 2] << '\n';
                return;
            }
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}