#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <functional>
#include <map>

using namespace std;

// Ǯ��.
// �� ������ ���̵��� ���� �ǹ� 3�ΰ� �ǽ��� ����.

int N, M;
string board[20000];
vector<char> columnLetters[26];
int num[26] = { 0 };  // �� ���ĺ��� ��� ���� �־�� �ϴ��� ��� (1-based)

void Input() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
        cin >> board[i];
}

void Solve() {
    // �� ���ĺ��� � ������ �ִ��� Ȯ��
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int idx = board[i][j] - 'A';
            if (num[idx] == 0)
                num[idx] = j + 1;
            else if (num[idx] != j + 1) {
                cout << "NO\n";
                return;
            }
        }
    }

    // �� ���� � ���ĺ��� �ִ��� ����
    for (int i = 0; i < 26; ++i) {
        if (num[i] == 0) continue;
        columnLetters[num[i] - 1].push_back('A' + i);
    }

    // �Է� ���ڿ� ����
    multiset<string> inputSet;
    for (int i = 0; i < M; ++i)
        inputSet.insert(board[i]);

    // ������ ��� ���� �����ؼ� ����
    multiset<string> generatedSet;
    string temp = "";
    function<void(int)> dfs = [&](int depth) {
        if (depth == N) {
            generatedSet.insert(temp);
            return;
        }
        for (char c : columnLetters[depth]) {
            temp.push_back(c);
            dfs(depth + 1);
            temp.pop_back();
        }
    };
    dfs(0);

    // ��
    if (inputSet != generatedSet) {
        cout << "NO\n";
        return;
    }

    // ���
    cout << "YES\n";
    for (int i = 0; i < N; ++i) {
        sort(columnLetters[i].begin(), columnLetters[i].end());
        for (char c : columnLetters[i])
            cout << c;
        cout << '\n';
    }
}

int main() {
    Input();
    Solve();
    return 0;
}