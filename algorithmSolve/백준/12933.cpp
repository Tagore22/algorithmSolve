#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 풀이.
// 꽤나 난이도가 있는 문제였다. 맨 처음부터 순서대로 quack를 찾을 수 있는 만큼
// 삭제해나가는 문제인데 여러가지 주의할 점이 있다.

// 1. q u a c k 순서대로만 지울 수 있으며 5개의 문자가 온전히 존재할 때만 삭제 가능
// 2. 녹음 순서가 올바르지 않을 경우 -1을 출력해야 한다.

// 1번은 순서대로 q u a c k를 찾되, 찾은 개수가 5보다 작을 경우에는 무시하고
// 5보다 클 때에도 온전히 5개씩만 삭제가 가능하므로 5로 나누어 다시 5를 곱한 개수만큼만
// 삭제를 하였다. 
// 2번은 1번에서 지우고 남은 문자열이 최종적으로 텅 빈 상태가 아닐 경우를 의미한다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    char board[5] = { 'q', 'u', 'a', 'c', 'k' };
    vector<int> idxs; // 순서대로 찾은 문자들의 인덱스값
    int answer = 0;
    while (true)
    {
        idxs.clear(); // 매번 벡터를 초기화시켜야한다.
        int idx = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            // 찾은 문자들을 벡터에 집어넣는다.
            if (str[i] == board[idx])
            {
                idxs.push_back(i);
                idx = (idx + 1) % 5;
            }
        }

        // 더이상 5개 이상 찾지 못했다면 온전한 quack가 아니므로 무시한다.
        if (idxs.size() < 5)
            break;
        ++answer;
        // 온전하게 5개씩만 삭제해야하므로 5로 나누어 다시 5를 곱해준다.
        int limit = idxs.size() / 5 * 5;
        // 이 부분에서 약간 헤맸는데 for문이 반복될 때마다 str의 크기값이 작아지므로
        // 매번 i값을 뺀 위치에서 삭제해야 한다.
        for (int i = 0; i < limit; ++i)
            str.erase(idxs[i] - i, 1);
    }
    // 마지막에 문자열이 텅 빈 상태가 아니라면 잘못 녹음된 경우이므로 -1을 출력한다.
    answer = str != "" ? -1 : answer;
    cout << answer << '\n';
    return 0;
}