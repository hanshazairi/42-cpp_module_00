/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:51:13 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/02 13:12:28 by hbaddrul         ###   ########.fr       */
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
using std::getline;
using std::isdigit;
using std::setw;
using std::stoi;

static int IsNumber(const string num) {
    for (size_t i = 0; i < num.length(); i++)
        if (!isdigit(num[i]))
            return 0;

    return 1;
}

PhoneBook::PhoneBook(void) : entries_(0) {}

void PhoneBook::AddContact(void) {
    int i = entries_++ % 8;
    contacts_[i].UpdateContact();
    cout << endl;
}

void PhoneBook::SearchContact(void) {
    int i;
    string idx;

    cout << "+----------+----------+----------+----------+" << endl;
    cout << "|    index |  f. name |  l. name | nickname |" << endl;
    cout << "+----------+----------+----------+----------+" << endl;

    for (int i = 0; i < 8; i++) {
        cout << "|";
        cout << setw(10) << i + 1 << "|";
        cout << setw(10) << contacts_[i].get_first_name_summary() << "|";
        cout << setw(10) << contacts_[i].get_last_name_summary() << "|";
        cout << setw(10) << contacts_[i].get_nickname_summary() << "|" << endl;
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
            cout << "First Name: " << contacts_[i - 1].get_first_name() << endl;
            cout << "Last Name: " << contacts_[i - 1].get_last_name() << endl;
            cout << "Nickname: " << contacts_[i - 1].get_nickname() << endl;
            cout << "Phone Number: " << contacts_[i - 1].get_phone_number() \
                    << endl;
            cout << "Darkest Secret: " \
                    << contacts_[i - 1].get_darkest_secret() << endl;
            cout << endl;
        }
    }
}
