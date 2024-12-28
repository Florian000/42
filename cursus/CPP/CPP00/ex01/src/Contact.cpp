/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:32:28 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/15 13:52:22 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

Contact::Contact(void)
{
    return;
};
Contact::~Contact(void)
 {
    return;
 };

Contact::Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string darkestsecrets) :
    fisrtname(firstname), lastname(lastname), nickname(nickname), phonenumber(phonenumber), darkestsecrets(darkestsecrets) {};

void Contact::display_contact(void)
{    
    display_line("CONTACT INFORMATION", HEADER);
    display_line("First name : "+ this->fisrtname, RIGHT);
    display_line("Last name : "+ this->lastname, RIGHT);
    display_line("Nickname : "+ this->nickname, RIGHT);
    display_line("Phone number : "+ this->phonenumber, RIGHT);
    display_line("Darkest secret : " + this->darkestsecrets, RIGHT);
    display_line(" ", SEP);
    display_line(" ", RIGHT);
    display_line("PRESS ENTER TO GO BACK", CENTER);
    std::cin.ignore();
}

std::string Contact::get_firstname(void)
{
    return(this->fisrtname);
};

std::string Contact::get_lastname(void)
{
    return(this->lastname);
};

std::string Contact::get_nickname(void)
{
    return(this->nickname);
};

std::string Contact::truncate_width(std::string str)
{
    if (str.length() > 10)
    {
        str.resize(9);
        str.append(".");
    }
    return (str);
}