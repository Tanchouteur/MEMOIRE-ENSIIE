#include <stdio.h>
#include <stdlib.h>

#define MONTH_SIZE {31,28,31,30,31,30,31,31,30,31,30,31}

struct date
{
    int day;
    int month;
    int year;
};

void print_date(struct date *d)
{
    printf("%02d/%02d/%04d\n", d->day, d->month, d->year);
}

void incr_date(struct date *d)
{
    d->day += 1;
    int month_size[] = MONTH_SIZE;

    if (d->day > month_size[d->month - 1])
    {
        d->day = 1;
        d->month += 1;

        if (d->month > 12)
        {
            d->month = 1;
            d->year += 1;
        }
    }
}

int main()
{
    struct date *d = malloc(sizeof(struct date));
    int day = 31, month = 12, year = 2024;
    d->day = day;
    d->month = month;
    d->year = year;

    while (d->year < 30026)
    {
        incr_date(d);
        print_date(d);
    }

    free(d);

    return 0;
}