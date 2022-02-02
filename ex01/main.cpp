/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 21:10:01 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/02 13:04:15 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "PhoneBook.hpp"

using std::cin;
using std::cout;
using std::getline;
using std::string;

int main(void) {
    string cmd;
    PhoneBook phonebook;

    while (1) {
        cout << "[ADD, SEARCH, EXIT]: ";
        getline(cin, cmd);

        if (cin.eof() || cmd == "EXIT")
            break;

        if (cmd.empty() || (cmd != "ADD" && cmd != "SEARCH"))
            continue;

        if (cmd == "ADD")
            phonebook.AddContact();
        else if (cmd == "SEARCH")
            phonebook.SearchContact();
    }

    return 0;
}
