#ifndef _MAIN_H_
#define _MAIN_H_
/****includes**********/

#include "data.h"
/********Macro Declariation ***********/

/********* Macro Functions *******/

/********Functions Prototypes*/
void main_screen(void)
{
    printf("\n\n\t\t Bank Managment System \t\t\n\n");
    printf("Options: \n");
    printf("1- Create a new Account\n");
    printf("2-Remove a client Account\n");
    printf("3-Edit client Account\n");
    printf("4-Check Client Account\n");
    printf("5-Cash Transfer from Account to another\n");
    printf("0-Exit\n");
    printf("Please Enter Option Number: ");
}
#endif