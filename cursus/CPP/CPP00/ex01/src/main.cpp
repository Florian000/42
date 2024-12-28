/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:32:39 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/15 13:52:07 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int main(void)
{
    std::string command;
    PhoneBook phonebook;

    app_start();
    while (1)
    {
        display_line("Enter a command : ", INPUT);
        std::getline(std::cin, command);
        display_line("", SEP);
        if (command == "ADD")
        {
            phonebook.add();
        }
        else if (command == "SEARCH")
        {
            phonebook.search();
        }
        else if (command == "EXIT")
            break;
        else
        {
            app_start();
            display_line("Invalid command, please try again", ERROR);
            continue;
        }
        app_start();
    }
}