#include <iostream>
#include <string>
#include <list>
#include "catch.hpp"
using std::string;
using std::list;
using std::cout;
using std::endl;
using std::ostream;

//struct Book which stores book data
struct Book {
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
//overload < operator to compare that the publication date of b1 is before b2
//aka- check that b1 is older than b2
bool operator< (const Book &b1, const Book &b2){
	if(b1.pubDate_ < b2.pubDate_)
		return true;
	else
		return false;
}
//overload <= operator to compare that the publication date of b1 is before b2
//aka- check that b1 is older than or the same age as b2
bool operator<= (const Book &b1, const Book &b2){
	if(b1.pubDate_ <= b2.pubDate_)
		return true;
	else
		return false;
}
//overload > operator to compare that the publication date of b1 is after b2
//aka- check that b1 is newer than b2
bool operator> (const Book &b1, const Book &b2){
	if(b1.pubDate_ > b2.pubDate_)
		return true;
	else
		return false;
}

//globally declare the four main books I will be using in the different tests
Book book1 {"The War of the Worlds", "H.G. Wells", 1898};
Book book2 {"Wine Bottles and Broomsticks","Dave S. Koster",2019};
Book book3 {"A Study in Scarlet", "Sir Arthur Conan Doyle", 1887};
Book book4 {"The Hobbit","J.R.R. Tolkien",1937};

TEST_CASE("Test Queue style list:"){
	list<Book> shelf = {book1, book2, book3};
	//add object to end of list & check to make sure it was added
	shelf.push_back(book4);
	REQUIRE(shelf.back() == book4);

	//remove first object in list & check that it was changed
	shelf.pop_front();
	REQUIRE(shelf.front()== book2);
}

TEST_CASE("Test stack style list:"){
	//initialize list of books
	list<Book> shelf = {book3,book4,book1};
	shelf.push_back(book2);
	//test to make sure that book2 was added to the end of the list
	REQUIRE(shelf.back() == book2);
	//remove last book & check to make sure it was removed
	shelf.pop_back();
	REQUIRE(shelf.back() == book1);
}

TEST_CASE("Test insert & find"){
	//make list of books 1-4 in sorted order based on publication date with the newest being the first in the list
	list<Book> shelf = {book2, book4, book1, book3};
	const Book book5 {"Moby Dick","Herman Melville",1851};
	shelf.sort();
	//test to make sure the list is sorted by date
	REQUIRE(shelf.front() < shelf.back());

	// search for book1 in the list
	bool isFound = false;
	for(auto i: shelf){
		if(i == book1) {
			isFound = true;
			break;
		}
	}
	//test to make sure that book1 was found
	REQUIRE(isFound);

	//insert book5 into list
	shelf.push_back(book5);
	shelf.sort();
	for(auto i: shelf){
		//check to make sure the list is sorted with the oldest book being the first in the list
		REQUIRE(i <= shelf.back());
	}

	//print the list
	cout << "Printing the list:" << endl;
	for(auto i: shelf){
		cout << i;
		cout << "-------------" << endl;
	}
}