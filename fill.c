#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "gnl/get_next_line.h"

int main()
{
	char	*str;
	int 	fd;
	int		i;
	int 	flag;
	char 	*at;
	int 	k;

	k = -1;
	i = -1;
	flag = -1;
	at = (char *)malloc(sizeof(at) * 20);
	fd = open("output.txt", O_CREAT | O_RDWR);
	while(get_next_line(0, &str) && flag != 0)
	{
		flag--;
		ft_putstr_fd(str, fd);
		ft_putchar_fd2('\n', fd);
		if (ft_strstr(str, "Piece") && flag < 0)
		{
			while (str[++i])
				while (str[i] > 47 && str[i] < 58)
					at[++k] = str[i++];
			flag = ft_atoi(at);
			ft_printf("%i", flag);
		}
	}
	ft_printf("7 2");
	return (0);
}