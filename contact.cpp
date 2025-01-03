#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
using namespace std;

int print_search(AddressBook *addressBook, char *search_term, int flag);
int del_fun(AddressBook *addressBook, char *search_term, int flag);
int editfun(AddressBook *addressBook, char *search_term, char *edit_term, int flag);

void listContacts(AddressBook *addressBook)
{
    cout << "\n\n------------------------Address Book Contacts-------------------------\n\n"
         << endl;
    cout << left << setw(25) << "Name" << setw(25) << "Phone No" << setw(305) << "Email" << endl;
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        cout << left << setw(25) << addressBook->contacts[i].name << setw(25) << addressBook->contacts[i].phone << setw(30) << addressBook->contacts[i].email << endl;
    }
    
}

void initialize(AddressBook *addressBook)
{
    populateAddressBook(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    
}


void createContact(AddressBook *addressBook)
{
    populateAddressBook(addressBook);
    char new_name[50];
    char new_phone[20];
    char new_email[50];
    getchar();
    cout << "Enter the name you want to add" << endl;
    cin.getline(new_name, 50);

    cout << "Enter the phone you want to add" << endl;
    cin.getline(new_phone, 20);

    cout << "Enter the email you want to add" << endl;
    cin.getline(new_email, 50);

    int name_found = print_search(addressBook, new_name, 1);
    int name_phone = print_search(addressBook, new_phone, 2);
    int name_email = print_search(addressBook, new_email, 3);

    if (name_phone != 0)
    {
        cout << "The phone number already exists in the addressBook" << endl;
    }
    else if (name_email != 0)
    {
        cout << "The email already exists in the addressBook" << endl;
    }
    else
    {
        strcpy(addressBook->contacts[addressBook->contactCount].name, new_name);
        strcpy(addressBook->contacts[addressBook->contactCount].phone, new_phone);
        strcpy(addressBook->contacts[addressBook->contactCount].email, new_email);
        addressBook->contactCount++;
        printf("Contact added successfully");
    }
}

void searchContact(AddressBook *addressBook)
{
    populateAddressBook(addressBook);
    cout << "Enter your choice to search\n1.Search by Name\n2.Search by phone number\n3.Search by email" << endl;
    int choice;
    cin >> choice;
    int flag = 0;
    flag = choice;
    int found = 0;
    switch (choice)
    {
    case 1:
    {
        getchar();
        char search_name[20];
        cout << "Enter the name you want to search" << endl;
        cin.getline(search_name, 20);
        found = print_search(addressBook, search_name, flag);
        if (found == 0)
        {
            cout << "Entered name is not present in the addresbook" << endl;
        }
        else
        {
            cout << "Printed the details of user successfully" << endl;
        }
    }
    break;

    case 2:
    {
        char search_phone[20];
        cout << "Enter the phone number you want to search" << endl;
        cin.getline(search_phone, 20);
        found = print_search(addressBook, search_phone, flag);
        if (found == 0)
        {
            cout << "Entered phone number is not present in the addresbook" << endl;
        }
        else
        {
            cout << "Printed the details of user successfully" << endl;
        }
    }
    break;

    case 3:
    {
        char search_email[20];
        cout << "Enter the email you want to search" << endl;
        cin.getline(search_email, 20);
        found = print_search(addressBook, search_email, flag);
        if (found == 0)
        {
            cout << "Entered email is not present in the addresbook" << endl;
        }
        else
        {
            cout << "Printed the details of user successfully" << endl;
        }
    }
    break;
    }
}

int print_search(AddressBook *addressBook, char *search_term, int flag)
{
    int found = 0;
    switch (flag)
    {
    case 1:
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].name, search_term) == 0)
            {
                cout << endl;
                cout << "The details of the searced user are:  " << endl;
                cout << left << setw(25) << addressBook->contacts[i].name << setw(25) << addressBook->contacts[i].phone << setw(30) << addressBook->contacts[i].email << endl;
                found = 1;
            }
        }
    }
    break;

    case 2:
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, search_term) == 0)
            {
                cout << endl;
                cout << "The details of the searced user are:  " << endl;
                cout << left << setw(25) << addressBook->contacts[i].name << setw(25) << addressBook->contacts[i].phone << setw(30) << addressBook->contacts[i].email << endl;
                found = 1;
            }
        }
    }
    break;

    case 3:
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].email, search_term) == 0)
            {
                cout << endl;
                cout << "The details of the searced user are:  " << endl;
                cout << left << setw(25) << addressBook->contacts[i].name << setw(25) << addressBook->contacts[i].phone << setw(30) << addressBook->contacts[i].email << endl;
                found = 1;
            }
        }
    }
    break;
    }

    return found;
}

