/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:32:33 by fgranger          #+#    #+#             */
/*   Updated: 2024/08/15 16:32:35 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Header file of contact class : 
contact class contains private variables
public destructor and constructor
contact creator with parameters to set the private variales
a display contact function that will display all info about a contact
getter for each variable that will be called elsewhere
a static function (usable elsewhere without being instanciated) that truncate the witdh of each element to 10 char ending by .
*/

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
    private:

        std::string fisrtname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        std::string darkestsecrets;

    public:

        Contact(void);
        ~Contact(void);
        
        Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string darkestsecret);
        void display_contact(void);
        std::string get_firstname(void);
        std::string get_lastname(void);
        std::string get_nickname(void);
        static std::string truncate_width(std::string str);

};