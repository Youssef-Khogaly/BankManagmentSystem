#include "data.h"
/*----------Global---Varaibles---------*/
static uint64_t id = 0;
/*--------- helper Functions Prototype--------------*/
static data_t *create_node(void);
static void get_data(data_t **temp);
static void edit_screen(void);
/*-------------------------------------*/
StdReturn_t data_init(list_t **data)
{
    StdReturn_t ret = E_NOT;
    if (NULL == data)
    {
        ret = E_NULL;
    }
    else
    {
        (*data)->head = NULL;
        (*data)->tail = NULL;
        ret = E_OK;
    }
    return ret;
}
StdReturn_t data_add_new_customer(list_t **list)
{
    StdReturn_t ret = E_NOT;
    data_t *head = (*list)->head;
    data_t *tail = (*list)->tail;
    if (NULL == list)
    {
        ret = E_NULL;
    }
    else
    {
        if (head == NULL)
        {
            data_t *temp = create_node();
            if (NULL == temp)
                ret = E_NULL;
            else
            {
                get_data(&(temp));
                (*list)->head = temp;
                (*list)->tail = temp;
                ret = E_OK;
            }
        }
        else
        {
            data_t *temp = create_node();
            if (NULL == temp)
                ret = E_NULL;
            else
            {
                get_data(&(temp));
                (*list)->tail->next = temp;
                (*list)->tail = temp;
                ret = E_OK;
            }
        }
        printf("Account Added Successfully\n");
        printf("Your Account ID : %llu", id);
        getchar();
    }
    return ret;
}

StdReturn_t data_remove_customer(list_t **list, uint64_t id)
{
    StdReturn_t ret = E_NOT;
    data_t *head = (*list)->head;
    data_t *tail = (*list)->tail;
    data_t *temp = head;
    data_t* temp2 = NULL;
    if (NULL == list || NULL == (*list) || NULL == (*list)->head)
    {
        ret = E_NULL;
    }
    else
    {

        if (id == head->id)
        {
            if (head == tail)
            {
                (*list)->head = (*list)->head->next;
                free((*list)->head);
                (*list)->head = NULL;
                (*list)->tail = NULL;
                ret = E_OK;
            }
            else
            {
                temp = head;
                (*list)->head = (*list)->head->next;
                free(temp);
                temp = NULL;
                ret = E_OK;
            }
        }
        else
        {
            while ((NULL != temp) && (NULL != temp->next) && id != temp->next->id)
                temp = temp->next;
            if (NULL == temp->next || id != temp->id)
            {
                printf("Client Not Found !!\n");
                getchar();
                ret = E_OK;
                return ret;
            }
            else
            { /*nothing*/
            }

            if (tail == temp->next)
            {
                free((*list)->tail);
                (*list)->tail = NULL;
                (*list)->tail = temp;
                ret = E_OK;
            }
            else
            {
                temp2 = temp->next;
                temp->next = temp2->next;
                free(temp2);
                temp2 = NULL;
                ret = E_OK;
            }
        }
        if (E_OK == ret)
            printf("Account Removed Successfully!!\n");
            getchar();
            getchar();
    }
    return ret;
}

StdReturn_t data_edit_customer(list_t **list, uint64_t client_id)
{
    StdReturn_t ret = E_NOT;
    uint8_t edit_select = 1;
    data_t *head = (*list)->head;
    data_t *tail = (*list)->tail;
    data_t *temp = head;
    if (NULL == list || NULL == (*list) || NULL == (*list)->head)
    {
        ret = E_NULL;
    }
    else if (client_id > tail->id || client_id < head->id)
    {
        printf("id Not found !!");
        ret = E_NOT;
    }
    else
    {
        if (id == tail->id)
            temp = tail;
        else
        {
            while (NULL != temp && client_id != temp->id)
                temp = temp->next;
            if (NULL == temp)
            {
                printf("Id Not Found !!\n");
                ret = E_NOT;
                getchar();
                return ret;
            }
        }
        ret = E_OK;
        while (edit_select != 0)
        {
            edit_screen();
            scanf("%u", &edit_select);
            switch (edit_select)
            {
            case 1:
                printf("Enter Client Name: ");
                scanf("%60s", ((temp)->ClientName));
                setbuf(stdin, NULL);
                ret |= ret;

                break;
            case 2:
                setbuf(stdin, NULL);
                printf("enter Client Cash: ");
                scanf("%llu", &((temp)->Cash));
                setbuf(stdin, NULL);
                ret |= ret;
                break;
            case 3:
                setbuf(stdin, NULL);
                printf("enter client Account Type: ");
                scanf("%12s", ((temp)->AccountType));
                setbuf(stdin, NULL);
                ret |= ret;
                break;
            case 0:
                ret |= ret;
                break;
            }
        }
    }
    return ret;
}