void editContact(AddressBook *addressBook)
{
    populateAddressBook(addressBook);
    cout << "Enter your choice to search\n1.Search by Name\n2.Search by phone number\n3.Search by email" << endl;
    int choice;
    cin >> choice;
    int flag = 0;
    flag = choice;
    int found = 0;
    switch (choice)
    {
    case 1:
    {
        getchar();
        char search_name[50];
        cout << "Enter the name you want to search" << endl;
        cin.getline(search_name, 50);
        found = print_search(addressBook, search_name, flag);
        if (found == 0)
        {
            cout << "Entered name is not present in the addresbook" << endl;
        }
        else
        {
            cout << "Printed the details of user successfully" << endl;
        }
        cout << "Enter your choice to edit\n1.Edit By name\n2.Edit by phone\n3.Edit by email\n"
             << endl;
        int opt;
        cin >> opt;
        int edit_flag = opt;
        switch (opt)
        {
        case 1:
        {
            getchar();
            char search_term[50];
            cout << "Enter the new name: " << endl;
            cin.getline(search_term, 50);
            int edit_name = editfun(addressBook, search_name, search_term, edit_flag);
            if (edit_name == 0)
            {
                cout << "Failed to edit" << endl;
            }
        }
        break;
        case 2:
        {
            getchar();
            char search_term[50];
            cout << "Enter the new phone: " << endl;
            cin.getline(search_term, 50);
            int edit_phone = editfun(addressBook, search_name, search_term, flag);
            if (edit_phone == 0)
            {
                cout << "Failed to edit" << endl;
            }
        }
        break;
        case 3:
        {
            getchar();
            char search_term[50];
            cin.getline(search_term, 50);
            cout << "Enter the new email: " << endl;
            int edit_email = editfun(addressBook, search_name, search_term, flag);
            if (edit_email == 0)
            {
                cout << "Failed to edit" << endl;
            }
        }
        break;
        }
    }
    break;

    case 2:
    {
        char search_phone[20];
        cout << "Enter the phone number you want to search" << endl;
        cin.getline(search_phone, 20);
        found = print_search(addressBook, search_phone, flag);
        if (found == 0)
        {
            cout << "Entered phone number is not present in the addresbook" << endl;
        }
        else
        {
            cout << "Printed the details of user successfully" << endl;
        }
        cout << "Enter your choice to edit\n1.Edit By name\n2.Edit by phone\n3.Edit by email\n"
             << endl;
        int opt;
        cin >> opt;
        int edit_flag = opt;
        switch (opt)
        {
        case 1:
        {
            getchar();
            char search_term[50];
            cout << "Enter the new phone number" << endl;
            cin.getline(search_term, 50);
            int edit_name = editfun(addressBook, search_phone, search_term, edit_flag);
            if (edit_name == 0)
            {
                cout << "Failed to edit" << endl;
            }
        }
        break;
        case 2:
        {
            getchar();
            char search_term[50];
            cout << "Enter the new phone number" << endl;
            cin.getline(search_term, 50);
            int edit_phone = editfun(addressBook, search_phone, search_term, flag);
            if (edit_phone == 0)
            {
                cout << "Failed to edit" << endl;
            }
        }
        break;
        case 3:
        {
            getchar();
            char search_term[50];
            cout << "Enter the new phone number" << endl;
            cin.getline(search_term, 50);
            int edit_email = editfun(addressBook, search_phone, search_term, flag);
            if (edit_email == 0)
            {
                cout << "Failed to edit" << endl;
            }
        }
        break;
        }
    }
    break;

    case 3:
    {
        char search_email[20];
        cout << "Enter the email you want to search" << endl;
        cin.getline(search_email, 20);
        found = print_search(addressBook, search_email, flag);
        if (found == 0)
        {
            cout << "Entered email is not present in the addresbook" << endl;
        }
        else
        {
            cout << "Printed the details of user successfully" << endl;
        }
        cout << "Enter your choice to edit\n1.Edit By name\n2.Edit by phone\n3.Edit by email\n"
             << endl;
        int opt;
        cin >> opt;
        int edit_flag = opt;
        switch (opt)
        {
        case 1:
        {
            getchar();
            char search_term[50];
            cout << "Enter the new email" << endl;
            cin.getline(search_term, 50);
            int edit_name = editfun(addressBook, search_email, search_term, edit_flag);
            if (edit_name == 0)
            {
                cout << "Failed to edit" << endl;
            }
        }
        break;
        case 2:
        {
            getchar();
            char search_term[50];
            cout << "Enter the new email" << endl;
            cin.getline(search_term, 50);
            int edit_phone = editfun(addressBook, search_email, search_term, flag);
            if (edit_phone == 0)
            {
                cout << "Failed to edit" << endl;
            }
        }
        break;
        case 3:
        {
            getchar();
            char search_term[50];
            cout << "Enter the new email" << endl;
            cin.getline(search_term, 50);
            int edit_email = editfun(addressBook, search_email, search_term, flag);
            if (edit_email == 0)
            {
                cout << "Failed to edit" << endl;
            }
        }
        break;
        }
    }
    break;
    }
}

