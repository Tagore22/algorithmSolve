#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// DFS문제였다. 몇개를 골라서 위와 아래를 맞춘다는 것은
// i를 골라 board[i]로 가는 것을 순회하였을때 다시 i로 돌아오는 것들을 고르면 된다.
// 문제에서 존재하지 않을때를 따로 언급하지 않을 것을 보면 무조건 순환은 존재하는 것 같다.
// 또한, 이미 순환을 얻어낸 다른 원소는 굳이 DFS를 반복할 필요가 없다.

// 자세한 설명은 주석으로 남긴다.

int board[101];
// 이미 순환을 얻은 원소를 갱신하는 bool 벡터와 매 DFS 순환시 방문여부를 체크하는 bool 벡터. 
vector<bool> isAnswer, visit;
// 매 DFS 순환시 윗 원소들과 아랫 원소들을 저장하는 벡터들.
vector<int> first_vec, second_vec;
int N, answer = 0;

// 이미 방문한 원소에 또다시 도달하였을때 순환인지 확인하는 함수.
void CheckVec()
{
    // 두 벡터가 동일한지 확인하기 위해 정렬한다.
    sort(first_vec.begin(), first_vec.end());
    sort(second_vec.begin(), second_vec.end());

    // 두 벡터가 동일하다면 순환이기에 벡터안에 있는 원소들이 답임을 체크한다.
    if (first_vec == second_vec)
    {
        for (int i = 0; i < first_vec.size(); ++i)
        {
            isAnswer[first_vec[i]] = true;
            // 최종답을 미리 알아야 나중에 답들을 두번 순회하지 않을수 있다.
            ++answer;
        }
    }
    // 순회는 끝났기에 순회마다 갱신이 필요한 아래 2개를 초기화해준다.
    first_vec.clear();
    second_vec.clear();
}

// DFS 함수. 윗 벡터의 번호를 받아서 아랫 벡터로 이동한다.
void DFS(int cur)
{
    // 일단 윗 벡터와 아랫 벡터에 현재 값들을 입력해주고
    // 방문 여부를 갱신한다.
    first_vec.push_back(cur);
    second_vec.push_back(board[cur]);
    visit[cur] = true;

    if (visit[board[cur]])
    {
        // 이미 방문한 곳을 또다시 방문한다면 더이상 순회는 불가능하므로 확인해본다.
        CheckVec();
        return;
    }

    DFS(board[cur]);
}

void MakeAnswer()
{
    // 모든 원소에서 시작해본다.
    for (int i = 1; i <= N; ++i)
    {
        // 다만 이미 답이 구해진 원소라면 똑같은 순환을 반복할뿐이므로 무시한다.
        if (!isAnswer[i])
        {
            // 방문 여부를 갱신해준다.
            visit.assign(N + 1, false);
            DFS(i);
        }
    }
    cout << answer << '\n';
    for (int i = 1; i <= N; ++i)
    {
        if (isAnswer[i])
        {
            cout << i << '\n';
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    isAnswer.resize(N + 1, false);
    for (int i = 1; i <= N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}