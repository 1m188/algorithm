#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

struct Book
{
    std::string bookName;
    std::string author;

    Book() : bookName(""), author("") {}
    Book(std::string b, std::string a) : bookName(b), author(a) {}
};
void BORROW(std::vector<Book> &shelf, std::vector<Book> &borrowBook);
void RETURN(std::vector<Book> &shelf, std::vector<Book> &returnBook);
void SHELVE(std::vector<Book> &shelf, std::vector<Book> &returnBook);

int main() //还是比较好做的，没有测试
{
    std::vector<Book> shelf{};
    std::string t = "";
    while (std::cin >> t && t != "END")
    {
        Book b = Book();
        b.bookName = t;
        std::cin >> b.author;
        shelf.push_back(b);
    }
    std::sort(shelf.begin(), shelf.end(), [&](Book a, Book b) {if (a.author != b.author){return a.author < b.author;} else {return a.bookName < b.bookName;} });

    std::vector<Book> borrowBook{}, returnBook{};
    while (std::cin >> t && !std::cin.eof())
    {
        if (t == "BORROW")
        {
            BORROW(shelf, borrowBook);
        }
        else if (t == "RETURN")
        {
            RETURN(shelf, returnBook);
        }
        else if (t == "SHELVE")
        {
            SHELVE(shelf, returnBook);
        }
    }

    return 0;
}

void BORROW(std::vector<Book> &shelf, std::vector<Book> &borrowBook)
{
    std::string bookName = "";
    std::cin >> bookName;
    std::string author = "";
    std::cin >> author;
    Book book(bookName, author);
    shelf.erase(std::find(shelf.begin(), shelf.end(), book));
    borrowBook.push_back(book);
}

void RETURN(std::vector<Book> &shelf, std::vector<Book> &returnBook)
{
    std::string bookName = "";
    std::cin >> bookName;
    std::string author = "";
    std::cin >> author;
    Book book(bookName, author);
    returnBook.push_back(book);
}

void SHELVE(std::vector<Book> &shelf, std::vector<Book> &returnBook)
{
    std::sort(returnBook.begin(), returnBook.end(), [&](Book a, Book b) {if (a.author != b.author){return a.author < b.author;} else {return a.bookName < b.bookName;} });
    for (std::vector<Book>::iterator it = returnBook.begin(); it != returnBook.end(); it++)
    {
        for (int i = 0; i < shelf.size(); i++)
        {
            if (shelf[i].author > it->author)
            {
                std::cout << it->bookName << std::endl;
                std::cout << i - 1 << std::endl;
            }
            else if (shelf[i].author == it->author)
            {
                if (shelf[i].bookName > it->bookName)
                {
                    std::cout << it->bookName << std::endl;
                    std::cout << i - 1 << std::endl;
                }
            }
        }
    }
}