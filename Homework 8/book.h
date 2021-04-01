#include <string>
using namespace std;

class Book {
private:
	string title;
	int ID, aisle;
	string bookType;

public:
	Book();		// constructor

	void setTitle(string title_input);
	void setID(int id_input);
	void setAisle(int aisle_input);
	void setBookType(string bookType_input);
	void displayBook();
	string getTitle();
	int getID();
	int getAisle();
	string getBookType();
};
