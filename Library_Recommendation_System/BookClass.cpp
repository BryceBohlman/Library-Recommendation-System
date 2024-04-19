#include "BookClass.h"
#include "LibraryMemberClass.h"

using namespace std;

class Book
{
private:
	string bookTitle;
	string author;
	string genre;
	vector<LibraryMember *> checkoutHistory;

public:
	Book()
	{
		bookTitle = "";
		author = "";
		genre = "";
	}

	Book(string title)
	{
		bookTitle = title;
		author = "";
		genre = "";
	}
	
	Book(string title, string genre)
	{
		bookTitle = title;
		author = "";
		genre = genre;
	}

	Book(string title, string writerName, string bookGenre)
	{
		bookTitle = title;
		author = writerName;
		genre = bookGenre;
	}

	void recordCheckout(LibraryMember *user)
	{
		checkoutHistory[checkoutHistory.size()] = user;
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
