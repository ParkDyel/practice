/* EUC-KR
*
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#define LIST_COUNT 4

typedef struct _busket_element
{
    char name[6];
    int amount;
    int price;
    int cost;
} busket, *ptr_busket;

//input
char fruit_name[LIST_COUNT][6] = {"사과", "포도", "배", "자두"};
int fruit_amout[LIST_COUNT] = {20, 30, 15, 25};
int fruit_price[LIST_COUNT] = {1500, 2000, 2500, 900};

void setData(ptr_busket ptr, int idx)
{
    strcpy(ptr->name, fruit_name[idx]);
    ptr->amount = fruit_amout[idx];
    ptr->price = fruit_price[idx];
    return;
}

int setCost(ptr_busket ptr)
{
    ptr->cost = (ptr->price) * (ptr->amount);
    return ptr->cost;
}

ptr_busket getData(ptr_busket ptr)
{
    printf("\t--START DATA %x--\n\tName\t%s\n\tamount\t%d\n\tprice\t%d\n\tcost\t%d\n\t--END DATA--\n\n", ptr, ptr->name, ptr->amount, ptr->price, ptr->cost);
    return ptr;
}

void bubbleSort(ptr_busket ptr)
{
    if (ptr->cost < (ptr + 1)->cost)
    {
        swapBuskets(ptr, (ptr) + 1);
    }
    return;
}

void swapBuskets(ptr_busket ptr1, ptr_busket ptr2)
{
    busket temp_busket;
    {
        strcpy(temp_busket.name, ptr1->name);
        temp_busket.amount = ptr1->amount;
        temp_busket.price = ptr1->price;
        temp_busket.cost = ptr1->cost;
    }
    {
        strcpy(ptr1->name, ptr2->name);
        ptr1->amount = ptr2->amount;
        ptr1->price = ptr2->price;
        ptr1->cost = ptr2->cost;
    }
    {
        strcpy(ptr2->name, temp_busket.name);
        ptr2->amount = temp_busket.amount;
        ptr2->price = temp_busket.price;
        ptr2->cost = temp_busket.cost;
    }
    return;
}

int main()
{
    printf("Program Start\n");
    // ptr_busket ptr1;
    ptr_busket ptr_buskets;

    printf("malloc : busket array\n");
    {
        ptr_buskets = (busket *)malloc(sizeof(busket) * LIST_COUNT);
        memset(ptr_buskets, -1, sizeof(busket) * LIST_COUNT);
        printf("malloc : allocated memory { size : %d\t address : %x }\n", sizeof(busket) * LIST_COUNT, ptr_buskets);
    }

    printf("init List : init Data in List \n");
    {
        for (ptr_busket ptr_temp = ptr_buskets; ptr_temp - ptr_buskets < LIST_COUNT; (*ptr_temp++))
        {
            // idx == ptr_temp - ptr_buskets
            setData(ptr_temp, ptr_temp - ptr_buskets);
        }
    }

    printf("set List's Cost: set cost\n");
    {
        for (ptr_busket ptr_temp = ptr_buskets; ptr_temp - ptr_buskets < LIST_COUNT; ptr_temp++)
        {
            setCost(ptr_temp);
        }
    }

    printf("showList : show data in list.\n");
    {
        for (ptr_busket ptr_temp = ptr_buskets; ptr_temp - ptr_buskets < LIST_COUNT; ptr_temp++)
        {
            getData(ptr_temp);
        }
    }
    printf("Sort lists as cost attr.\n");
    {
        for (ptr_busket ptr_temp = ptr_buskets; ptr_temp - ptr_buskets < LIST_COUNT - 1; ptr_temp++)
        {
            for (ptr_busket ptr_temp2 = ptr_buskets; ptr_temp2 - ptr_buskets < LIST_COUNT - (ptr_temp - ptr_buskets) - 1; ptr_temp2++)
            {
                bubbleSort(ptr_temp2);
            }
        }
    }

    printf("showList : show data in list.\n");
    {
        for (ptr_busket ptr_temp = ptr_buskets; ptr_temp - ptr_buskets < LIST_COUNT; ptr_temp++)
        {
            getData(ptr_temp);
        }
    }

    printf("printList : printList\n");
    {
        printf("품목\t수량\t단가\t금액\t순위\n");
        for (ptr_busket ptr_temp = ptr_buskets; ptr_temp - ptr_buskets < LIST_COUNT; ptr_temp++)
        {
            printf("%s\t%d\t%d\t%d\t%d\n", ptr_temp->name, ptr_temp->amount, ptr_temp->price, ptr_temp->cost, ptr_temp - ptr_buskets + 1);
        }
    }

    printf("free : busket array\n");
    {
        free(ptr_buskets);
    }

    printf("Program End\n");
}