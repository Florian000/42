/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:32:49 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/15 13:52:43 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Header file of phonebook class :

contains two privates variable an index and an array of Contact elements and the private funciton homesearch
which is the home page display for SEARCH page (prints the header and the table of contacts) this is a utils only used for the public search function
contacts array depends on the define contact limit which is set to 8 according to the subject
constructor initiate index to 0
add enable to create an element of the array (used with Contact creator parametized) :
    - Display a new "page" and invite the user to input each field
    - Add the new contact only if no field is empty

search : enable to visualize all contact created and to drill down to a specific contact using index
    - display a new page with the table (formatted like asked in the subject)
    - take index as input and then display a contact page informtion (display contact function of contact class)
*/

#pragma once
# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"
# include "Display.hpp"
# define CONTACTLIMIT 8

class PhoneBook
{
    private:

        int index;
        Contact contacts[CONTACTLIMIT];
        int homesearch(void);

    public:
    
        PhoneBook(void);
        ~PhoneBook(void);

        void add(void);
        void search(void);
};