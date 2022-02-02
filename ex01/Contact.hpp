/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:02:34 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/02 12:59:39 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_CONTACT_HPP_
#define EX01_CONTACT_HPP_

#include <string>

using std::string;

class Contact {
 public:
    Contact(void);

    string get_first_name(void) const;
    string get_last_name(void) const;
    string get_nickname(void) const;
    string get_phone_number(void) const;
    string get_darkest_secret(void) const;
    string get_first_name_summary(void) const;
    string get_last_name_summary(void) const;
    string get_nickname_summary(void) const;
    void UpdateContact(void);

 private:
    string first_name_;
    string last_name_;
    string nickname_;
    string phone_number_;
    string darkest_secret_;
};

#endif  // EX01_CONTACT_HPP_
