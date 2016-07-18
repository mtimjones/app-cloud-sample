/*
 * DESCRIPTION A simple function which serves as a starting point for a C
 * program. This function can be changed, removed, or replaced. The function
 * will be launched as a task when the Zephyr kernel is run. See prj.mdef to
 * adjust task parameters and entry point.
 */

#include <stdio.h>
#include <zephyr.h>
#include <microkernel.h>

/* Specify delay for each pass through the pool (in ms); compute equivalent in ticks */

#define SLEEPTIME  1000
#define SLEEPTICKS (SLEEPTIME * sys_clock_ticks_per_sec / 1000)

int main ( void )
    {
        printf( "%8d: Initialization\n", task_tick_get_32( ) );
   

        while (1)
        {
            printf( "%8d: Looping\n", task_tick_get_32( ) );

            /* wait a while, then let other task have a turn */
            task_sleep( SLEEPTICKS );
        }

    }