StdReturn_t data_check_customer(list_t **list, uint64_t id)
{
    StdReturn_t ret = E_NOT;
    data_t *head = (*list)->head;
    data_t *tail = (*list)->tail;
    data_t *temp = NULL;
    if (NULL == list || NULL == (*list) || NULL == (*list)->head)
    {
        printf("Data Base is Empty!!\n");
        ret = E_NULL;
        getchar();
        getchar();
    }
    else
    {
        if (id == head->id)
            temp = head;
        else if (id == tail->id)
            temp = tail;
        else
        {
            temp = head;
            while (NULL != temp && id != temp->id)
                temp = temp->next;
        }
        if (temp == NULL)
        {
            ret = E_NOT;
            return ret;
        }
        fflush(stdin);
        printf("Customer Name: %s", temp->ClientName);
        printf("Customer ID: %u\n", temp->id);
        printf("Account Type: %s", temp->AccountType);
        printf("Account Cash: %llu\n", temp->Cash);
        printf("press any key to return to main screen\n");
        ret = E_OK;
        getchar();
        getchar();
    }
    return ret;
}

StdReturn_t Cash_Transfer(uint64_t dest_id , uint64_t source_id , uint64_t cash, list_t **list)
{
    StdReturn_t ret = E_NOT;
    data_t* head = (*list)->head;
    data_t* tail = (*list)->tail;
    data_t* _dest = NULL;
    data_t* _src = NULL;
    if(NULL == list  ||  NULL == *(list)  || NULL == head)
    {
        printf("ERROR CANT TRANSFER THE CASH!!");
        getchar();
        ret = E_NULL;
    }
    else if (dest_id < head->id || dest_id > tail->id || source_id > tail->id || source_id < head->id)
    {
        printf("Cant Find Account id !!");
        getchar();
        ret = E_NOT;
    }
    else 
    {
        if(dest_id == tail->id)
            _dest = tail;
        else if(source_id == tail->id)
            _src = tail;
        else {/*nothing*/}
        if(NULL == _dest)
        {
            _dest = head;
            while(_dest &&  dest_id !=_dest->id)
                _dest = _dest->next;
            if(NULL == _dest)
            {
                ret = E_NOT;
                printf("ERROR uncorrect account ID\n");
                getchar();
                return ret;
            }
            else {/*nothing*/}
        }
        if(NULL == _src)
        {
            _src = head;
            while(_src && source_id != _src->id)
                _src = _src->next;
            if(NULL == _src)
            {
                ret = E_NOT;
                printf("ERROR uncorrect account id\n");
                getchar();
                return ret;
            }
        }
        if(cash > _src->Cash)
        {
            ret = E_NOT;
            printf("NO enough cash on source account\n");
            getchar();
        }
        else
        {
            _src->Cash -= cash;
            _dest->Cash += cash;
            ret = E_OK;
            printf("Cash Transfer Successfully\n");
            getchar();
        }
        
    }
    return ret;
}


/* ---------------------------------------------------*/
data_t *create_node(void)
{
    data_t *temp = (data_t *)calloc(1, sizeof(data_t));
    if (!temp)
        return NULL;
    else
        return temp;
}
void get_data(data_t **temp)
{
    ++id;
    (*temp)->next = NULL;
    (*temp)->id = id;
    setbuf(stdin, NULL);
    printf("Enter Client Name: \n");
    fgets(((*temp)->ClientName), 60, stdin);
    setbuf(stdin, NULL);
    printf("enter client Account Type: \n");
    fgets(((*temp)->AccountType), 12, stdin);
    setbuf(stdin, NULL);
    printf("enter Client Cash: \n");
    scanf("%llu", &((*temp)->Cash));
    setbuf(stdin, NULL);
}

static void edit_screen(void)
{
    printf("\n\n");
    printf("1-Edit Customer Name\n");
    printf("2-Edit Customer Cash\n");
    printf("3-Edit Account Type\n");
    printf("0-Exit Edit Screen\n");
    return;
}