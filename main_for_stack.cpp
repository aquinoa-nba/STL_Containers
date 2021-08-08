#include <list>
#include <vector>

#if	0						/*	std::stack	*/
	#include <iostream>
	#include <stack>
	namespace ft = std;
#else						/*	ft::stack	*/
	#include "Stack.hpp"
#endif

int		main()
{
	std::cout <<"\n##############################################################" << std::endl;
    std::cout << "###                     ";
    std::cout  << "STACK                              ###" << std::endl;
    std::cout << "##############################################################\n" << std::endl;
    ft::stack<int> intStack;
    ft::stack<int> intStack2;
    ft::stack<std::string> strStack;
    ft::stack<std::string> strStack2;
    ft::stack<int, std::list<int> > intListStack;
    ft::stack<int, std::list<int> > intListStack2;
    std::cout << "\t\t\t.empty()" << std::endl << std::endl;
    std::cout << "intStack.empty():\t" << (intStack.empty() ? "true" : "false")  << std::endl;
    std::cout << "strStack.empty():\t" << (strStack.empty() ? "true" : "false")  << std::endl;
    std::cout << "intListStack.empty():\t" << (intListStack.empty() ? "true\n" : "false\n")  << std::endl;
    std::cout << "intStack2.empty():\t" << (intStack2.empty() ? "true" : "false")  << std::endl;
    std::cout << "strStack2.empty():\t" << (strStack2.empty() ? "true" : "false")  << std::endl;
    std::cout << "intListStack2.empty():\t" << (intListStack2.empty() ? "true\n" : "false")  << std::endl;
    std::cout << "\n--------------------------------------------------------------\n" << std::endl;
    std::cout << "intStack == intStack2 ?\t\t" << (intStack == intStack2 ? "true" : "false")  << std::endl;
    std::cout << "strStack == strStack2 ?\t\t" << (strStack == strStack2 ? "true" : "false")  << std::endl;
    std::cout << "intListStack == intListStack2 ?\t" << (intListStack == intListStack2 ? "true" : "false")  << std::endl;
    std::cout << "\n--------------------------------------------------------------\n" << std::endl;
    for (int i = 0; i < 10; ++i)
	{
        intStack.push(i);
        intListStack.push(i);
        strStack.push("Str-" + std::to_string(i));
    }
    std::cout << "intStack.empty():\t" << (intStack.empty() ? "true" : "false")  << std::endl;
    std::cout << "strStack.empty():\t" << (strStack.empty() ? "true" : "false")  << std::endl;
    std::cout << "intListStack.empty():\t" << (intListStack.empty() ? "true" : "false")  << std::endl;
    std::cout << "\n<+==========================================================+>\n" << std::endl;
	std::cout << "\tcopy constructor stack( const stack &other )\n" << std::endl;
    ft::stack<int> intStack3(intStack);
    ft::stack<std::string> strStack3(strStack);
    ft::stack<int, std::list<int> > intListStack3(intListStack);
    std::cout << "intStack == intStack3 ?\t\t" << (intStack == intStack3 ? "true" : "false")  << std::endl;
    std::cout << "strStack == strStack3 ?\t\t" << (strStack == strStack3 ? "true" : "false")  << std::endl;
    std::cout << "intListStack == intListStack3 ?\t" << (intListStack == intListStack3 ? "true" : "false")  << std::endl;
    std::cout << "\n<+==========================================================+>\n" << std::endl;
    std::cout << "intStack != intStack2 ?\t\t" << (intStack != intStack2 ? "true" : "false")  << std::endl;
    std::cout << "strStack != strStack2 ?\t\t" << (strStack != strStack2 ? "true" : "false")  << std::endl;
    std::cout << "intListStack != intListStack2 ?\t" << (intListStack != intListStack2 ? "true\n" : "false\n")  << std::endl;
    std::cout << "intStack < intStack2 ?\t\t" << (intStack < intStack2 ? "true" : "false")  << std::endl;
    std::cout << "strStack < strStack2 ?\t\t" << (strStack < strStack2 ? "true" : "false")  << std::endl;
    std::cout << "intListStack < intListStack2 ?\t" << (intListStack < intListStack2 ? "true\n" : "false\n")  << std::endl;
    std::cout << "intStack > intStack2 ?\t\t" << (intStack > intStack2 ? "true" : "false")  << std::endl;
    std::cout << "strStack > strStack2 ?\t\t" << (strStack > strStack2 ? "true" : "false")  << std::endl;
    std::cout << "intListStack > intListStack2 ?\t" << (intListStack > intListStack2 ? "true\n" : "false\n")  << std::endl;
    std::cout << "intStack <= intStack2 ?\t\t" << (intStack <= intStack2 ? "true" : "false")  << std::endl;
    std::cout << "strStack <= strStack2 ?\t\t" << (strStack <= strStack2 ? "true" : "false")  << std::endl;
    std::cout << "intListStack <= intListStack2 ?\t" << (intListStack <= intListStack2 ? "true\n" : "false\n")  << std::endl;
    std::cout << "intStack >= intStack2 ?\t\t" << (intStack >= intStack2 ? "true" : "false")  << std::endl;
    std::cout << "strStack >= strStack2 ?\t\t" << (strStack >= strStack2 ? "true" : "false")  << std::endl;
    std::cout << "intListStack >= intListStack2 ?\t" << (intListStack >= intListStack2 ? "true" : "false")  << std::endl;
    std::cout << "\n<+==========================================================+>\n" << std::endl;
    std::cout << "\t\t\t.size()" << std::endl << std::endl;
    std::cout << "intStack.size():\t" << intStack.size() << std::endl;
    std::cout << "strStack.size():\t" << strStack.size() << std::endl;
    std::cout << "intListStack.size():\t" << intListStack.size() << std::endl;
    std::cout << "\n<+==========================================================+>\n" << std::endl;
    std::cout << "\t\t\t.top()" << std::endl << std::endl;
    std::cout << "intStack.top():\t\t" << intStack.top() << std::endl;
    std::cout << "strStack.top():\t\t" << strStack.top() << std::endl;
    std::cout << "intListStack.top():\t" << intListStack.top() << std::endl;
    std::cout << "\n<+==========================================================+>\n" << std::endl;
    std::cout << "\t\t\t.push(42)" << std::endl << std::endl;
    intStack.push(42);
    intListStack.push(42);
    strStack.push("Str-" + std::to_string(42));
    std::cout << "intStack.top():\t\t" << intStack.top() << std::endl;
    std::cout << "strStack.top():\t\t" << strStack.top() << std::endl;
    std::cout << "intListStack.top():\t" << intListStack.top() << std::endl;
    std::cout << "\n<+==========================================================+>\n" << std::endl;
    std::cout << "\t\t\t.pop()" << std::endl << std::endl;
    intStack.pop();
    strStack.pop();
	intListStack.pop();
    std::cout << "intStack.top():\t\t" << intStack.top() << std::endl;
    std::cout << "strStack.top():\t\t" << strStack.top() << std::endl;
    std::cout << "intListStack.top():\t" << intListStack.top() << std::endl;
    std::cout << "\n<+==========================================================+>\n" << std::endl;
    std::cout << "\t\t\t.swap()" << std::endl << std::endl;
    std::cout << "intStack.size():\t" << intStack.size() << std::endl;
    std::cout << "strStack.size():\t" << strStack.size() << std::endl;
    std::cout << "intListStack.size():\t" << intListStack.size() << std::endl << std::endl;
    std::cout << "intStack2.size():\t" << intStack2.size() << std::endl;
    std::cout << "strStack2.size():\t" << strStack2.size() << std::endl;
    std::cout << "intListStack2.size():\t" << intListStack2.size() << std::endl << std::endl;
    std::cout << "intStack.top():\t\t" << intStack.top() << std::endl;
    std::cout << "strStack.top():\t\t" << strStack.top() << std::endl;
    std::cout << "intListStack.top():\t" << intListStack.top() << std::endl << std::endl;
    std::cout << "\n--------------------------------------------------------------\n" << std::endl;
    std::cout << "intStack.swap(intStack2)" << std::endl;
	intStack.swap(intStack2);
    std::cout << "strStack.swap(strStack2)" << std::endl;
	strStack.swap(strStack2);
    std::cout << "intListStack.swap(intListStack2)\n" << std::endl;
	intListStack.swap(intListStack2);
    std::cout << "\n--------------------------------------------------------------\n" << std::endl;
    std::cout << "intStack.size():\t" << intStack.size() << std::endl;
    std::cout << "strStack.size():\t" << strStack.size() << std::endl;
    std::cout << "intListStack.size():\t" << intListStack.size() << std::endl << std::endl;
    std::cout << "intStack2.size():\t" << intStack2.size() << std::endl;
    std::cout << "strStack2.size():\t" << strStack2.size() << std::endl;
    std::cout << "intListStack2.size():\t" << intListStack2.size() << std::endl << std::endl;
    std::cout << "intStack2.top():\t" << intStack2.top() << std::endl;
    std::cout << "strStack2.top():\t" << strStack2.top() << std::endl;
    std::cout << "intListStack2.top():\t" << intListStack2.top() << std::endl << std::endl;
    std::cout << "\n<+==========================================================+>\n" << std::endl;
    std::cout << "intStack\t=\tintStack2" << std::endl;
	intStack = intStack2;
    std::cout << "strStack\t=\tstrStack" << std::endl;
	strStack = strStack2;
    std::cout << "intListStack\t=\tintListStack2\n" << std::endl;
	intListStack = intListStack2;
    std::cout << "intStack == intStack2\t?\t" << (intStack == intStack2 ? "true" : "false")  << std::endl;
    std::cout << "strStack == strStack2\t?\t" << (strStack == strStack2 ? "true" : "false")  << std::endl;
    std::cout << "intListStack == intListStack2 ?\t" << (intListStack == intListStack2 ? "true\n" : "false\n")  << std::endl;

	std::vector<int>	vec;
	for (size_t i = 0; i < 5; ++i)
		vec.push_back(i);
	ft::stack<int, std::vector<int> > stck(vec);
	while (stck.size())
	{
		std::cout << stck.top() << std::endl;
		stck.pop();
	}
	return 0;
}
