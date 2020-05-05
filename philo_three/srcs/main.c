#include "philosopher.h"

int main(int argc, char **argv)
{
	t_all all;

	ft_init_null(&all);
	if (argc < 5 || argc > 6 || ft_parser(&all, argc, argv) == TRUE)
		return (ft_error("error : arguments invalides\n", 1));
	ft_unlink();
	if (ft_init_sem_start(&all) == TRUE ||
		ft_init_sem_fork(&all) == TRUE ||
		ft_init_sem_speak(&all) == TRUE ||
		ft_init_sem_end(&all) == TRUE ||
		ft_init_eating_status(&all) == TRUE ||
		ft_init_philosopher(&all) == TRUE)
	{
		return (ft_error("error : erreur lors de l'initialisation ...\n", 0) +
				ft_free(&all, 1));
	}
	sem_wait(all.sem_start);
	sem_wait(all.sem_end);
	ft_init_start(&all);
	ft_init_synchronisation_start(&all);
	ft_init_processus(&all);
	sem_wait(all.sem_end);
	ft_kill_everyone(&all);
	return (ft_free(&all, 1));
}
