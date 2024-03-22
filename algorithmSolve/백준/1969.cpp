#include <iostream>

using namespace std;

// 풀이.
// 처음에는 주어진 문자열들중 HD가 가장 작은 문자열을 구하는것으로 착각했었다.
// 실제로는 모든 경우의 수에서 HD가 가장 작은 문자열을 찾는 것이었다. 사전순으로 가장 앞선 문자열을
// 찾아야 하기 때문에 4개의 알파벳을 사전순으로 대입해가면서 풀어야한다. 원래는 아주 간단한데,
// 모든 문자열들의 각 문자들중 가장 많이 등장한 문자이며 사전순으로 가장 앞서는 문자를 하나씩 뽑아가고,
// 그 문자와 같지 않은 문자의 수를 더해가면 된다. 원래는 map으로 풀면 더 짧게 풀수 있을 것 같으나
// map이 워낙 느려서 쓰기 싫어 고집을 부려봤다.

// 자세한 설명은 주석으로 남긴다.

string board[1000];
char alpha[4] = { 'A', 'C', 'G', 'T' };
int HD[4];
int N, M;

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

void MakeAnswer()
{
    pair<string, int> answer = make_pair("", 0);
    // 문자열의 길이만큼 반복하며 하나씩 문자를 찾는다.
    for (int i = 0; i < M; ++i)
    {
        // 각 문자들이 등장한 수를 기록하는 배열의 초기화.
        for (int j = 0; j < 4; ++j)
            HD[j] = 0;
        // 각 문자열의 i번째 문자들을 모두 확인해보며
        // 등장한 횟수들을 저장한다. 상술한 것처럼 map을 사용해도 된다.
        for (int j = 0; j < N; ++j)
        {
            if (board[j][i] == 'A')
                ++HD[0];
            else if (board[j][i] == 'C')
                ++HD[1];
            else if (board[j][i] == 'G')
                ++HD[2];
            else
                ++HD[3];
        }

        pair<int, int> maxHD = make_pair(0, HD[0]);
        // 각 문자들을 순회하며 등장횟수가 가장 많고, 사전순으로 앞선 문자를 찾는다.
        for (int j = 1; j < 4; ++j)
            if (HD[j] > maxHD.second)
                maxHD = make_pair(j, HD[j]);

        // 그 문자를 최종값 answer의 문자열에 추가한다.
        answer.first += alpha[maxHD.first];

        // 모든 문자열의 i번째 문자들을 다시 순회하며 이전에 찾는 문자와 다른 문자들의 수를
        // 모두 구하여 더한다.
        for (int j = 0; j < N; ++j)
            if (board[j][i] != alpha[maxHD.first])
                ++answer.second;
    }
    cout << answer.first << '\n';
    cout << answer.second << '\n';
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}