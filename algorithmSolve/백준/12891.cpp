#include <iostream>

using namespace std;

// 풀이.
// 길이가 S인 문자열이 있을때 길이가 P인 부분문자열들중 A, C, G, T의 등장횟수를 충족하는 부분문자열의 개수를 출력하는 문제다.
// 처음에는 길이가 P인 모든 부분문자열을 순회하되, 가지치기로 연산량을 줄이려고 했으나 그래도 시간초과가 떴다.
// 진짜 풀이는 0번째부터 P - 1개의 문자까지 확인후 앞에서 한개를 빼고 뒤에서 한개를 넣는 방식이었다.
// 그렇게 하면 100만개의 연산량안에 끝나는 것이 확정된다. 다만 이 이후에 다풀어놓고 한가지 실수를 했는데
// 이는 따로 후술한다.

// 자세한 설명은 주석으로 남긴다.

int S, P, A, C, G, T;
string str;

void MakeAnswer()
{
    // 최종답 answer와 각 A, C, G, T의 개수는 0으로 초기화한다.
    int answer = 0, a_num = 0, c_num = 0, g_num = 0, t_num = 0;
    // 최초 0 ~ P - 1번째 문자를 확인한다.
    for (int i = 0; i < P; ++i)
    {
        if (str[i] == 'A')
            ++a_num;
        else if (str[i] == 'C')
            ++c_num;
        else if (str[i] == 'G')
            ++g_num;
        else if (str[i] == 'T')
            ++t_num;

        // 원래는 아래 if문이 여기에 있었다. 너무 안일하게 생각했으며
        // 여기에 존재하면 최초 길이 P의 부분문자열을 조사했을때 answer가 1 초과의 수가
        // 나타날수 있다. 예를 들어 입력이 4, 2, AAAA, 1, 0, 0, 0일때
        // 아래 if문이 여기에 있다면 맨 처음 AA까지만 검사했을때 기껏해야 answer는 1이여야 하지만
        // 실제로는 최초 2개의 문자가 모두 1, 0, 0, 0을 충족시켜 answer는 2가 되어 틀리게 된다.
    }

    // 최초 P개의 문자 확인후 answer를 갱신한다.
    if (a_num >= A && c_num >= C && g_num >= G && t_num >= T)
        ++answer;

    // 맨앞 문자를 제거하고 뒤에 하나를 추가해나가며 순회를 한다.
    for (int i = P; i < S; ++i)
    {
        // 맨앞 문자를 지운다.
        if (str[i - P] == 'A')
            --a_num;
        else if (str[i - P] == 'C')
            --c_num;
        else if (str[i - P] == 'G')
            --g_num;
        else if (str[i - P] == 'T')
            --t_num;

        // 맨뒤에 문자를 추가한다.
        if (str[i] == 'A')
            ++a_num;
        else if (str[i] == 'C')
            ++c_num;
        else if (str[i] == 'G')
            ++g_num;
        else if (str[i] == 'T')
            ++t_num;

        // 이번 추가로 답이 존재하는지 확인한다.
        if (a_num >= A && c_num >= C && g_num >= G && t_num >= T)
            ++answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S >> P >> str >> A >> C >> G >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}