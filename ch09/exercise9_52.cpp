#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

string calc(string l, string r, string op)
{
	string s;
	if (op == "-")
		s = to_string(stoi(l) - stoi(r));
	return s;
}

int main()
{
	string s("1+2*(7-4)");
	stack<string> stack;
	for (auto iter = s.begin(); iter != s.end();)
	{
		if (*iter == '(')
		{
			stack.push(string(1, *iter)); //顺序容器构造函数C seq(n,t),使seq包含n个初始化为值t的元素
			++iter;
			while (*iter != ')')
			{
				stack.push(string(1, *iter));
				++iter;
			}
		}
		else if (*iter == ')')
		{
			string r = stack.top(); stack.pop();
			string op = stack.top(); stack.pop();
			string l = stack.top(); stack.pop();
			stack.pop(); // '(' 弹出
			stack.push(calc(l, r, op));
			++iter;
		}
		else
		{
			++iter;
		}

	}

	while (!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
	return 0;
}
