/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutin <soutin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:17:11 by soutin            #+#    #+#             */
/*   Updated: 2023/05/22 13:34:59 by soutin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

static void	pf_putnbr_base(unsigned long nb, char *base, size_t *len)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nb >= base_len)
	{
		pf_putnbr_base(nb / base_len, base, len);
	}
	*len += pf_putchar(base[nb % base_len]);
}

void	pf_convert_base(unsigned long nb, char index, size_t *len)
{
	char	*base[3];

	base[0] = "0123456789";
	base[1] = "0123456789abcdef";
	base[2] = "0123456789ABCDEF";
	if (index == 'u')
		pf_putnbr_base(nb, base[0], len);
	else if (index == 'x')
		pf_putnbr_base(nb, base[1], len);
	else if (index == 'X')
		pf_putnbr_base(nb, base[2], len);
	else if (index == 'p')
	{
		if (!nb)
		{
			*len += write(1, "(nil)", 5);
			return ;
		}
		*len += write(1, "0x", 2);
		pf_putnbr_base(nb, base[1], len);
	}
}

// int	main(void)
// {
// 	pf_convert_base(45, "0123456789ABCDEF");
// }
