int ft_print_char(const char *str)
{
    int i;

    while(str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    return (0);
}