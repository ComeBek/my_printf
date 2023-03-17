/**
***
**/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdarg.h>
#include<stdlib.h>
#include<sys/cdefs.h>

/*
************************************************************
*/
void function_putchar(char a)
{
    write(1, &a, 1);
}
/*
************************************************************
*/
int function_putstr(char* rts)
{
    int i = 0;

    while(*rts != '\0')
    {
        function_putchar(*rts);
        rts++;
        i++;
    }

    return i;
}
/*
************************************************************
*/
char* integer_for_char(int param_1, int param_2)
{
    
    char* rainbow;
    char* skit;
    int a[100000];
    int  c, x, respawn;
    c = x = 0;
    if(param_1 < 0)
    {
        param_1 = param_1 * -1;
        x++;
    }
    for(c = 0; param_1 > 0; c++){
        a[c] = param_1 % (5 * 2);
        param_1 /= (20 / 2);
    }

    skit = malloc(c);
    rainbow = malloc(c + 1);
    respawn = 0;

    for(int n = c - 1;n >= 0; n--)
    {
        skit[respawn] = a[n] +'0';
        respawn++;
    }
    if(x > 0)
    {
        if(param_2 == 0)
        {
            rainbow[0] = 45;
            for(int i = 0; i < (int)strlen(skit); i++)
            {
                rainbow[i + 1] = skit[i];
            }
            return rainbow;
        }else{
            return skit;
        }

    }
    return skit;

}
/*
************************************************************
*/
char* show_path(int lon, unsigned long shor)
{
    unsigned long digit, num_copy;
    int rate_cm_exit = 0;
    num_copy = shor;
    char* cm_exit;
    
    while (shor != 0)
    {
        shor /= lon;
        rate_cm_exit++;
    }
    
    cm_exit = (char*)malloc(sizeof(char) *  rate_cm_exit);
    *cm_exit = '\0';
    char temp[16] = "0123456789abcdef";
    
    while (num_copy != 0)
    {
        digit = num_copy % lon;
        rate_cm_exit--;
        if(rate_cm_exit > 0){
            cm_exit[rate_cm_exit] = temp[digit];
        }else if(rate_cm_exit == 0){
            cm_exit[rate_cm_exit] = temp[digit];
        }
        
        num_copy = num_copy / lon;
    }
     
    // free(cm_exit);
    return cm_exit;
}
/*
************************************************************
*/
char* post(int param_1)
{
    char post1[100000];
    int ab, ac;
    ab = ac = 0;
    char* sos = (char*)malloc(sizeof(char) * 1000);

    ///--------///
    
    for(ab = 0; param_1 != 0; ab++)
    {
        post1[ab++] = param_1 % 8;
        param_1 /= 8; 
    }
    for(int i = ab - 1; i >= 0; i--)
    {
        sos[ac] = post1[i] + '0';
        ac++;
    }
    return sos;
}
/*
************************************************************
*/
char* goddammit(int param_1)
{
    char a_table[128];
    int xy, webstruct, qwer;
    xy = qwer = 0;
    char* sunshine = (char*)malloc(sizeof(char) * xy);

    ///--------///

    while(param_1 != 0)
    {
        webstruct = param_1 % (2 * 8);
            if(param_1 < 10)
            {
                a_table[xy++] = webstruct + 48;
            }
            else
            {
                a_table[xy++] = webstruct + 55;
            }
            param_1 /= (32 / 2); 
    }
    for(int i = xy - 1; i >= 0; i--)
    {
        sunshine[qwer] = a_table[i];
        qwer++;
    }
    return sunshine;
}
/*
************************************************************
*/
int my_printf(char* string, ...)
{
    va_list shot;
    va_start(shot, string);
    int gen, s_gen;
    unsigned long pool;
    char sort;
    char* right = (char*)malloc(14 * sizeof(char));
    char *n = "(null)";
    gen = 0;

    ///--------///

    for(int i = 0; i < (int)strlen(string); i++)
    {
        if(string[i] == '%')
        {
            i++;
            switch (string[i])
            {
                case 'd':
                s_gen = va_arg(shot, int);
                if(s_gen == 0){
                    char under = s_gen + '0';
                    function_putchar(under);
                    gen++;
                }else{
                function_putstr(integer_for_char(s_gen, 0));
                gen += strlen(integer_for_char(s_gen, 0));
                }
                break;
                case 's':
                right = va_arg(shot, char*);
                if(right == NULL){
                    gen += function_putstr(n);
                }else{
                    gen += function_putstr(right);
                }
                break;

                case 'c':
                sort = (char)va_arg(shot, int);                
                function_putchar(sort);
                gen++;
                break;

                case 'o':
                s_gen = va_arg(shot, int);
                char clan[100000];
                int j;
                j = 0;
                while(s_gen != 0)
                {
                    clan[j++] = s_gen % 8 + '0';
                    s_gen /= (4 * 2);
                    gen++;
                }
                for(int i = strlen(clan) - 1; i >= 0; i--)
                {
                    function_putchar(clan[i]);
                }
                break;
                case 'p':
                pool = (unsigned long)va_arg(shot, void*);
                function_putchar('0');
                function_putchar('x');
                gen = gen + 2;
                right = show_path(16, pool);
                
                function_putstr(right);
                while(*right != '\0')
                {
                    gen++;
                    right++;
                }
                break;

                case 'x':
                s_gen = va_arg(shot, int);
                int dom, tom;
                tom = 0;
                char flash[1000];
                while(s_gen != 0){
                    gen++;
                    dom = s_gen % (2 * 8);
                    if(dom < 10){
                        flash[tom++] = dom + 48;
                    }else{
                        flash[tom++] = dom + 55;
                    }
                        s_gen = s_gen / 16;
                }
                function_putstr(flash);
                break;
            }
        }
        else
        {
            function_putchar(string[i]);
            gen++;
        }
    }
    return gen;
}

//  int main(){
//  int rest = 0;
//   int a = 10;
//  int* pA = &a;
  //my_printf("hello\n");
 // my_printf("%c!\n", 'H');

//  my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o');
//  my_printf("Hello %s!\n", "QWASAR.IO");
//  my_printf("Hello %s %s!\n", "Mr", "Gaetan");
//  my_printf("NULL STRING %s!\n", (char*)NULL);
//  my_printf("%d!\n", 1337);
//  my_printf("%x!\n", 14);
//  my_printf("%d - %d - %d!\n", 2048, 0, -1337);
//  my_printf("%o!\n", 100);
// my_printf("%p", pA);
//printf("%p", pA);



//  return rest;    
//  }