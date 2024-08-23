#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 풀이.
// 언제까지고 쉬면서 -브- 문제만 풀수는 없었기 때문에 쉬더라도 골2문제 하나만큼은 풀어보자 결심했고
// 성공했다. 2시간 가까이나 걸렸으나 복귀문제로는 그래도 나쁘지 않았다. 위상정렬을 생각해야하는 문제였다.
// 위상문제는 푼지 굉장히 오래되서 제대로 기억은 안났으나 어찌저찌 틀은 잡은것 같다.
// 후손들의 값을 증가시키면서 현재 시조가 되는 위치에서 직계 후손들을 찾아야했다. 주어지는 후손과 조상의 관계가
// 바로 이어지는 부모자식 관계가 아닌 후손과 조상 관계였기 때문이다. 복잡한 문제에다가 아직 정신이 멀쩡하지 않아
// 밑에 주석으로 설명해야겠다.

// 자세한 설명은 주석으로 남긴다.

map<string, int> con; // string >> int로의 변환.
map<int, string> recon; // int >> string으로의 변환.
vector<int> board[1000]; // 후손들을 저장하는 vector배열.
int num[1000]; // 현재 몇번째로 엮여 있는지를 저장. 위상 정렬의 변수.
int N, M;

// 1. 조상에서 후손을 포함시킨다. 이때 후손의 값들을 1씩 증가시킨다.
// 2. 시조부터 시작한다. 시조의 후손들의 값을 모두 -1 시키고 이때 0이 된 후손들이 직계 후손이 된다.
// 이 수와 각 후손들을 따로 최종값에 포함시킨다.

void MakeAnswer()
{
    // 아직 위상 정렬이 엮여있기 전이기 때문에 모두 0으로 초기화 된다. 조상이 2명 있을 경우 이 값이 2이 되어
    // 조상 2명이 모두 후손을 구하기 전까지 움직일수 없다.
    for (int i = 0; i < N; ++i)
        num[i] = 0;
    string first, second;
    // 모든 정보를 입력받아 조상에서 후손을 저장하고
    // 후손은 몇번 엮여있는지 저장한다.
    for (int i = 0; i < M; ++i)
    {
        cin >> first >> second;
        int f_num = con[first];
        int s_num = con[second];
        ++num[f_num];
        board[s_num].push_back(f_num);
    }
    // 후에 모든 후손들을 사전순으로 정렬해서 출력해야 한다. 이때 정렬해 놓으면
    // 나중에 que를 순회할때도 사전순으로 순회하기 때문에 편한다.
    for (int i = 0; i < N; ++i)
        sort(board[i].begin(), board[i].end());

    queue<int> que;
    vector<int> thefirst;
    // 시조를 구하는 부분. 애시당초 엮여있지 않는 이들이 시조이기 때문이다.
    for (int i = 0; i < N; ++i)
        if (num[i] == 0)
        {
            que.push(i);
            thefirst.push_back(i);
        }

    // 시조들의 수와 그 이름을 출력한다.
    cout << thefirst.size() << '\n';
    for (auto& a : thefirst)
        cout << recon[a] << ' ';
    cout << '\n';

    vector<int> answer[1000];
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        // 현재 시조의 후손들을 순회하며 각 엮여있는 값을 1씩 빼준다. 이때 더이상 엮여 있지 않다면
        // 다음 시조가 될수 있으며 현 시조의 직계 후손이 된다. 따라서 que에 포함시켜주고 현 시조의
        // vector 배열에 저장한다.
        for (auto& a : board[cur])
        {
            --num[a];
            if (num[a] == 0)
            {
                answer[cur].push_back(a);
                que.push(a);
            }
        }
    }

    // 인덱스순으로 각 후손들의 수와 이름을 출력한다.
    for (int i = 0; i < N; ++i)
    {
        cout << recon[i] << ' ' << answer[i].size() << ' ';
        for (auto& a : answer[i])
            cout << recon[a] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<string> name;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        name.push_back(str);
    }
    sort(name.begin(), name.end());
    for (int i = 0; i < N; ++i)
    {
        con[name[i]] = i;
        recon[i] = name[i];
    }
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}