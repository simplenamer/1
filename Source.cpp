#include <map>
#include <iostream>
#include <fstream>

int main() {
	std::multimap<std::string, int> mp;
	setlocale(LC_ALL, "RUS");

	std::ifstream stream("text.txt");
	std::string str;
	int i;
	while (!stream.eof())
	{
		stream >> str;

		i = str.find(',');
		if (i != -1) {
			str.erase(i, 1);
		}
		i = str.find('.');
		if (i != -1) {
			str.erase(i, 1);
		}
		i = str.find(')');
		if (i != -1) {
			str.erase(i, 1);
		}
		i = str.find('(');
		if (i != -1) {
			str.erase(i, 1);
		}
		i = str.find('-');
		if (i != -1) {
			str.erase(i, 1);
		}
		i = str.find('!');
		if (i != -1) {
			str.erase(i, 1);
		}
		i = str.find('?');
		if (i != -1) {
			str.erase(i, 1);
		}
		mp.insert(std::make_pair(str, 1));
	}

	std::multimap<std::string, int>::iterator it = mp.begin();
	std::map<std::string, int> mp1;


	for (size_t i = 0; i < mp.size(); i++)
	{
		mp1.insert(std::make_pair((it->first), mp.count(it->first)));
		it++;
	}

	std::map<std::string, int>::iterator it1 = mp1.begin();

	std::multimap<int, std::string> mp2;
	for (size_t i = 0; i < mp1.size(); i++)
	{
		mp2.insert(std::make_pair(it1->second, it1->first));
		it1++;
	}

	//for (auto i : mp2) {
	//	std::cout << i.first << " " << i.second <<  std::endl;
	//}

	std::multimap<int, std::string>::iterator it2 = --mp2.end();

	for (size_t i = 0; i < mp2.size(); i++)
	{
		//std::cout << it2->first << "  " << it2->second << std::endl;
		it2--;
	}
	it2 = --mp2.end();

	std::map<int, std::string> mp3;

	//std::map<int, std::string>::iterator it1 = mp3.begin();
	for (size_t i = 0; i < mp2.size(); i++)
	{
		mp3.insert(std::make_pair((it2->first), it2->second));
		it2--;
	}

	for (auto i : mp3) {
		std::cout << i.first << " " << i.second << std::endl;
	}

	system("pause");
}