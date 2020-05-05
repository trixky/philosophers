#include "philosopher.h"

int		ft_parser(t_all *all, int argc, char **argv)
{
	all->arg_must_eat = ERROR;
	if ((all->arg_nbr_philosopher = ft_atoi(argv[1])) == ERROR ||
			(all->arg_time_to_die = ft_atoi(argv[2])) == ERROR ||
			(all->arg_time_to_eat = ft_atoi(argv[3])) == ERROR ||
			(all->arg_time_to_sleep = ft_atoi(argv[4])) == ERROR ||
			(argc == 6 &&
			(all->arg_must_eat = ft_atoi(argv[5])) == ERROR))
		return (TRUE);
	if (all->arg_nbr_philosopher == 0 ||
			all->arg_time_to_die == 0 ||
			all->arg_time_to_eat == 0 ||
			all->arg_time_to_sleep == 0 ||
			all->arg_must_eat == 0)
		return (TRUE);
	all->arg_time_to_eat *= 1000;
	all->arg_time_to_sleep *= 1000;
	return (FALSE);
}
