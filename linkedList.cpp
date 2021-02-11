#include <iostream>
#include <string>
#include <list>
#include "catch.hpp"
using std::string;
using std::list;

struct Book{
	string title_;
	string author_;
	string pubDate_;
};

TEST_CASE("Test Queue"){
	Book book1 {"The War of the Worlds", "H.G. Wells", "1898"};
	Book book2 {"Wine Bottles and Broomsticks","Dave S. Koster","2019"};
	Book book3 {"A Study in Scarlet", "Sir Arthur Conan Doyle", "1887"};
	Book book4 {"The Hobbit","J.R.R. Tolkien","1937"};

	list<Book> shelf ={book1, book2, book3, book4};
}