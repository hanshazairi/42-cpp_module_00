/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:52:52 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/01 16:29:24 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Contact.hpp"

using std::cin;
using std::cout;
using std::string;

static string   TrimWhitespace(const string str) {
    const string    whitespace = "\t\n\v\f\r ";
    const int       start = str.find_first_not_of(whitespace);
    const int       end = str.find_last_not_of(whitespace);
    const int       len = end - start + 1;

    if (start == -1 || end == -1)
        return ("");

    return (str.substr(start, len));
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

void    Contact::RemoveContact(void) {
    firstName_ = "";
    lastName_ = "";
    nickname_ = "";
    phoneNumber_ = "";
    darkestSecret_ = "";
}

void    Contact::CreateContact(void) {
    GetInput(&firstName_, "First Name");
    GetInput(&lastName_, "Last Name");
    GetInput(&nickname_, "Nickname");
    GetInput(&phoneNumber_, "Phone Number");
    GetInput(&darkestSecret_, "Darkest Secret");
}

string  Contact::GetFirstNameSummary(void) {
    if (firstName_.length() > 10)
        return (firstName_.substr(0, 9) + ".");

    return (firstName_);
}

string  Contact::GetLastNameSummary(void) {
    if (lastName_.length() > 10)
        return (lastName_.substr(0, 9) + ".");

    return (lastName_);
}

string  Contact::GetNicknameSummary(void) {
    if (nickname_.length() > 10)
        return (nickname_.substr(0, 9) + ".");

    return (nickname_);
}

string  Contact::GetFirstName(void) {
    return (firstName_);
}

string  Contact::GetLastName(void) {
    return (lastName_);
}

string  Contact::GetNickname(void) {
    return (nickname_);
}

string  Contact::GetPhoneNumber(void) {
    return (phoneNumber_);
}

string  Contact::GetDarkestSecret(void) {
    return (darkestSecret_);
}
