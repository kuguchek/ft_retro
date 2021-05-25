/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:24:29 by asirenko          #+#    #+#             */
/*   Updated: 2019/12/08 22:31:52 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR_HPP
# define STAR_HPP

# include "Enemy.hpp"
# include "Game.hpp"
#include "Elements.hpp"

class Star : public Elements
{
	public:
		Star(void);
		~Star(void);
		Star(Star const &src);

		Star	&operator=(Star const &src);
		
		void	print(void) const;
		void	move(void);
};

#endif
