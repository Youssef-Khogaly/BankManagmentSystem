#ifndef _DATA_H_
#define _DATA_H_
/****includes**********/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
/********Macro Declariation ***********/

/********* Macro Functions *******/

/* User Data Types*/
typedef struct data
{
    char ClientName[60];
    uint64_t id;
    uint64_t Cash;
    char AccountType[12];
    struct data *next;
} data_t;
typedef struct list
{
    data_t *head;
    data_t *tail;
} list_t;
typedef enum
{
    E_OK,
    E_NOT,
    E_NULL,
} StdReturn_t;
/********Functions Prototypes**************/

StdReturn_t data_init(list_t **data);
StdReturn_t data_add_new_customer(list_t **list);
StdReturn_t data_remove_customer(list_t **list, uint64_t id);
StdReturn_t data_edit_customer(list_t **list, uint64_t client_id);
StdReturn_t data_check_customer(list_t **list, uint64_t id);
StdReturn_t Cash_Transfer(uint64_t dest_id , uint64_t source_id , uint64_t cash, list_t **list);

#endif