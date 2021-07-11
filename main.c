#include "get_next_line.h"

int	main(void)
{
	char	*line;

	line = 0;
	while ((line = get_next_line(0)) != NULL)
	{
		write(1, line, ft_strlen(line));
		free(line);
		line = 0;
	}
	return (0);
}

