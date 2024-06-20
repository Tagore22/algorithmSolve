#include <iostream>

using namespace std;

// 풀이.
// 조금 아쉬웠던 문제다. idx를 비교해서 idx + 1번째 스위치를 건드리는건 대충 알았으나 0번 스위치에 따라
// 달라지기에 둘을 나누어서 푸는건 몰랐다. 정답율이 37퍼에 해당하는 꽤나 어려웠던 문제라서 그랬던가.
// 역시 쉽지 않은것 같다. 그래도 주저앉지 말고 조금씩이나마 나아가자.

// 자세한 설명은 주석으로 남긴다.

int N, answer = 987654321;
string from, to, temp;

// idx번째 스위치를 누르는 함수.
void PushSwit(int idx)
{
    // idx번째 문자가 뒤집힌다.
    temp[idx] = temp[idx] == '0' ? '1' : '0';
    // 0보다 크다면 바로 앞 문자도 뒤집힌다.
    if (idx > 0)
        temp[idx - 1] = temp[idx - 1] == '0' ? '1' : '0';
    // N - 1보다 작다면 바로 뒤 문자도 뒤집힌다.
    if (idx < N - 1)
        temp[idx + 1] = temp[idx + 1] == '0' ? '1' : '0';
}

// 모든 문자열들을 순회하여 최소값을 구하는 함수. 다만 맨 앞 스위치를 누르느냐 안누르느냐에
// 따라 갈린다.
void CalMin(bool IsFirst)
{
    temp = from;
    int ans = 0;
    // 맨 앞 스위치를 눌렀다고 가정한다. 따라서 앞에서 2개의 문자가 뒤집히고 스위치를 누른 수가 1 증가한다.
    if (IsFirst)
    {
        ++ans;
        temp[0] = temp[0] == '0' ? '1' : '0';
        temp[1] = temp[1] == '0' ? '1' : '0';
    }

    // 그 뒤로 문자열을 순회하여 현재 문자가 다르다면 그 다음 스위치를 눌러간다.
    for (int i = 1; i < N; ++i)
    {
        if (temp[i - 1] != to[i - 1])
        {
            PushSwit(i);
            ++ans;
        }
    }
    // 문자열이 동일하다면 현재 스위치를 누른값을 최종값과 비교해본다.
    if (temp == to)
        answer = min(answer, ans);
}

void MakeAnswer()
{
    CalMin(false);
    CalMin(true);
    answer = answer == 987654321 ? -1 : answer;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> from >> to;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}