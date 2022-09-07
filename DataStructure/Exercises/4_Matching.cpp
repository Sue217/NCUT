/**
 *    author: Jingbo Su
 *    created: 29/10/2021
 **/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair<char, int> bracket;

bool isMatch(bracket a, bracket b) {
  if (!(a.first ^ '(') && !(b.first ^ ')')) return true;
  if (!(a.first ^ '{') && !(b.first ^ '}')) return true;
  return false;
}

bool isLeftBracket(char ch) {
  if (!(ch ^ '(') || !(ch ^ '{')) return true;
  return false;
}

bool isRightBracket(char ch) {
  if (!(ch ^ ')') || !(ch ^ '}')) return true;
  return false;
}

class Stack {
 public:
  Stack() = default;

  void Push(bracket bk) { stk.emplace_back(bk); }

  void Pop() {
    if (!static_cast<int>(stk.size())) exit(0);
    stk.pop_back();
  }

  bracket Top() {
    if (!static_cast<int>(stk.size())) exit(0);
    return stk.back();
  }

  bool isEmpty() { return !(static_cast<int>(stk.size())); }

 private:
  vector<bracket> stk;
};

class Solve {
 public:
  Solve() = default;

  explicit Solve(int maxn) {
    args.resize(maxn);
    row = 0;
  }

  void readFile() {
    ifstream ifstr("example.c", ios::in);

    while (getline(ifstr, args[row++]))
      ;

    --row;

    ifstr.close();
  }

  vector<bracket> getBrackets() {
    vector<bracket> ans;
    for (int i = 0; i < row; ++i) {
      int col = static_cast<int>(args[i].size());
      for (int j = 0; j < col; ++j) {
        char ch = args[i][j];
        if (!(ch ^ '/') && j < col - 1) {
          if (!(args[i][j + 1] ^ '/')) break;
          if (!(args[i][j + 1] ^ '*')) {
            for (j += 2; i < row; ++i) {
              for (j = (j < col - 1 ? j : 0),
                  col = static_cast<int>(args[i].size());
                   j < col - 1; ++j)
                if (!(args[i][j] ^ '*') && !(args[i][j + 1] ^ '/')) break;
              if (j < col - 1) break;
            }
            ++j;
            continue;
          }
        }
        if (!(ch ^ '\'')) {
          while (args[i][++j] != '\'')
            ;
          // args[i][j] = '\''
          continue;
        }
        if (!(ch ^ '\"')) {
          while (args[i][++j] != '\"')
            ;
          continue;
        }
        if (isLeftBracket(ch) || isRightBracket(ch)) {
          ans.emplace_back(ch, i + 1);
        }
      }
    }

    return ans;
  }

 private:
  vector<string> args;
  int row;
};

void goMatch(vector<bracket> argc) {
  Stack stack;

  for (auto &i : argc) {
    if (isLeftBracket(i.first)) stack.Push(i);

    // is right bracket
    else {
      if (stack.isEmpty() || !isMatch(stack.Top(), i)) {
        cout << "without matching '" << i.first << "' at line " << i.second
             << endl;
        return;
      } else
        stack.Pop();
    }
  }
  if (stack.isEmpty()) {
    for (auto &i : argc) cout << i.first;
    cout << endl;
  } else {
    cout << "without matching '" << stack.Top().first << "' at line "
         << stack.Top().second << endl;
  }
}

int main() {
  const int maxn = 211;
  Solve solve(maxn);

  solve.readFile();

  vector<bracket> res = solve.getBrackets();

  goMatch(res);

  return 0;
}