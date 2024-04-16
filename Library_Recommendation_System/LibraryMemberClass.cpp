#include "LibraryMemberClass.h"
#include "BookClass.h"
#include "BookClass.cpp"

using namespace std;

class LibraryMember
{
private:
	string name;
	//string memberID;
	Book *bookCheckoutHistory[1000];
	Book *fullLibraryCatalogue[1000];
	Book *recommendedTitles[1000];
	int checkoutHistoryCount;
	int fullCatalogueCount;
	int recommendationsCount;

public:
	LibraryMember()
	{
		name = "";
		checkoutHistoryCount = 0;
		fullCatalogueCount = 0;
		recommendationsCount = 0;
		*bookCheckoutHistory = NULL;
		*fullLibraryCatalogue = NULL;
		*recommendedTitles = NULL;
	}

	LibraryMember(string userName)
	{
		name = userName;
		checkoutHistoryCount = 0;
		fullCatalogueCount = 0;
		recommendationsCount = 0;
		*bookCheckoutHistory = NULL;
		*fullLibraryCatalogue = NULL;
		*recommendedTitles = NULL;
	}

	LibraryMember(string userName, Book &libraryCatalogue, int libraryCatalogueSize)
	{
		name = userName;
		checkoutHistoryCount = 0;
		recommendationsCount = 0;
		*recommendedTitles = NULL;
		*bookCheckoutHistory = NULL;
		*fullLibraryCatalogue = &libraryCatalogue;
		fullCatalogueCount = libraryCatalogueSize;
	}

	void AttachSecondVertexSet(Book& libraryCatalogue, int libraryCatalogueSize)
	{
		*fullLibraryCatalogue = &libraryCatalogue;
		fullCatalogueCount = libraryCatalogueSize;
	}

	void CheckOutBook(string bookTitle)
	{
		if (fullCatalogueCount)
		{
			for (int i = 0; i < fullCatalogueCount; i++)
			{
				if (bookTitle == fullLibraryCatalogue[i]->getTitle())
				{
					bookCheckoutHistory[checkoutHistoryCount] = fullLibraryCatalogue[i];
					checkoutHistoryCount++;
					fullLibraryCatalogue[i]->recordCheckout(*this);
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
		for (int i = 0; i < checkoutHistoryCount; i++)
		{
			for (int j = 0; j < fullCatalogueCount; j++)	//O(n^2) need to find more efficient implementation
			{												
				if (bookCheckoutHistory[i]->getGenre() == fullLibraryCatalogue[j]->getGenre())
				{
					recommendedTitles[recommendationsCount] = fullLibraryCatalogue[j];
					recommendationsCount++;
				}
				else if (bookCheckoutHistory[i]->getAuthor() == fullLibraryCatalogue[j]->getAuthor())
				{
					recommendedTitles[recommendationsCount] = fullLibraryCatalogue[j];
					recommendationsCount++;
				}
			}
		}
	}

	void RemoveSpecificRecommendation(string bookTitle)
	{
		for (int i = 0; i < recommendationsCount; i++)
		{
			if (recommendedTitles[i]->getTitle() == bookTitle)
			{
				recommendedTitles[i] = recommendedTitles[i+1];
				break;
			}
		}
	}

	void RemoveRecommendationsByGenre(string bookGenre)
	{
		for (int i = 0; i < recommendationsCount; i++)
		{
			if (recommendedTitles[i]->getGenre() == bookGenre)
			{
				recommendedTitles[i] = recommendedTitles[i + 1];
			}
		}
	}

	void PrintOutUserHistory()
	{
		for (int i = 0; i < checkoutHistoryCount; i++)
		{
			cout << bookCheckoutHistory[i]->getTitle() << '\n';
		}
		
		cout << endl;
	}

	void PrintOutRecommendations()
	{
		for (int i = 0; i < recommendationsCount; i++)
		{
			cout << recommendedTitles[i]->getTitle() << '\n';
		}

		cout << endl;
	}
};
