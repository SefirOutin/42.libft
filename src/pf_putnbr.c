/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:22:35 by soutin            #+#    #+#             */
/*   Updated: 2023/05/21 21:35:36 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

void	pf_putnbr(int nb, size_t *len)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		*len += pf_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		pf_putnbr(n / 10, len);
	}
	*len += pf_putchar(n % 10 + 48);
}
