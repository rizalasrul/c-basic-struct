#include <stdio.h>

main() {
	struct date {
		int day, month, year;
	} today, tomorrow;

	puts("MENCARI NILAI TANGGAL");
	fflush(stdin);
	printf("\nMasukkan tanggal sekarang [dd-mm-yyyy): ");
	scanf("%d-%d-%d", &today.day, &today.month, &today.year);
	tomorrow = today;
	tomorrow.day++;
	if (today.month == 1 || today.month == 3 || today.month == 5 || today.month == 7 || today.month == 8 || today.month == 10 || today.month == 12) {
		if (today.day == 31) {
			if (today.month == 12)
				tomorrow.day = 1, tomorrow.month = 1, tomorrow.year++;
			else
				tomorrow.day = 1, tomorrow.month++;
		}
	}
	else {
		if (today.month == 2) {
			if (today.year % 4 != 0) {
				if (today.day == 28)
					tomorrow.day = 1, tomorrow.month++;
			}
			else {
				if (today.day == 29)
					tomorrow.day = 1, tomorrow.month++;
			}
		}
		else
		if (today.day == 30)
			tomorrow.day = 1, tomorrow.month++;
	}
	printf("Besoknya: %d-%d-%d\n", tomorrow.day, tomorrow.month, tomorrow.year);
}