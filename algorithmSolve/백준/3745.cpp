#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 사실상 LIS 문제였다. 문제가 조잡했다. '주가는 한 개 이상의 공백으로 구분되어 있으며, 그 외의 위치에서도 자유롭게 나올 수 있다.'
// 에 뭔가 함정이 있는것 같았는데 어차피 그냥 입력받아도 모든 공백은 무시하므로 별 상관이 없는 문장이었다.
// 그것보다도 오름세가 굳이 연속되지 않아도 적용되는 LIS 문제였는데 연속되는 오름세들만 찾는 문제로 착각을 한게 더 컸다.
// LIS를 복습한 부분은 좋았던 것 같다. LIS의 점화식은 다음과 같다.

// 1. 맨 첫번째 원소를 벡터에 넣는다.
// 2. 두번째 원소부터 마지막까지 순회를 하되, 현재 원소를 벡터의 맨 마지막 원소(가장 큰 원소)와 비교한다.
// 3. 현재 원소가 더 크다면 그대로 벡터에 넣는다.
// 4. 현재 원소가 더 작다면 lower_bound(이분 탐색)을 이용하여 현재 원소의 자리를 찾아 그곳에 대체한다.
// 5. 순회 종료 이후 벡터의 크기가 곧 LIS가 된다.

// 다만 여기서 한걸음 더 나아가 LIS의 배열까지 알아야한다면 매번 순회시 현재 원소와 현재 원소가 벡터에 들어가는 인덱스 번호를
// 또다른 벡터에 넣는다. 이후 순회가 끝나면 LIS - 1(윗 벡터의 맨 마지막 인덱스번호)부터 0까지 또다른 벡터의 맨 뒤부터 해당 번호에
// 맞는 원소를 대입하여 넣어가면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[100000];
vector<int> lis;
int N;

void MakeAnswer()
{
    while (cin >> N)
    {
        for (int i = 0; i < N; ++i)
            cin >> board[i];
        lis.clear();
        // 1번. 첫번째 원소를 벡터에 넣는다.
        lis.push_back(board[0]);
        // 2번. 모든 원소들의 순회중 현재 원소를 벡터의 맨 마지막 원소와 비교.
        for (int i = 1; i < N; ++i)
        {
            // 3번.
            if (lis.back() < board[i])
            {
                lis.push_back(board[i]);
            }
            // 4번.
            else
            {
                int idx = lower_bound(lis.begin(), lis.end(), board[i]) - lis.begin();
                lis[idx] = board[i];
            }
        }
        // 5번.
        cout << lis.size() << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}