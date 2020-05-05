#include "philosopher.h"

int		main(int argc, char **argv)
{
	t_all	all;

	if (argc < 5 || argc > 6 || ft_parser(&all, argc, argv) == TRUE)
		return (ft_error("error : arguments invalides\n", 1));
	if (ft_init_null(&all) == TRUE ||
			ft_init_speak(&all) == TRUE ||
			ft_init_fork(&all) == TRUE ||
			ft_init_philosopher(&all) == TRUE)
		return (ft_error("error : erreur lors de l'initialisation ...\n", 1));
	ft_init_start(&all);
	ft_init_thread(&all);
	usleep(WAIT_WHL);
	while (1)
	{
		usleep(WAIT_CPU);
		if (ft_someone_is_dead(&all) == TRUE ||
				ft_everyone_is_satisfied(&all) == TRUE)
			return (ft_free(&all, 0));
	}
	return (0);
}
