/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:52:52 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/02 13:13:10 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Contact.hpp"

using std::cin;
using std::cout;
using std::getline;
using std::string;

static string TrimWhitespace(const string str) {
    const string whitespace = "\t\n\v\f\r ";
    const int start = str.find_first_not_of(whitespace);
    const int end = str.find_last_not_of(whitespace);
    const int len = end - start + 1;

    if (start == -1 || end == -1)
        return "";

    return str.substr(start, len);
}

static void GetInput(string *field, const string prompt) {
    while (field->empty()) {
        cout << prompt << ": ";
        getline(cin, *field);

        if (cin.eof())
            break;

        *field = TrimWhitespace(*field);
    }
}

Contact::Contact(void) : first_name_(""), last_name_(""), nickname_(""), \
        phone_number_(""), darkest_secret_("") {}

string Contact::get_first_name(void) const {
    return first_name_;
}

string Contact::get_last_name(void) const {
    return last_name_;
}

string Contact::get_nickname(void) const {
    return nickname_;
}

string Contact::get_phone_number(void) const {
    return phone_number_;
}

string Contact::get_darkest_secret(void) const {
    return darkest_secret_;
}

string Contact::get_first_name_summary(void) const {
    if (first_name_.length() > 10)
        return (first_name_.substr(0, 9) + ".");

    return first_name_;
}

string Contact::get_last_name_summary(void) const {
    if (last_name_.length() > 10)
        return (last_name_.substr(0, 9) + ".");

    return last_name_;
}

string Contact::get_nickname_summary(void) const {
    if (nickname_.length() > 10)
        return (nickname_.substr(0, 9) + ".");

    return nickname_;
}

void Contact::UpdateContact(void) {
    first_name_ = "";
    GetInput(&first_name_, "First Name");
    last_name_ = "";
    GetInput(&last_name_, "Last Name");
    nickname_ = "";
    GetInput(&nickname_, "Nickname");
    phone_number_ = "";
    GetInput(&phone_number_, "Phone Number");
    darkest_secret_ = "";
    GetInput(&darkest_secret_, "Darkest Secret");
}
