#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    bool available;

    Book(string t, string a) {
        title = t;
        author = a;
        available = true;
    }
};

class Member {
public:
    string name;
    vector<string> borrowedBooks;

    Member(string n) {
        name = n;
    }
};

int main() {

    vector<Book> books;
    vector<Member> members;

    int choice;
    string title, author, name;

    do {
        cout << "\n=== Library Management System ===" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Borrow Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Search Book" << endl;
        cout << "6. Display All Books" << endl;
        cout << "7. Exit" << endl;

        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                cout << "Enter book title: ";
                getline(cin >> ws, title);

                cout << "Enter author: ";
                getline(cin >> ws, author);

                bool found = false;

                for (int i = 0; i < books.size(); i++) {
                    if (books[i].title == title) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    cout << "Book already exists!" << endl;
                }
                else {
                    books.push_back(Book(title, author));
                    cout << "Book \"" << title << "\" added." << endl;
                }

                break;
            }

            case 2: {
                cout << "Enter book title to remove: ";
                getline(cin >> ws, title);

                bool found = false;

                for (int i = 0; i < books.size(); i++) {
                    if (books[i].title == title) {

                        if (!books[i].available) {
                            cout << "Cannot remove a borrowed book!" << endl;
                        }
                        else {
                            books.erase(books.begin() + i);
                            cout << "Book \"" << title << "\" removed." << endl;
                        }

                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Book not found!" << endl;
                }

                break;
            }

            case 3: {
                cout << "Enter book title to borrow: ";
                getline(cin >> ws, title);

                bool found = false;

                for (int i = 0; i < books.size(); i++) {
                    if (books[i].title == title) {

                        if (books[i].available) {
                            books[i].available = false;

                            cout << "\"" << title
                                 << "\" borrowed successfully." << endl;
                        }
                        else {
                            cout << "Book is already borrowed!" << endl;
                        }

                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Book not found!" << endl;
                }

                break;
            }

            case 4: {
                cout << "Enter book title to return: ";
                getline(cin >> ws, title);

                bool found = false;

                for (int i = 0; i < books.size(); i++) {
                    if (books[i].title == title) {

                        if (!books[i].available) {
                            books[i].available = true;

                            cout << "\"" << title
                                 << "\" returned successfully." << endl;
                        }
                        else {
                            cout << "Book is not borrowed!" << endl;
                        }

                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Book not found!" << endl;
                }

                break;
            }

            case 5: {
                cout << "Enter book title or author: ";
                getline(cin >> ws, name);

                bool found = false;

                for (int i = 0; i < books.size(); i++) {
                    if (books[i].title == name ||
                        books[i].author == name) {

                        cout << "\nTitle: " << books[i].title << endl;
                        cout << "Author: " << books[i].author << endl;

                        if (books[i].available) {
                            cout << "Status: Available" << endl;
                        }
                        else {
                            cout << "Status: Borrowed" << endl;
                        }

                        found = true;
                    }
                }

                if (!found) {
                    cout << "Book not found!" << endl;
                }

                break;
            }

            case 6: {
                if (books.empty()) {
                    cout << "No books in the library." << endl;
                }
                else {
                    for (int i = 0; i < books.size(); i++) {

                        cout << "\nTitle: " << books[i].title;
                        cout << " | Author: " << books[i].author;

                        if (books[i].available) {
                            cout << " | Status: Available" << endl;
                        }
                        else {
                            cout << " | Status: Borrowed" << endl;
                        }
                    }
                }

                break;
            }

            case 7:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid option! Try again." << endl;
        }

    } while (choice != 7);

    return 0;
}