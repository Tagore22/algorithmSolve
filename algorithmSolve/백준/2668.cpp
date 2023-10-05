#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// DFS��������. ��� ��� ���� �Ʒ��� ����ٴ� ����
// i�� ��� board[i]�� ���� ���� ��ȸ�Ͽ����� �ٽ� i�� ���ƿ��� �͵��� ���� �ȴ�.
// �������� �������� �������� ���� ������� ���� ���� ���� ������ ��ȯ�� �����ϴ� �� ����.
// ����, �̹� ��ȯ�� �� �ٸ� ���Ҵ� ���� DFS�� �ݺ��� �ʿ䰡 ����.

// �ڼ��� ������ �ּ����� �����.

int board[101];
// �̹� ��ȯ�� ���� ���Ҹ� �����ϴ� bool ���Ϳ� �� DFS ��ȯ�� �湮���θ� üũ�ϴ� bool ����. 
vector<bool> isAnswer, visit;
// �� DFS ��ȯ�� �� ���ҵ�� �Ʒ� ���ҵ��� �����ϴ� ���͵�.
vector<int> first_vec, second_vec;
int N, answer = 0;

// �̹� �湮�� ���ҿ� �Ǵٽ� �����Ͽ����� ��ȯ���� Ȯ���ϴ� �Լ�.
void CheckVec()
{
    // �� ���Ͱ� �������� Ȯ���ϱ� ���� �����Ѵ�.
    sort(first_vec.begin(), first_vec.end());
    sort(second_vec.begin(), second_vec.end());

    // �� ���Ͱ� �����ϴٸ� ��ȯ�̱⿡ ���;ȿ� �ִ� ���ҵ��� ������ üũ�Ѵ�.
    if (first_vec == second_vec)
    {
        for (int i = 0; i < first_vec.size(); ++i)
        {
            isAnswer[first_vec[i]] = true;
            // �������� �̸� �˾ƾ� ���߿� ����� �ι� ��ȸ���� ������ �ִ�.
            ++answer;
        }
    }
    // ��ȸ�� �����⿡ ��ȸ���� ������ �ʿ��� �Ʒ� 2���� �ʱ�ȭ���ش�.
    first_vec.clear();
    second_vec.clear();
}

// DFS �Լ�. �� ������ ��ȣ�� �޾Ƽ� �Ʒ� ���ͷ� �̵��Ѵ�.
void DFS(int cur)
{
    // �ϴ� �� ���Ϳ� �Ʒ� ���Ϳ� ���� ������ �Է����ְ�
    // �湮 ���θ� �����Ѵ�.
    first_vec.push_back(cur);
    second_vec.push_back(board[cur]);
    visit[cur] = true;

    if (visit[board[cur]])
    {
        // �̹� �湮�� ���� �Ǵٽ� �湮�Ѵٸ� ���̻� ��ȸ�� �Ұ����ϹǷ� Ȯ���غ���.
        CheckVec();
        return;
    }

    DFS(board[cur]);
}

void MakeAnswer()
{
    // ��� ���ҿ��� �����غ���.
    for (int i = 1; i <= N; ++i)
    {
        // �ٸ� �̹� ���� ������ ���Ҷ�� �Ȱ��� ��ȯ�� �ݺ��һ��̹Ƿ� �����Ѵ�.
        if (!isAnswer[i])
        {
            // �湮 ���θ� �������ش�.
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