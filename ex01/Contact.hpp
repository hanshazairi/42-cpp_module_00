/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:02:34 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/01 16:48:55 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_CONTACT_HPP_
#define EX01_CONTACT_HPP_

#include <string>

using std::string;

class   Contact {
 private:
    string  firstName_;
    string  lastName_;
    string  nickname_;
    string  phoneNumber_;
    string  darkestSecret_;

 public:
    void    RemoveContact(void);
    void    CreateContact(void);
    string  GetFirstNameSummary(void);
    string  GetLastNameSummary(void);
    string  GetNicknameSummary(void);
    string  GetFirstName(void);
    string  GetLastName(void);
    string  GetNickname(void);
    string  GetPhoneNumber(void);
    string  GetDarkestSecret(void);
};

#endif  // EX01_CONTACT_HPP_
