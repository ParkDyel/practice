#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1

#define LIST_COUNT 4

typedef struct _busket_element
{
    char name[6];
    int amount;
    int price;
    int cost;
    struct _busket_element *next;
} busket, *ptr_busket;

typedef *ptr_busket pptr_buskets;

//input
char fruit_name[LIST_COUNT][6] = {"사과", "포도", "배", "자두"};
int fruit_amout[LIST_COUNT] = {20, 30, 15, 25};
int fruit_price[LIST_COUNT] = {1000, 1500, 2000, 900};

void setData(ptr_busket ptr, int idx)
{
    strcpy(ptr->name, fruit_name[idx]);
    ptr->amount = fruit_amout[idx];
    ptr->price = fruit_price[idx];
    ptr->next = NULL;
    return;
}

int setCost(ptr_busket ptr)
{
    ptr->cost = (ptr->price) * (ptr->amount);
    return ptr->cost;
}

ptr_busket setNext(ptr_busket ptr, ptr_busket ptr_next)
{
    ptr->next = ptr_next;
    return ptr->next;
}

ptr_busket getData(ptr_busket ptr, int idx)
{
    printf("\t--START DATA %x\n\tName\t%s\n\tamount\t%d\n\tprice\t%d\n\tcost\t%d\n\t--END DATA(Next Address %x)--\n\n", ptr, ptr->name, ptr->amount, ptr->price, ptr->cost, ptr->next);
    return ptr;
}

ptr_busket swapBusket(ptr_busket ptr_bf, int idx)
{
    ptr_busket ptr_temp;
    if (ptr_bf->next->cost > ptr_bf->next->next->cost)
    {
        ptr_temp = ptr_bf->next->next;
        ptr_bf->next->next = ptr_bf->next->next->next;
        ptr_bf->next->next->next = ptr_temp;
        ptr_bf->next = ptr_temp;
    }
    return ptr_temp;
}

ptr_busket swapHeaderBusket(ptr_busket ptr)
{
    ptr_busket ptr_temp;
    if (ptr->cost > ptr->next->cost)
    {
        ptr_temp = ptr->next;
        ptr->next = ptr->next->next;
        ptr->next->next = ptr_temp;
    }
    return ptr_temp;
}

ptr_buskets swapArrayAsCost(pptr_buskets pptr, int sizeOfBusket, int sizeOfList)
{
    //bubble sort
    ptr_busket ptr = *pptr;
    for (int idx = 0; idx <= sizeOfList / sizeOfBusket; idx++)
    {
        ptr = *pptr;
        for (int idx2 = 0; idx2 < idx; idx2++)
        {
            if (idx2 == 0)
            {
                *pptr = swapHeaderBusket(ptr);
                ptr = *pptr;
            }
            else
            {
                ptr = swapBusket(ptr, idx2);
            }
        }
    }
    return *pptr;
}

int main()
{
    printf("Program Start\n");
    // ptr_busket ptr1;
    pptr_buskets pptr_lists;

    printf("malloc : busket array\n");
    {
        pptr_lists = (busket **)malloc(sizeof(busket) * LIST_COUNT);
        memset(pptr_lists, -1, sizeof(busket) * LIST_COUNT);
        printf("malloc : allocated memory { size : %d\t address : %x }\n", sizeof(busket) * LIST_COUNT, &pptr_lists);
    }

    printf("init List : init Data in List \n");
    {
        // for (ptr_busket ptr_temp = ptr1; ptr_temp - ptr1 < LIST_COUNT; (*ptr_temp++))
        for (ptr_busket ptr_temp = *pptr_lists; ptr_temp - *pptr_lists < LIST_COUNT; (*ptr_temp++))
        {
            // idx == ptr_temp - ptr1
            // setData(ptr_temp, ptr_temp - ptr1);
            setData(ptr_temp, ptr_temp - *pptr_lists);
            if (ptr_temp - *pptr_lists < (LIST_COUNT - 1))
            {
                setNext(ptr_temp, ptr_temp + 1);
            }
            else
            {
                setNext(ptr_temp, NULL);
            }
        }
    }

    printf("set List's Cost: set cost\n");
    {
        ptr_busket ptr_temp = *pptr_lists;
        while (TRUE)
        {
            setCost(ptr_temp);
            ptr_temp = ptr_temp->next;
            if (ptr_temp == NULL)
                break;
        }
    }

    printf("showList : show data in list.\n");
    {
        ptr_busket ptr_temp = *pptr_lists;
        while (TRUE)
        {
            ptr_temp = getData(ptr_temp, ptr_temp - pptr_lists)->next;
            if (ptr_temp == NULL)
                break;
        }
    }
    printf("Sort lists as cost attr.\n");
    {
        swapArrayAsCost(pptr_lists, sizeof(busket), sizeof(busket)*LIST_COUNT));
    }

    printf("showList : show data in list.\n");
    {
        ptr_busket ptr_temp = *pptr_lists;
        while (TRUE)
        {
            ptr_temp = getData(ptr_temp, ptr_temp - pptr_lists)->next;
            if (ptr_temp == NULL)
                break;
        }
    }

    printf("free : busket array\n");
    {
        free(pptr_lists);
    }

    printf("Program End\n");
}