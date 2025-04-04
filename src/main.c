#include "parsing.h"

int main(int ac, char **av)
{
    int fd; 
    char *map; 

    if(check_args(ac, av))
        return(1); 
    fd = open(av[1], O_RDONLY);
    if(fd == -1)
    {
        printf("couldnt open file\n"); 
        return(1); 
    }
    map = get_map(fd);
    if(!map)
    {
        printf("couldnt get map\n"); 
        return(1); 
    }
    close(fd); 
    if(!valid_map(map))
    {
        return(1); 
    }
    return(0); 
}
