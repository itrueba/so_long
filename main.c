#include "s_long.h"

void	ft_error(char *text, t_map *map)
{
	printf("%s\n", text);
	free(map);
	exit(0);
}

int	ft_error_name(char *map_name)
{
	char	*ber1;
	char	*ber2;

	ber1 = ".ber";
	ber2 = ft_strrchr(map_name, '.');
	if (ft_strlen(map_name) > 4 && ber2)
	{
		while (*ber2)
		{
			if (*ber1 != *ber2)
				return (1);
			ber1++;
			ber2++;
		}
		return (0);
	}
	return (1);
}


int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_error_name(argv[1]))
			exit(0);
		ft_check_map(argv[1]);
	}
	return (0);
}