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

//overload << operator to print all book data
ostream & operator<< (ostream &os, const Book &book){
	return os << book.title_ << "\nWritten by: " << book.author_ << "\nPublished in: " << book.pubDate_ << endl;
}
//overload == operator to compare that 2 books are the same
bool operator== (const Book &b1, const Book &b2){
	if(b1.title_ == b2.title_ && b1.author_ == b2.author_ && b1.pubDate_ == b2.pubDate_){
		return true;
	}
	else
		return false;
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

	REQUIRE(shelf.front().title_ == book1.title_);
	REQUIRE(shelf.back() == book4);
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