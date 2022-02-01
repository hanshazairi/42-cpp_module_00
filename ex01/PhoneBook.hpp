/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:57:32 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/01 14:25:08 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_PHONEBOOK_HPP_
#define EX01_PHONEBOOK_HPP_

#include "Contact.hpp"

class   PhoneBook {
 private:
    int     entries_;
    Contact contacts_[8];

 public:
    PhoneBook(void);

    void    AddContact(void);
    void    SearchContact(void);
};

#endif  // EX01_PHONEBOOK_HPP_
