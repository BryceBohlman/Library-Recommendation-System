#include "BookClass.h"
#include "LibraryMemberClass.h"

using namespace std;

class Book
{
private:
	string bookTitle;
	string author;
	string genre;
	vector<LibraryMember> *checkoutHistory;
	int userCount;

public:
	Book()
	{
		bookTitle = "";
		author = "";
		genre = "";
		checkoutHistory = NULL;
		userCount = 0;
	}

	Book(string title)
	{
		bookTitle = title;
		author = "";
		genre = "";
		checkoutHistory = NULL;
		userCount = 0;
	}
	
	Book(string title, string genre)
	{
		bookTitle = title;
		author = "";
		genre = genre;
		checkoutHistory = NULL;
		userCount = 0;
	}

	Book(string title, string writerName, string bookGenre)
	{
		bookTitle = title;
		author = writerName;
		genre = bookGenre;
		checkoutHistory = NULL;
		userCount = 0;
	}

	void recordCheckout(LibraryMember *user)
	{
		checkoutHistory[userCount] = user;
		userCount++;
	}

	string getTitle()
	{
		return bookTitle;
	}

	string getGenre()
	{
		return genre;
	}

	string getAuthor()
	{
		return author;
	}
};
