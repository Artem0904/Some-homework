
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

template<typename T>
void printCont(const T& cont, const string& text = "")
{
	cout << text << endl;
	for (auto it = begin(cont); it != end(cont); it++)
	{
		cout << "\t" << *it;
	}
	cout << endl;
}

int main()
{

    list<string> li;
	printCont(li, "Empty list : ");

}
