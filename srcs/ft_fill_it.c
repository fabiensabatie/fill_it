/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:02:07 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/11 13:02:09 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_it.h"
#include "libft.h"

int main(int argc, char const *argv[])
{
	if (!ft_allisgood(argc, argv))
		return (0);
	else
		ft_putstr("You good to go ! :D\n");
}
