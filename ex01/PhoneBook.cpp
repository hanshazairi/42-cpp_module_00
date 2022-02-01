/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:51:13 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/01 16:48:02 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

#include "PhoneBook.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::isdigit;
using std::setw;
using std::stoi;

PhoneBook::PhoneBook(void) {
    entries_ = 0;
}

static int  IsNumber(const string num) {
    for (size_t i = 0; i < num.length(); i++)
        if (!isdigit(num[i]))
            return (0);

    return (1);
}

void    PhoneBook::AddContact(void) {
    int i;

    i = entries_++ % 8;
    contacts_[i].RemoveContact();
    contacts_[i].CreateContact();
    cout << endl;
}

void    PhoneBook::SearchContact(void) {
    int     i;
    string  idx;

    cout << "+----------+----------+----------+----------+" << endl;
    cout << "|    index |  f. name |  l. name | nickname |" << endl;
    cout << "+----------+----------+----------+----------+" << endl;

    for (int i = 0; i < 8; i++) {
        cout << "|";
        cout << setw(10) << i + 1 << "|";
        cout << setw(10) << contacts_[i].GetFirstNameSummary() << "|";
        cout << setw(10) << contacts_[i].GetLastNameSummary() << "|";
        cout << setw(10) << contacts_[i].GetNicknameSummary() << "|";
        cout << endl;
        cout << "+----------+----------+----------+----------+" << endl;
    }

    cout << endl;
    i = -1;

    while (i != 0) {
        cout << "Contact [1-8, 0 to exit]: ";
        getline(cin, idx);

        if (cin.eof())
            break;

        if (idx.empty() || !IsNumber(idx))
            continue;

        i = stoi(idx);

        if (i >= 1 && i <= 8) {
            cout << "First Name: " << contacts_[i - 1].GetFirstName() << endl;
            cout << "Last Name: " << contacts_[i - 1].GetLastName() << endl;
            cout << "Nickname: " << contacts_[i - 1].GetNickname() << endl;
            cout << "Phone Number: " << contacts_[i - 1].GetPhoneNumber() \
                    << endl;
            cout << "Darkest Secret: " << contacts_[i - 1].GetDarkestSecret() \
                    << endl;
            cout << endl;
        }
    }
}
