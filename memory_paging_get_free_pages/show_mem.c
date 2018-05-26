/*
 * Generic show_mem() implementation
 *
 * Copyright (C) 2008 Johannes Weiner <hannes@saeurebad.de>
 * All code subject to the GPL version 2.
 */

#include <linux/mm.h>
#include <linux/quicklist.h>
#include <linux/cma.h>

void my_buddyinfo_show(void);

void my_buddyinfo_show()
{
    int i;
    int j;
    struct pglist_data* node_0;
    struct zone* pzone;
    node_0 = NODE_DATA(0);
    if (node_0 == NULL)
        return ;
    for (i = 0; i < MAX_NR_ZONES; ++i)
    {
        pzone = &node_0->node_zones[i];
        if (pzone == NULL)
            continue;
        printk("Node 0 Zone %s", pzone->name);
        if (pzone->free_area == NULL)
            continue;
        for (j = 0; j < MAX_ORDER; ++j)
        {
            printk("%5lu", pzone->free_area[j].nr_free);
        }
        printk("\n");
    }
}


void show_mem(unsigned int filter, nodemask_t *nodemask)
{
	pg_data_t *pgdat;
	unsigned long total = 0, reserved = 0, highmem = 0;

	printk(" Srinth Koilakonda: Mem-Info:\n"); //delete it
	show_free_areas(filter, nodemask);

	for_each_online_pgdat(pgdat) {
		unsigned long flags;
		int zoneid;

		pgdat_resize_lock(pgdat, &flags);
		for (zoneid = 0; zoneid < MAX_NR_ZONES; zoneid++) {
			struct zone *zone = &pgdat->node_zones[zoneid];
			if (!populated_zone(zone))
				continue;

			total += zone->present_pages;
			reserved += zone->present_pages - zone->managed_pages;

			if (is_highmem_idx(zoneid))
				highmem += zone->present_pages;
		}
		pgdat_resize_unlock(pgdat, &flags);
	}

	printk(" Srinath koilakonda : %lu pages RAM\n", total);
	printk(" Srinath koilakonda : %lu pages HighMem/MovableOnly\n", highmem);
	printk(" Srinath koilakonda : %lu pages reserved\n", reserved);
#ifdef CONFIG_CMA
	printk(" Srinath koilakonda : %lu pages cma reserved\n", totalcma_pages);
#endif
#ifdef CONFIG_QUICKLIST
	printk(" Srinath koilakonda : %lu pages in pagetable cache\n",
		quicklist_total_size());
#endif
#ifdef CONFIG_MEMORY_FAILURE
	printk(" Srinath koilakonda : %lu pages hwpoisoned\n", atomic_long_read(&num_poisoned_pages));
#endif
}
