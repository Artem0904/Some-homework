
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

	list<string> li{ "red", "orange", "yellow", "pink", "black", "blue", "grey", "white" };
	printCont(li, "Colors : ");

	cout << "Enter search len  : ";
	int searchLen;
	cin >> searchLen;
	cout << "Count of words (len > " << searchLen << ") : " << count_if(begin(li), end(li), [searchLen](string word) {return word.size() > searchLen; });


	char letter;
	cout << "\nEnter letter to find word by first:" << endl;
	cin >> letter;
	auto it = find_if(begin(li), end(li), [&letter](string el) {return el[0] == letter; });
	cout << "Letter: " << letter << " -> " << *it << endl;
}
