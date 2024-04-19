#include "LibraryMemberClass.h"
#include "BookClass.h"
#include "BookClass.cpp"

using namespace std;

class LibraryMember
{
private:
	string name;
	vector<Book *> bookCheckoutHistory;
	vector<Book> fullLibraryCatalogue;
	vector<Book> recommendedTitles;


public:
	LibraryMember()
	{
		name = "";
	}

	LibraryMember(string userName)
	{
		name = userName;
	}

	LibraryMember(string userName, vector<Book>& libraryCatalogue)
	{
		name = userName;
		fullLibraryCatalogue = libraryCatalogue;
	}

	void AttachSecondVertexSet(vector<Book>& libraryCatalogue)
	{
		fullLibraryCatalogue = libraryCatalogue;
	}

	void CheckOutBook(string bookTitle)
	{
		if (fullLibraryCatalogue.size())
		{
			for (int i = 0; i < fullLibraryCatalogue.size(); i++)
			{
				if (bookTitle == fullLibraryCatalogue[i].getTitle())
				{
					bookCheckoutHistory[bookCheckoutHistory.size()] = &fullLibraryCatalogue[i];
					fullLibraryCatalogue[i].recordCheckout(this);
				}
			}
		}
		else
		{ 
			cout << "No books in catalogue" << endl;
		}
	}

	void PopulateRecommendationArray()
	{
		for (int i = 0; i < bookCheckoutHistory.size(); i++)
		{
			for (int j = 0; j < fullLibraryCatalogue.size(); j++)	//O(n^2) need to find more efficient implementation
			{		
				if (bookCheckoutHistory[i]->getGenre() == fullLibraryCatalogue[j].getGenre())
				{
					recommendedTitles[recommendedTitles.size()] = fullLibraryCatalogue[j];
				}
				else if (bookCheckoutHistory[i]->getAuthor() == fullLibraryCatalogue[j].getAuthor())
				{
					recommendedTitles[recommendedTitles.size()] = fullLibraryCatalogue[j];
				}
			}
		}
	}

	void RemoveSpecificRecommendation(string bookTitle)
	{
		for (int i = 0; i < recommendedTitles.size(); i++)
		{
			if (recommendedTitles[i].getTitle() == bookTitle)
			{
				recommendedTitles.erase(recommendedTitles.begin() + i);
				break;
			}
		}
	}

	void RemoveRecommendationsByGenre(string bookGenre)
	{
		for (int i = 0; i < recommendedTitles.size(); i++)
		{
			if (recommendedTitles[i].getGenre() == bookGenre)
			{
				recommendedTitles.erase(recommendedTitles.begin() + i);
			}
		}
	}

	void RemoveRecommendationByAuthor(string bookAuthor)
	{
		for (int i = 0; i < recommendedTitles.size(); i++)
		{
			if (recommendedTitles[i].getAuthor() == bookAuthor)
			{
				recommendedTitles.erase(recommendedTitles.begin() + i);
			}
		}
	}

	void PrintOutUserHistory()
	{
		for (int i = 0; i < bookCheckoutHistory.size(); i++)
		{
			cout << bookCheckoutHistory[i]->getTitle() << '\n';
		}
		
		cout << endl;
	}

	void PrintOutRecommendations()
	{
		for (int i = 0; i < recommendedTitles.size(); i++)
		{
			cout << recommendedTitles[i].getTitle() << '\n';
		}

		cout << endl;
	}
};
