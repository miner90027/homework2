#include <iostream>
#include <string>
#include <list>
#include "catch.hpp"
using std::string;
using std::list;
using std::cout;
using std::endl;
using std::ostream;

struct Book{
	const string title_;
	const string author_;
	const int pubDate_;
};

ostream & operator<< (ostream &os, const Book &book){
	return os << book.title_ << "\nWritten by: " << book.author_ << "\nPublished in: " << book.pubDate_ << endl;
}

//globally declare the four books I will be using in the different tests
Book book1 {"The War of the Worlds", "H.G. Wells", 1898};
Book book2 {"Wine Bottles and Broomsticks","Dave S. Koster",2019};
Book book3 {"A Study in Scarlet", "Sir Arthur Conan Doyle", 1887};
Book book4 {"The Hobbit","J.R.R. Tolkien",1937};

TEST_CASE("Test Queue style list:"){
	list<Book> shelf;
	shelf.push_back(book1);
	shelf.push_back(book2);
	shelf.push_back(book3);
	shelf.push_back(book4);

	cout << shelf.front() << endl;
	REQUIRE(shelf.front().title_ == book1.title_);
}

TEST_CASE("Test stack style list"){
	//make list of books 1-4 in sorted order based on publication date with the newest being the first in the list
	list<Book> shelf;
	shelf.push_back(book2);
	shelf.push_back(book4);
	shelf.push_back(book1);
	shelf.push_back(book3);

	//REQUIRE()

	SECTION("Test insert and find"){

	}
}