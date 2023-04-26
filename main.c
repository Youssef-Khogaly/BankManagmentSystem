#include "main.h"

void main(void)
{
    uint8_t program_select = 0;
    uint64_t id = 0;
    uint64_t src_id;
    uint64_t dest_id;
    uint64_t Cash = 0;
    StdReturn_t ret = E_NOT;
    list_t *Data_base = (list_t *)calloc(1, sizeof(list_t));
    if (NULL == Data_base)
        return;
    else
    {
        ret = data_init(&(Data_base));
    }

    while (1)
    {
        main_screen();
        scanf("%u", &program_select);
        switch (program_select)
        {
        case 1:
            ret = data_add_new_customer(&(Data_base));
            break;
        case 2:
            printf("Enter Account ID: \n");
            scanf("%llu", &id);
            ret = data_remove_customer(&(Data_base), id);
            break;
        case 3:
            printf("Enter Account ID: \n");
            scanf("%llu", &id);
            ret = data_edit_customer(&(Data_base), id);
            break;
        case 4:
            printf("Enter Account ID: \n");
            scanf("%llu", &id);
            ret = data_check_customer(&(Data_base), id);
            break;
        case 5:
        printf("Enter Account id to transfer cash from: \n");
        scanf("%llu" , &src_id);
        setbuf(stdin , NULL);
        printf("Enter Account id to trasfer cash to to it: \n");
        scanf("%llu" , &dest_id);
        setbuf(stdin , NULL);
        printf("Enter the amout of the cash to transfer: \n");
        scanf("%llu" , &Cash);
        setbuf(stdin , NULL);        
        ret = Cash_Transfer(dest_id , src_id , Cash , &Data_base);
            break;
        case 0:
            return;
            break;
        default:
            printf("Wrong Option Number!!\n\n");
            getchar();
        }
    }
    return;
}