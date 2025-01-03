#include <iostream>
#include <iomanip>
#include "contact.h"
using namespace std;

AddressBook Book;

int main()
{
    int choice;
    Book.contactCount = 0;
    do
    {
        cout << "\n\n------------------------Address Book Menu-------------------------\n\n"
         << endl;
        cout << "1.Create Contact." << endl;
        cout << "2.Search Contact." << endl;
        cout << "3.Edit Contact." << endl;
        cout << "4.Delete Contact." << endl;
        cout << "5.List all Contacts." << endl;
        cout << "6.Exit." << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {

        case 1:
        {
            createContact(&Book);
        }
        break;

        case 2:
        {
            searchContact(&Book);
        }
        break;

        case 3:
        {
            editContact(&Book);
        }
        break;

        case 4:
        {
            deleteContact(&Book);  
        }
        break;

        case 5:
        {
            if (Book.contactCount != 0)
            {
                listContacts(&Book);
            }
            else
            {
                initialize(&Book);
                listContacts(&Book);
            }

            break;
           
        }
        break;
        }

    } while (choice != 6);
}
