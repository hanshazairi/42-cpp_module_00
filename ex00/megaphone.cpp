/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 23:48:47 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/01 17:05:11 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv) {
    if (argc == 1) {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } else {
        for (int i = 1; i < argc; i++)
            for (int j = 0; argv[i][j]; j++)
                cout << static_cast<char>(toupper(argv[i][j]));
    }
    cout << endl;
    return (0);
}
