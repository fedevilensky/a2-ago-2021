#include <string>
#include <stack>
#include <iostream>
using namespace std;

char opposite(char c)
{
  switch (c)
  {
  case '(':
    return ')';
  case '[':
    return ']';
  case '{':
    return '}';
  }
}

// funciona con ([{}])
bool isBalanced(string brackets)
{
  stack<char> stk;

  char x;
  for (int i = 0; i < brackets.length(); i++)
  {
    x = brackets[i];
    if (x == '(' || x == '[' || x == '{')
      stk.push(opposite(brackets[i]));
    else
    {
      if (stk.empty())
        return false;

      if (stk.top() == x)
        stk.pop();
      else
        return false;
    }
  }

  return stk.empty();
}

// solo funciona con ()
bool isBalanced2(string brackets)
{
  int count = 0;
  for (int i = 0; i < brackets.length(); i++)
  {
    if (brackets[i] == '(')
      count++;
    else
    {
      count--;
      if (count < 0)
        return false;
    }
  }
  return count == 0;
}

int main()
{
  const string brackets = "(())";

  if (isBalanced(brackets))
    cout << "Balanced" << endl;
  else
    cout << "Not Balanced" << endl;
}