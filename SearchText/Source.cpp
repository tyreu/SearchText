#include <stack>
#include <string>
#include <iostream>
#include <tuple>
using namespace std;


bool Match(string& text, string& mask)
{
	stack<tuple<int, int>> *tasks = new stack<tuple<int, int>>();
	tasks->push(tuple<int, int>(0, 0));
	while (tasks->size() > 0)
	{
		auto task = tasks->top();
		tasks->pop();
		int it = get<0>(task);
		int im = get<1>(task);
		while (it < text.length() && im < mask.length())
		{
			if (mask[im] == '?')
			{
				it++;
				im++;
			}
			else if (mask[im] == '*')
			{
				tasks->push(tuple<int, int>(it + 1, im));
				im++;
			}
			else if (mask[im] == text[it])
			{
				it++;
				im++;
			}
			else break;
		}
		if (it == text.length())
		{
			if (im == mask.length())
				return true;

			if (im == mask.length() - 1 && mask[im] == '*')
				return true;
		}
	}
	return false;
}

int main()
{
	setlocale(0, "");
	string text;
	string mask; 
	cout << "Enter text: ";
	getline(cin, text);
	cin.clear();
	cout << "Enter mask: ";
	getline(cin, mask);
	cout << boolalpha << Match(text, mask) << endl;
	system("pause");
	return 0;
}