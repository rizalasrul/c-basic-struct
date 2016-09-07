#include <stdio.h>
#define MAKS 20

struct date {
	int month, day, year;
};
struct student {
	char name[30];
	struct date birthday;
};

main() {
	struct student data_mhs[MAKS];
	int i = 0, jml;
	char lagi;

	do {
		printf("Name : ");
		gets(data_mhs[i].name);
		printf("Birthday (mm-dd-yyyy): ");
		scanf("%d-%d-%d",
			&data_mhs[i].birthday.month,
			&data_mhs[i].birthday.day,
			&data_mhs[i].birthday.year);
		i++;
		fflush(stdin);
		printf("\nMau memasukkan data lagi [Y/T]? ");
		lagi = getchar();
		fflush(stdin);
	} while (lagi == 'Y' || lagi == 'y');

	jml = i;
	printf("\nDATA MAHASISWA\n");
	for (i = 0; i < jml; i++) {
		printf("%d. Name\t: %s", i + 1, data_mhs[i].name);
		printf("\n   Birhtday\t: %d=%d-%d\n\n",
			data_mhs[i].birthday.month,
			data_mhs[i].birthday.day,
			data_mhs[i].birthday.year);
	}
}
