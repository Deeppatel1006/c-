#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class bookdata
{
  string b_name;
  string b_author;
  float b_isbn;
  int b_qty;
  int status = 0;

public:
  void acceptbookdata()
  {
    cout << "\nInsert Book Title: ";
    cin >> b_name;
    cout << "Insert author name: ";
    cin >> b_author;
    cout << "Insert ISBN: ";
    cin >> b_isbn;
    cout << "Insert quantity of book: ";
    cin >> b_qty;
    status = 0;
  }
  void displaydata()
  {
    cout << "***************" << endl;
    cout << "Title      : " << b_name << endl;
    cout << "Author     : " << b_author << endl;
    cout << "ISBN       : " << b_isbn << endl;
    cout << "Quantity   : " << b_qty << endl;
    if (status == 0)
    {
      cout << "Status : Not Isseued" << endl;
    }
    else
    {
      cout << "Status : Isseued" << endl;
    }
    cout << "***************" << endl;
  }
  void addbookdata();
  void searchbookdata();
  void deletebookdata();
};
bookdata obj;
void bookdata::addbookdata()
{
  obj.acceptbookdata();
  fstream wr;
  wr.open("./data.txt", ios::app);
  wr.write((char *)&obj, sizeof(obj));
  cout << "***************" << endl;
  cout << "Book Added Successfully" << endl;
  cout << "***************" << endl;
}
void bookdata::searchbookdata()
{
  fstream rd;
  rd.open("./data.txt", ios::in);
  char n[50];
  cout << "Enter Title of book: ";
  cin >> n;
  rd.seekg(0, ios::end);
  int size = rd.tellg() / sizeof(obj);
  rd.seekg(0, ios::beg);
  int flag = 0;
  for (int i = 1; i <= size; i++)
  {
    rd.read((char *)&obj, sizeof(obj));
    if (strcmp(n, obj.b_name.c_str()) == 0)
    {
      flag = 1;
        cout << "***************" << endl;
        cout << "Title      : " << obj.b_name << endl;
        cout << "Author     : " << obj.b_author << endl;
        cout << "ISBN       : " << obj.b_isbn << endl;
        cout << "Quantity   : " << obj.b_qty << endl;
    }
  }
  if (flag == 0)
  {
    cout << "Sorry We didn't find that book !" << endl;
  }
  else
  {
    cout << "***************" << endl;
    cout << "Book Found" << endl;
    cout << "***************" << endl;
  }
}
void bookdata::deletebookdata()
{
  fstream rd, wr;
  rd.open("./data.txt", ios::in);
  wr.open("./temp.txt", ios::app);
  char n[50];
  cout << "Enter Title of the Book :";
  cin >> n;
  rd.seekg(0, ios::end);
  int size = rd.tellg() / sizeof(obj);
  rd.seekg(0, ios::beg);
  int flag = 0;
  for (int i = 1; i <= size; i++)
  {
    rd.read((char *)&obj, sizeof(obj));
    if (strcmp(n, obj.b_name.c_str()) == 0)
    {
      cout << "Book Removed" << endl;
    }
    else
    {
      wr.write((char *)&obj, sizeof(obj));
    }
  }
  rd.close();
  wr.close();
  remove("./data.txt");
  rename("./temp.txt", "./data.txt");
}
int main()
{
  int choice;
  cout << "******* Welcome To Library Management System ********" << endl;
  while (1)
  {
    cout << "What would you want me to do ?" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Search Book" << endl;
    cout << "3. Remove Book" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    if (choice == 1)
    {
      bookdata b1;
      b1.addbookdata();
    }
    else if (choice == 2)
    {
      bookdata b1;
      b1.searchbookdata();
    }
    else if (choice == 3)
    {
      bookdata b1;
      b1.deletebookdata();
    }
    else if (choice == 4)
    {
      break;
    }
    else
    {
      cout << "Invalid Choice...." << endl;
    }
  }
  cout << "Thank You for using my system" << endl
       << "Have a Nice Day !" << endl;
  return 0;
}

