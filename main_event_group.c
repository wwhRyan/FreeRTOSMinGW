#include <stdio.h>
#include <stdbool.h>

#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"

/* Declare a variable to hold the created event group. */
EventGroupHandle_t xCreatedEventGroup;

#define BIT_0 (1 << 0)
#define BIT_4 (1 << 4)

void TxTask(void *pvParameters)
{
    EventBits_t uxBits;

    while (true)
    {
        /* Set bit 0 and bit 4 in xEventGroup. */
        uxBits = xEventGroupSetBits(
            xCreatedEventGroup, /* The event group being updated. */
            BIT_0 | BIT_4);     /* The bits being set. */

        printf("uxBits set 0x11.\n");

        vTaskDelay(1000); // 1 second
    }
}

void RxTask(void *pvParameters)
{
    EventBits_t uxBits;

    while (true)
    {
        uxBits = xEventGroupGetBits(xCreatedEventGroup);

        printf("uxBits is: %X\n", uxBits);

        printf("uxBits clear BIT 0.\n");
        xEventGroupClearBits(xCreatedEventGroup, BIT_0);

        vTaskDelay(500); // 1 second
    }
}

int main()
{
    /* Attempt to create the event group. */
    xCreatedEventGroup = xEventGroupCreate();

    /* Was the event group created successfully? */
    if (xCreatedEventGroup == NULL)
    {
        /* The event group was not created because there was insufficient
        FreeRTOS heap available. */
    }
    else
    {
        /* The event group was created. */
    }

    xTaskCreate(RxTask, "Rx", 1000, NULL, 1, NULL);
    xTaskCreate(TxTask, "Tx", 1000, NULL, 1, NULL);

    vTaskStartScheduler();
    return 0;
}