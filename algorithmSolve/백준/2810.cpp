#include <iostream>

using namespace std;

// 풀이.
// 모든 컵홀더의 수를 계산후 현재 존재하는 사람의 수와 비교하여 더 적은 수를 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int N;

void MakeAnswer()
{
    string str;
    cin >> str;

    int idx = 0;
    int answer = 1;
    // 0 ~ N까지 순회하며 모든 컵홀더의 수를 계산한다.
    while (idx < N)
    {
        // 일반좌석이라면 한칸씩, 커플석이라면 2칸씩 건너 뛴다.
        if (str[idx] == 'S')
            ++idx;
        else
            idx += 2;
        // 컵홀더는 1개씩 증가한다.
        ++answer;
    }
    answer = min(answer, N);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}