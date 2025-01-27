/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:30:35 by fgranger          #+#    #+#             */
/*   Updated: 2024/08/15 16:30:37 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"

PhoneBook::PhoneBook(void)
{
    this->index = 0;
    return;
};

PhoneBook::~PhoneBook(void)
{
    return;
};

void PhoneBook::add(void)
{
    std::cout << CLEAR;
    std::string firstname, lastname, nickname, phonenumber, darkestsecret;
    display_line("ADD CONTACT", HEADER);
    display_line("Enter First Name     : ", INPUT);
    std::getline(std::cin, firstname);
    display_line("Enter Last Name      : " , INPUT);
    std::getline(std::cin, lastname);
    display_line("Enter Nickname       : " , INPUT);
    std::getline(std::cin, nickname);
    display_line("Enter Phone Number   : " , INPUT);
    std::getline(std::cin, phonenumber);
    display_line("Enter Darkest Secret : " , INPUT);
    std::getline(std::cin, darkestsecret);

    if (firstname.empty() || lastname.empty() || nickname.empty() || phonenumber.empty() || darkestsecret.empty())
    {
        display_line("Contact not added, there are some fields missings", HEADER);
        display_line("PRESS ENTER TO GO BACK", CENTER);
        std::cin.ignore();
        return ;
    }
    this->contacts[this->index++ % CONTACTLIMIT] = Contact(firstname, lastname, nickname, phonenumber, darkestsecret);
    display_line("Contact added successfully", HEADER);
    display_line("PRESS ENTER TO GO BACK", CENTER);
    std::cin.ignore();
    display_line("", SEP);
};

int PhoneBook::homesearch(void)
{
    display_line("SEARCH CONTACT", HEADER);
    if (this->index == 0)
    {
        display_line("No contact stored in the phonebook yet", RIGHT);
        display_line("PRESS ENTER TO GO BACK", CENTER);
        return (1);
    }
    for (int i = 0; i < this->index && i < CONTACTLIMIT; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << Contact::truncate_width(this->contacts[i].get_firstname()) << "|";
        std::cout << std::setw(10) << Contact::truncate_width(this->contacts[i].get_lastname()) << "|";
        std::cout << std::setw(10) << Contact::truncate_width(this->contacts[i].get_nickname()) << "|" << std::endl;
    }
    return (0);
}

void PhoneBook::search(void)
{
    std::string input_index;

    if (this->homesearch())
    {
        std::cin.ignore();
        return ;
    }
    while (1)
    {
        display_line("Enter an index to get information about a contact", RIGHT);
        display_line("or press enter to go back", RIGHT);
        display_line("index : ", INPUT);
        std::getline(std::cin, input_index);

        if (input_index.empty())
            return ;
        else if (input_index.length() != 1 || input_index[0] < '0' || input_index[0] > '7' || input_index[0] - '0' >= this->index)
        {
            this->homesearch();
            display_line("Invalid index, please try again", ERROR);
        }
        else
        {
            this->contacts[input_index[0] - '0'].display_contact();
            this->homesearch();
        }
    }
};