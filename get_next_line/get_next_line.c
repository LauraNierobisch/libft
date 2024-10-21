/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:01:14 by lnierobi          #+#    #+#             */
/*   Updated: 2024/10/21 11:01:57 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// make a new string out of the old string from starting point to the leng point
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len >= s_len - start)
		len = s_len - start;
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (!output)
		return (0);
	i = 0;
	while (i < len && (s + start)[i] != '\0')
	{
		output[i] = (s + start)[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

// memsetset fills the empty strings with 0's.
// if workstring is empthy it gives only the 0 out
// if workstring is filled and no \n it reads into the buffer
// and string join the already existing workstring with the new readed buffer
// and becomes the new working string
char	*create_workstring(int fd, char **workstring, int *bytecount,
		char *buffer)
{
	char	*temp;

	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	if (*workstring == NULL)
	{
		*workstring = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (*workstring == NULL)
			return (NULL);
		ft_memset(*workstring, 0, BUFFER_SIZE + 1);
	}
	while (*bytecount > 0 && !ft_strchr(buffer, '\n'))
	{
		*bytecount = read(fd, buffer, BUFFER_SIZE);
		if (*bytecount == -1)
			return (free(*workstring), *workstring = NULL, NULL);
		if (*bytecount == 0)
			return (NULL);
		buffer[*bytecount] = '\0';
		temp = ft_strjoin(*workstring, buffer);
		free(*workstring);
		*workstring = temp;
	}
	return (*workstring);
}

// the function count to the point where the \n is and put the a new sting out
// what only containes the part befor the new line.
char	*extract_line_befor_newline(char *workstring)
{
	char	*extracted_line;
	int		count;
	int		i;

	count = 0;
	while (workstring[count] != '\0' && workstring[count] != '\n')
	{
		count++;
	}
	count++;
	extracted_line = (char *)malloc((count + 1) * sizeof(char));
	if (!extracted_line)
	{
		return (NULL);
	}
	i = 0;
	while (i < (count + 1) - 1 && workstring[i] != '\0')
	{
		extracted_line[i] = workstring[i];
		i++;
	}
	extracted_line[i] = '\0';
	return (extracted_line);
}

// it count to the point where the new line is and count till the end of
// the working string. It delets everthing what is befor the newline and
// keeps everything what is after the new line and give it out as the new
// workstring. so the oposit from extract line
char	*line_delete_newline_keep(char *workstring)
{
	int		count;
	int		length;
	char	*cutted_string;

	count = 0;
	length = 0;
	while (workstring[count] != '\0' && workstring[count] != '\n')
		count++;
	if (workstring[count] == '\n')
		count++;
	while (workstring[count + length] != '\0')
		length++;
	cutted_string = ft_substr(workstring, count, length);
	free(workstring);
	return (cutted_string);
}

// it error checks first
// while the workstring is empthy it stringdup an emphty string
// when it findes a new line with strchr it returns the line and
// keeps the rest of the buffer in the workstring
// if the is no new line it creates a new worksting
// if the worksting is == \0 or ==NULL it retruns
// the worksting and free the memory
// else it just extracts the line and return it and keep the rest of the string
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*workstring = NULL;
	char		*line;
	int			bytecount;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!workstring)
		workstring = ft_strdup("");
	if (ft_strchr(workstring, '\n'))
	{
		line = extract_line_befor_newline(workstring);
		workstring = line_delete_newline_keep(workstring);
		return (line);
	}
	bytecount = 1;
	create_workstring(fd, &workstring, &bytecount, buffer);
	if (workstring == NULL || *workstring == '\0')
	{
		free(workstring);
		return (workstring = NULL, NULL);
	}
	line = extract_line_befor_newline(workstring);
	workstring = line_delete_newline_keep(workstring);
	return (line);
}
