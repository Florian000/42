/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:45:58 by fgranger          #+#    #+#             */
/*   Updated: 2024/08/15 16:26:34 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Objectif : write a programm that should convert lowercase of str passed as argument to uppercase
Error management : if no input is passed write "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
Description :
- Create an empty string 
- iterate through each args with for loop without the index 0 (file name)
- iterate through the content of each arg with the j index until end of stirng ('\0') and append the char converted to uppercase to the created string
- if there was only one arg (the programm didnt go to the for loop) then wirte the error message with a end of line
- else print the str created with all the values converted to uppercase with end of line
*/

#include <iostream>

int main(int argc, char **argv)
{
	int j;
	std::string str;
	
	for(int i = 1; i < argc; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			str += toupper(argv[i][j]);
			j++;
		}
	}
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		std::cout << str << std::endl;
	return (0);
}