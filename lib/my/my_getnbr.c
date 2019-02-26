/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int n = 0;
    int neg = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg++;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            n = (n + str[i] - '0') * 10;
            i++;
        }
        else
            break;
    }
    if (neg % 2 == 0)
        return ((-1 * n) / 10);
    else
        return (n / 10);
}