int editfun(AddressBook *addressBook, char *search_term, char *edit_term, int flag)
{
    int edit_found = 0;
    switch (flag)
    {
    case 1:
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].name, search_term) == 0)
            {
                strcpy(addressBook->contacts[i].name, edit_term);
                cout << "Edited the name successfully" << endl;
                edit_found = 1;
            }
        }
    }
    break;

    case 2:
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, search_term) == 0)
            {
                strcpy(addressBook->contacts[i].phone, edit_term);
                cout << "Edited the Phone number successfully" << endl;
                edit_found = 1;
            }
        }
    }
    break;

    case 3:
    {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].email, search_term) == 0)
            {
                strcpy(addressBook->contacts[i].email, edit_term);
                cout << "Edited the email successfully" << endl;
                edit_found = 1;
            }
        }
    }
    break;
    }
    return edit_found;
}

void deleteContact(AddressBook *addressBook)
{
    populateAddressBook(addressBook);
    cout << "Enter your choice to search\n1.Search by Name\n2.Search by phone number\n3.Search by email" << endl;
    int choice;
    cin >> choice;
    int flag = 0;
    flag = choice;
    int found = 0;
    switch (choice)
    {
    case 1:
    {
        getchar();
        char search_name[20];
        cout << "Enter the name you want to search" << endl;
        cin.getline(search_name, 20);
        found = print_search(addressBook, search_name, flag);
        if (found == 0)
        {
            cout << "Entered name is not present in the addresbook" << endl;
        }
        else
        {
            cout << "Printed the details of user successfully" << endl;
        }
        int del_found = del_fun(addressBook, search_name, 1);
        if (del_found == 0)
        {
            cout << "Entered user is not in the addressBook" << endl;
        }
    }
    break;

    case 2:
    {
        char search_phone[20];
        cout << "Enter the phone number you want to search" << endl;
        cin.getline(search_phone, 20);
        found = print_search(addressBook, search_phone, flag);
        if (found == 0)
        {
            cout << "Entered phone number is not present in the addresbook" << endl;
        }
        else
        {
            cout << "Printed the details of user successfully" << endl;
        }
        int del_found = del_fun(addressBook, search_phone, 2);
        if (del_found == 0)
        {
            cout << "Entered user is not in the addressBook" << endl;
        }
    }
    break;

    case 3:
    {
        char search_email[20];
        cout << "Enter the email you want to search" << endl;
        cin.getline(search_email, 20);
        found = print_search(addressBook, search_email, flag);
        if (found == 0)
        {
            cout << "Entered email is not present in the addresbook" << endl;
        }
        else
        {
            cout << "Printed the details of user successfully" << endl;
        }
        int del_found = del_fun(addressBook, search_email, 3);
        if (del_found == 0)
        {
            cout << "Entered user is not in the addressBook" << endl;
        }
    }
    break;
    }
}

int del_fun(AddressBook *addressBook, char *search_term, int flag)
{
    int del_found = 0;
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        switch (flag)
        {
        case 1:
        {
            if (strcmp(addressBook->contacts[i].name, search_term) == 0)
            {
                for (int j = i; j < addressBook->contactCount - 1; j++)
                {
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    del_found = 1;
                }
            }
        }
        break;

        case 2:
        {
            if (strcmp(addressBook->contacts[i].phone, search_term) == 0)
            {
                for (int j = i; j < addressBook->contactCount - 1; j++)
                {
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    del_found = 1;
                }
            }
        }
        break;

        case 3:
        {
            if (strcmp(addressBook->contacts[i].email, search_term) == 0)
            {
                for (int j = i; j < addressBook->contactCount - 1; j++)
                {
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    del_found = 1;
                }
            }
        }
        break;
        }
        if (del_found)
        {
            addressBook->contactCount--;
            cout << "User deleted successfully" << endl;
        }
    }
    if (!del_found)
    {
        cout << "Failed to Delete User" << endl;
    }
    return del_found;
}
