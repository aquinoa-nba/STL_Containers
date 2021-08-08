#if	0						/*	std::map	*/
	#include <iostream>
	#include <map>
	namespace ft = std;
#else						/*	ft::map	*/
	#include "Map.hpp"
#endif

int	main()
{
	// srand(time(0));
	std::cout <<"\n##############################################################" << std::endl;
    std::cout << "###                     ";
    std::cout  << "MAP                                ###" << std::endl;
    std::cout << "##############################################################\n" << std::endl;
						std::cout << "\t\tDefault constructor\n" << std::endl;

	ft::map<int, std::string> map1;
	std::cout << "map1.size(): " << map1.size() << std::endl;
	std::cout << "map1.empty(): " << (map1.empty() ? "true" : "false") << std::endl;

	std::cout << "\n<+==========================================================+>\n" << std::endl;
						std::cout << "\t\t.insert( value_type )\n" << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		int	k = rand() % 21 + 21;
		int	v = rand() % 21 + 21;
		ft::pair<ft::map<int, std::string>::iterator, bool>	res;
		res = map1.insert(ft::make_pair(k, "Str-" + std::to_string(v)));
		std::cout << "map1.insert( " + std::to_string(k) + ", \"Str-" + std::to_string(v) + "\" ) "
		<< (res.second ? "true" : "false") << std::endl;
	}
	std::cout << std::endl;
	std::cout << "map1 key = value:\n";
	for (ft::map<int, std::string>::iterator it = map1.begin(), ite = map1.end(); it != ite; ++it)
		std::cout << it->first << "\t=\t" << it->second << std::endl;
	std::cout << "map1.size(): " << map1.size() << std::endl;
	std::cout << "map1.empty(): " << (map1.empty() ? "true" : "false") << std::endl;

	std::cout << "\n<+==========================================================+>\n" << std::endl;
						std::cout << "\t\tRange constructor\n" << std::endl;

	ft::map<int, std::string> map2(map1.begin(), map1.end());
	std::cout << "\tmap2( map1.begin(), map1.end() )\n" << std::endl;
	std::cout << "map2 key = value:" << std::endl;
	for (ft::map<int, std::string>::iterator it = map2.begin(), ite = map2.end(); it != ite; ++it)
		std::cout << it->first << "\t=\t" << it->second << std::endl;
	std::cout << "map2.size(): " << map2.size() << std::endl;

	std::cout << "\n<+==========================================================+>\n" << std::endl;
						std::cout << "\t\t.max_size()\n" << std::endl;

	std::cout << "map1.max_size(): " << map1.max_size() << std::endl;

	std::cout << "\n<+==========================================================+>\n" << std::endl;
						std::cout << "\t\t.erase( iterator )\n" << std::endl;

	std::cout << "map1 keys: ";
	for (ft::map<int, std::string>::iterator it = map1.begin(), ite = map1.end(); it != ite; ++it)
		std::cout << it->first << " ";
	std::cout << std::endl;
	std::cout << "map1.erase( ++map1.begin() )\n";
	map1.erase(++(map1.begin()));
	std::cout << "map1 key: ";
	for (ft::map<int, std::string>::iterator it = map1.begin(), ite = map1.end(); it != ite; ++it)
		std::cout << it->first << " ";
	std::cout << std::endl;
	std::cout << "map1.size(): " << map1.size() << std::endl;
	std::cout << "\n\t\t.erase( key_type )\n" << std::endl;
	std::cout << "map1.erase(1) return: " << map1.erase(1) << std::endl;
	std::cout << "map1.erase(" + std::to_string((++map1.rbegin())->first) + ") return: " << map1.erase((++map1.rbegin())->first) << std::endl;
	std::cout << "map1 keys: ";
	for (ft::map<int, std::string>::iterator it = map1.begin(), ite = map1.end(); it != ite; ++it)
		std::cout << it->first << " ";
	std::cout << std::endl;
	std::cout << "map1.size(): " << map1.size() << std::endl;

	std::cout << "\n<+==========================================================+>\n" << std::endl;
						std::cout << "\t\toperator[ key_type ]\n" << std::endl;

	map1[42] = "forty two";
	std::cout << "map1[42] = \"forty two\"\n";
	std::cout << "map1 key = value:" << std::endl;
	for (ft::map<int, std::string>::iterator it = map1.begin(), ite = map1.end(); it != ite; ++it)
		std::cout << it->first << "\t=\t" << it->second << std::endl;
	std::cout << "map1.size(): " << map1.size() << std::endl;

	std::cout << "\n<+==========================================================+>\n" << std::endl;
						std::cout << "\t\t.clear()\n" << std::endl;

	std::cout << "map1.size(): " << map1.size() << std::endl;
	map1.clear();
	std::cout << "map1.size(): " << map1.size() << std::endl;

	std::cout << "\n<+==========================================================+>\n" << std::endl;
						std::cout << "\t\t.swap( map )\n" << std::endl;

	for (int i = 0; i < 10; i++)
		map1.insert(ft::make_pair(i * 2, "Str-" + std::to_string(i * 2)));
	std::cout << "map1 key(value:)" << std::endl;
	for (ft::map<int, std::string>::iterator it = map1.begin(), ite = map1.end(); it != ite; ++it)
		std::cout << it->first << "(" << it->second << ") ";
	std::cout << std::endl;
	std::cout << "map1.size(): " << map1.size() << std::endl;
	std::cout << "map2 key(value:)" << std::endl;
	for (ft::map<int, std::string>::iterator it = map2.begin(), ite = map2.end(); it != ite; ++it)
		std::cout << it->first << "(" << it->second << ") ";
	std::cout << std::endl;
	std::cout << "map2.size(): " << map2.size() << std::endl;
	std::cout << "\n\t\tmap1.swap(map2)\n" << std::endl;
	map1.swap(map2);
	std::cout << "map1 key(value:)" << std::endl;
	for (ft::map<int, std::string>::iterator it = map1.begin(), ite = map1.end(); it != ite; ++it)
		std::cout << it->first << "(" << it->second << ") ";
	std::cout << std::endl;
	std::cout << "map1.size(): " << map1.size() << std::endl;
	std::cout << "map2 key(value:)" << std::endl;
	for (ft::map<int, std::string>::iterator it = map2.begin(), ite = map2.end(); it != ite; ++it)
		std::cout << it->first << "(" << it->second << ") ";
	std::cout << std::endl;
	std::cout << "map2.size(): " << map2.size() << std::endl;

	std::cout << "\n<+==========================================================+>\n" << std::endl;
						std::cout <<"\t\t.lower_bound( key_type )\n" << std::endl;

	std::cout << "map2.lower_bound(5)->first: " << map2.lower_bound(5)->first << std::endl;
	std::cout << "map2.lower_bound(5)->second: " << map2.lower_bound(5)->second << std::endl;

	std::cout << "\n<+==========================================================+>\n" << std::endl;
						std::cout <<"\t\t.upper_bound( key_type )\n" << std::endl;

	std::cout << "map2.upper_bound(5)->first: " <<  map2.upper_bound(5)->first << std::endl;
	std::cout << "map2.upper_bound(5)->second: " <<  map2.upper_bound(5)->second << std::endl;

	std::cout << "\n<+==========================================================+>\n" << std::endl;
						std::cout << "\t\t.equal_range( key_type )\n" << std::endl;

	ft::pair <ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> mtst = map2.equal_range(6);
	std::cout << "map2.equal_range(6): ";
		std::cout << mtst.first->first << " - " << mtst.second->first;
	std::cout << std::endl;

	std::cout << "\n<+==========================================================+>\n" << std::endl;
						std::cout << "\t\t.find( key_type )\n" << std::endl;

	std::cout << "map2.find(6)->first: " << map2.find(6)->first << std::endl;
	std::cout << "map2.find(6)->second: " << map2.find(6)->second << std::endl;
}
