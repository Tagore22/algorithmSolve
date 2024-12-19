#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 누적합과 이분탐색을 사용하는 문제다. A에서 만들수 있는 모든 조합과 B에서 만들수 있는 모든 조합을 만든후에
// A를 순회하며 총 크기 - 현재 A에서 만들수 있는 크기를 B에서 만들수 있는 경우의 수를 모두 더하여 출력하면 된다.
// 이 경우의 수는 upper_bound(), lower_bound()를 이용해서 구할수 있었는데, upper_bound()는 주어지는 값보다 
// 큰 첫번째 원소의 위치를, lower_bound()는 같거나 큰 첫번째 원소의 위치를 반환하기 때문에 두 위치값의 차이가
// 곧 개수와 일치하기 때문이다. 다만, 각 A와 B의 경우의 수를 좀더 간략하게 할수 있을 것 같은데 이 부분이 아쉽다.

// 자세한 설명은 주석으로 남긴다.

vector<int> boardA, boardB, sumA, sumB;

int S, N, M;

void MakeAnswer()
{
    int vsize = boardA.size();
    // A에서 만들수 있는 모든 경우를 구한다.
    for (int idx = 0; idx < vsize; ++idx)
    {
        int next = idx, sum = boardA[idx];
        int prev = idx - 1 < 0 ? vsize - 1 : idx - 1;
        while (next != prev)
        {
            sumA.push_back(sum);
            next = (next + 1) % vsize;
            sum += boardA[next];
        }
    }
    vsize = boardB.size();
    // A에서 만들수 있는 모든 경우를 구한다.
    for (int idx = 0; idx < vsize; ++idx)
    {
        int next = idx, sum = boardB[idx];
        int prev = idx - 1 < 0 ? vsize - 1 : idx - 1;
        while (next != prev)
        {
            sumB.push_back(sum);
            next = (next + 1) % vsize;
            sum += boardB[next];
        }
    }
    // A를 순회하며 B가 맞춰주는 형식이기에 B만 정렬해도 된다.
    sort(sumB.begin(), sumB.end());
    int answer = 0;
    // A를 순회하며 A에서 만들고 남은 피자의 크기를 B에서 만들수 있는지 확인하고
    // 그 경우의 수를 더해준다.
    for (auto& now : sumA)
    {
        int here = S - now;
        if (here < 0)
            continue;
        answer += upper_bound(sumB.begin(), sumB.end(), here) -
            lower_bound(sumB.begin(), sumB.end(), here);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> S >> N >> M;
    int num, sum = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        boardA.push_back(num);
        sum += num;
    }
    sumA.push_back(sum);
    sumA.push_back(0);
    sum = 0;
    for (int i = 0; i < M; ++i)
    {
        cin >> num;
        boardB.push_back(num);
        sum += num;
    }
    sumB.push_back(sum);
    sumB.push_back(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}