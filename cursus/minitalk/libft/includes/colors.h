/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <florian.granger@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:00:40 by fgranger          #+#    #+#             */
/*   Updated: 2023/02/05 15:43:18 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

// stdout coloring functions

void	stdout_red(void);
void	stdout_yellow(void);
void	stdout_green(void);
void	stdout_blue(void);
void	stdout_reset(void);

// Common HTML color codes 

# define WHITE      0x0FFFFFF // rgb(255, 255, 255)
# define SILVER     0x0C0C0C0 // rgb(192, 192, 192)
# define GRAY       0x0808080 // rgb(128, 128, 128)
# define BLACK      0x0000000 // rgb(0, 0, 0)
# define RED        0x0FF0000 // rgb(255, 0, 0)
# define MAROON     0x0800000 // rgb(128, 0, 0)
# define YELLOW     0x0FFFF00 // rgb(255, 255, 0)
# define OLIVE      0x0808000 // rgb(128, 128, 0)
# define LIME       0x000FF00 // rgb(0, 255, 0)
# define GREEN      0x0008000 // rgb(0, 128, 0)
# define AQUA       0x000FFFF // rgb(0, 255, 255)
# define TEAL       0x0008080 // rgb(0, 128, 128)
# define BLUE       0x00000FF // rgb(0, 0, 255)
# define NAVY       0x0000080 // rgb(0, 0, 128)
# define FUCHSIA    0x0FF00FF // rgb(255, 0, 255)
# define PURPLE     0x0800080 // rgb(128, 0, 128)

#endif
