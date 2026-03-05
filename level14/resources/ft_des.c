#include<string.h>
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>

void    even_transformation(char* str, int str_index, int iterations){
    for (size_t j = 0; j < iterations; j++)
    {
        str[str_index] = str[str_index] - 1;
        if (str[str_index] == 0x1f)
            str[str_index] = '~';
    }
}

void    odd_transformation(char* str, int str_index, int iterations){
    for (size_t j = 0; j < iterations; j++)
    {
        str[str_index] = str[str_index] + 1;
        if (str[str_index] == 0x7f)
            str[str_index] = ' ';
    }
}

char    *ft_des(const char *encoded) {
    size_t  len;
    char    *decrypted;
    char    pattern_keys[7] = {'0','1','2','3','4','5','6'};
    int     pattern_index;
    int     iterations;

    if (!encoded)
        return NULL;
    decrypted = strdup(encoded);
    if (!decrypted)
        return NULL;
    len = strlen(encoded);
    if (len <= 0 )
        return NULL;
    pattern_index = 0;
    for (size_t i = 0; i < len; i++)
    {
        iterations = pattern_keys[pattern_index];
        if (i % 2 == 0)
            even_transformation(decrypted, i, iterations);
        else
            odd_transformation(decrypted, i, iterations);
        pattern_index++;
        if (pattern_index == 6)
            pattern_index = 0;
    }
    return decrypted;
}

int main(void)
{
    const char *tokens[] = {
        "I`fA>_88eEd:=`85h0D8HE>,D",
        "7`4Ci4=^d=J,?>i;6,7d416,7",
        "<>B16\\AD<C6,G_<1>^7ci>l4B",
        "B8b:6,3fj7:,;bh>D@>8i:6@D",
        "?4d@:,C>8C60G>8:h:Gb4?l,A",
        "G8H.6,=4k5J0<cd/D@>>B:>:4",
        "H8B8h_20B4J43><8>\\ED<;j@3",
        "78H:J4<4<9i_I4k0J^5>B1j`9",
        "bci`mC{)jxkn<\"uD~6%g7FK`7",
        "Dc6m~;}f8Cj#xFkel;#&ycfbK",
        "74H9D^3ed7k05445J0E4e;Da4",
        "70hCi,E44Df[A4B/J@3f<=:`D",
        "8_Dw\"4#?+3i]q&;p6 gtw88EC",
        "boe]!ai0FB@.:|L6l@A?>qJ}I",
        "g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|"
    };

    for (int i = 0; i < 15; i++)
    {
        char *transformed = ft_des(tokens[i]);
        printf("Encrypted token%02d : %s | Actual token%02d : %s\n", i, tokens[i], i, transformed);
        free(transformed);
    }
    return 0;
}