#include "TrieClass.h"


int main()
{
	struct TrieNode* root = getNewNode();

	vector<string> words = 
	{	"sky", "skill", "skillfactory", 
		"hell", "hello", "help", "helping", 
		"box", "boy", "boyfriend", 
		"mom", "mommy", "mother" };

	for (auto &w : words)
		insert(root, w);

	bool exit = false;
	char operation;
	int res;
	string prefix;
	string addToDictionary;

    cout << "Welcome!" << endl;

	while (!exit)
	{
		bool isValid = true;
		cout << "\nSelect an operation:\n" <<
			"1 - Enter the beginning of the word for autocomplete\n" <<
			"2 - Add a word to the dictionary\n" <<
			"3 - Exit" << std::endl;
		cin >> operation;
		switch (operation)
		{
		case '1':
			cout << "\nEnter prefix (lowercase characters a-z): " << endl;
			cin >> prefix;
			for (int i = 0; i < prefix.size(); i++)
			{
				if (prefix[i] < 'a' || prefix[i] > 'z')
				{
					cout << "Incorrect prefix. You must enter the lowercase characters (a-z)\n";
					isValid = false;
					break;
				}
			}
			if (isValid)
			{
				cout << "\nAutocomplete words: " << endl;
				res = printAutoComplete(root, prefix);

				if (res == 0)
					cout << "No other words found with this prefix\n";
				else if (res == -1)
					cout << "No words found with this prefix\n";
			}
			break;
		case '2':
			cout << "\nAdd word: " << endl;
			cin >> addToDictionary;
			for (int i = 0; i < addToDictionary.size(); i++)
			{
				if (addToDictionary[i] < 'a' || addToDictionary[i] > 'z')
				{
					cout << "Incorrect word. You must enter the lowercase characters (a-z)\n";
					isValid = false;
					break;
				}
			}
			if (isValid)
			{
				insert(root, addToDictionary);
			}
			break;
		case '3':
			exit = true;
			break;
		default:
			cout << "\nIncorrect operation code! Try again." << endl;
			break;
		}
	}
    getchar();
	return 0;
}