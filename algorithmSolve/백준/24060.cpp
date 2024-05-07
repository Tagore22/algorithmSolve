#include <iostream>

using namespace std;

// 풀이.
// 병합 정렬을 설명해주고 그중 정렬되어 K번째로 임시 저장되는 수를 출력하는 문제다.
// 설명에 나온 병합 정렬을 그대로 구현후 K번째로 저장되는 수를 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[500000], temp[500000];
int N, K, answer = 0;

// 정렬된 수들을 병합하는 함수.
void Merge(int from, int mid, int to)
{
    // i와 j는 각각 양분된 배열의 시작위치를 뜻하며, t는 임시 저장된 값들의 시작점이다.
    int i = from, j = mid + 1, t = 0;
    // 첫번째 혹은 두번째 배열의 값들이 모두 저장될때까지 반복한다.
    while (i <= mid && j <= to)
        // 두 배열의 현재값들중 더 작은 값을 임시 저장한다.
        temp[t++] = board[i] <= board[j] ? board[i++] : board[j++];
    // 첫번째 배열값이 남았다면 모두 저장한다.
    while (i <= mid)
        temp[t++] = board[i++];
    // 두번째 배열값이 남았다면 모두 저장한다.
    while (j <= to)
        temp[t++] = board[j++];
    // i는 현재 범위의 시작값이고, t는 저장되어 있는 임시값들의 시작값(0)이다.
    i = from, t = 0;
    // 총 배열에 현재 임시 저장되어 있는 값들을 복사한다.
    while (i <= to)
    {
        board[i++] = temp[t++];
        ++answer;
        // K번째 저장에 도달하였다면 현재 값을 출력하고 프로그램을 종료한다.
        // exit(1)과 exit(0)은 에러로 인한 종료와 정상종료의 차이인데,
        // 0은 정상종료를, 0이 아닌 다른 수는 에러로 인한 종료인데 보통 1을 사용한다.
        if (answer == K)
        {
            // i++연산으로 i가 증가하므로 board[i]가 아닌 board[i - 1]을 출력하여야 한다.
            cout << board[i - 1] << '\n';
            exit(0);
        }
    }
}

// 일정 범위의 배열값들을 병합 정렬하는 함수.
void Merge_Sort(int from, int to)
{
    // 시작값과 끝값이 다르다면 두 부분으로 나누어 병합 정렬한다.
    // 이 if문은 기저사례를 위함인데 양분하여 하나의 배열만이 남았을때는 더이상 나눌수 없기에
    // 무시한다. 즉, 최소 2개 이상 배열값이 존재할때만 병합 정렬이 실행된다.
    if (from < to)
    {
        // 현재 범위를 양분한다.
        int mid = (from + to) / 2;
        // 앞부분 병합 정렬.
        Merge_Sort(from, mid);
        // 뒷부분 병합 정렬.
        Merge_Sort(mid + 1, to);
        // 두 부분을 다시 병합한다.
        Merge(from, mid, to);
    }
}

void MakeAnswer()
{
    // 배열의 모든 범위를 시작으로 병합 정렬을 실행한다.
    Merge_Sort(0, N - 1);
    // 임시 저장된 수가 K보다 적어 이미 병합 정렬이 종료되었다면 -1을 출력한다.
    cout << -1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}