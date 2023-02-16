
#include <iostream>
#include <algorithm>
#include <list>
#include <deque>
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
string deleteLastLetter(string& word)
{
	if (word.size() == 0)
	{
		throw underflow_error("One of your words have size = 0");
	}
	word.pop_back();
	return word;
}
int main()
{

	list<string> li{ "", "orange", "yellow", "pink", "black", "blue", "grey", "white" };
	printCont(li, "Colors : ");

	cout << "Enter search len  : ";
	int searchLen;
	cin >> searchLen;
	cout << "Count of words (len > " << searchLen << ") : " << count_if(begin(li), end(li), [searchLen](string word) {return word.size() > searchLen; });

	// deque
	deque<string> deq(li.size());
	copy(begin(li), end(li), begin(deq));
	try
	{
		transform(begin(deq), end(deq), begin(deq), deleteLastLetter);
	}
	catch(const underflow_error& ex)
	{
		cout << "\nError cant remove last letter : " << ex.what() << endl;
	}
	printCont(deq, "Deque : ");


	char letter;
	cout << "\nEnter letter to find word by first:" << endl;
	cin >> letter;
	auto it = find_if(begin(li), end(li), [&letter](string el) {return el[0] == letter; });
	cout << "Letter: " << letter << " -> " << *it << endl;

}
