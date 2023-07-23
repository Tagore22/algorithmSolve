#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 정답율을 보면 알겠지만 꽤나 어려운 문제라서 거의 하루종일 풀었다.
// 접근까지는 좋았는데 너무 어렵게 생각했다.
// 너무 어렵게 생각하지 말자.
// 큰틀은 다음과 같다.

// 1. 색깔 i, 크기 j인 공이 있을때 색깔이 다르고 크기가 더 작은 공을 상대로 점수를 획득할수 있다.
// 2. 색깔이 같거나 크기가 같거나 더 큰 공은 점수를 획득할수 없다.

// 따라서 크기를 기준으로 오름차순으로 공들을 정렬한후 현재와 같은 색들의 공들과 크기가 같았던 공들을
// 제외한 나머지 점수를 취하면 된다.
// 처음에는 따로 벡터를 이용해서 누적합을 미리 구하려고 했는데 그건 투머치였다.
// 그냥 최대 20만번의 순회를 돌면서 그때그때 크기와 색깔의 점수들을 누적시키면 된다.
// 다만 주의해야할점은 크기와 색깔이 같은 공일때인데 이때에는 오름차순으로 정렬된 상태이기에 앞에 공과 비교하여
// 크기와 색이 같다면 그 앞의 점수로 치환해주면 된다.

// 자세한 설명은 주석으로 남긴다.

int colors[200001], nums[2001];
vector<pair<pair<int, int>, int>> board; // 크기, 색, 번호;
int N;

void MakeAnswer()
{
    // 상술하였듯 크기를 기준으로 오름차순 정렬한다.
    sort(board.begin(), board.end());

    vector<int> answer(N, 0);
    int sum = 0;
    int cur_num, cur_color, cur_idx;
    for (int i = 0; i < N; ++i)
    {
        // 현재 크기와 색깔 그리고 순서.
        cur_num = board[i].first.first;
        cur_color = board[i].first.second;
        cur_idx = board[i].second;

        // 현재 공이 취할수 없는 점수들을 제외한다.

        // 1. 색깔이 같은 공들.
        // 2. 크기가 같은 공들.(크기가 더 큰 공들은 뒤에 나오기 때문에 무시해도 상관없다.)
        answer[cur_idx] = sum - colors[cur_color] - nums[cur_num];

        // 상술하였듯 크기와 색이 같다면 오름차순 정렬에 의해 붙어있다. 또한 대입해보면 알듯이
        // 두번째 같은 공의 값이 이상하게 된다. 따라서 앞의 값(기존값)으로 치환해준다.
        if (i > 0 && cur_num == board[i - 1].first.first &&
            cur_color == board[i - 1].first.second)
            answer[cur_idx] = answer[board[i - 1].second];

        // 각 크기와 색깔 및 총합에 현재값을 더해준다.
        colors[cur_color] += cur_num;
        nums[cur_num] += cur_num;
        sum += cur_num;
    }

    for (int i : answer)
        cout << i << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int color, num;
    for (int i = 0; i < N; ++i)
    {
        cin >> color >> num;
        board.push_back(make_pair(make_pair(num, color), i));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}