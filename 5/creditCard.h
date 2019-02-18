#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H
typedef struct {
	unsigned long long card_no;
	char bank_code[6];
	char expiry_date[8];
	char first_name[20];
	char last_name[20];
} CREDIT_CARD;
#endif