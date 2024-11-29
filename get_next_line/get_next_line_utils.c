/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:01:05 by lnierobi          #+#    #+#             */
/*   Updated: 2024/11/29 16:53:00 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
//it counts the sting length
// size_t	ft_strlen(const char *s)
// {
// 	size_t	length;

// 	length = 0;
// 	while (s[length] != '\0')
// 		length++;
// 	return (length);
// }

//search for a specific signed in a string and give its out if it is in the
// string when its not it returns NULL;
// char	*ft_strchr(const char *s, int c)
// {
// 	unsigned char	cc;
// 	int				i;

// 	i = 0;
// 	cc = (unsigned char)c;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == cc)
// 		{
// 			return ((char *)&s[i]);
// 		}
// 		i++;
// 	}
// 	if (cc == '\0')
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

//join to strings toghether to a new string
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*output;
// 	int		a;
// 	int		b;

// 	a = 0;
// 	b = 0;
// 	output = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (!output)
// 		return (NULL);
// 	while (s1[a])
// 		output[b++] = s1[a++];
// 	a = 0;
// 	while (s2[a])
// 		output[b++] = s2[a++];
// 	output[b] = '\0';
// 	return (output);
// }

//duplicate a string
// char	*ft_strdup(const char *s1)
// {
// 	char	*new;
// 	int		i;

// 	i = 0;
// 	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
// 	if (!new)
// 		return (NULL);
// 	while (*s1)
// 		new[i++] = *s1++;
// 	new[i] = '\0';
// 	return (new);
// }

//it set a string to a specific outcom
// void	*ft_memset(void *b, int c, size_t len)
// {
// 	unsigned char	*ptr;
// 	size_t			i;

// 	ptr = (unsigned char *)b;
// 	i = 0;
// 	while (i < len)
// 	{
// 		ptr[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return (b);
// }
