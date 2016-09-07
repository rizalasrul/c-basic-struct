#include <stdio.h>
#include <string.h>

typedef struct {
	int ID, honor;
	char name[20], sexname[10];
	char sex;
	struct date {
		int day, month, year;
	} birthday;
} pegawai;

int i;

void tampil(pegawai *, int *);
void input(pegawai *, int *);

main() {
	pegawai emp[10] = { 0 };
	int n;

	puts("\t\t\tDATA PEGAWAI\n");
	printf("Jumlah pegawai : ");
	scanf("%d", &n);
	input(emp, &n);
	tampil(emp, &n);
}

void input(pegawai *px, int *py) {
	for (i = 0; i < *py; i++) {
		printf("\nData Pegawai Ke-%d\n", i + 1);
		fflush(stdin);
		(px + i)->ID = i + 1;
		printf("Nama\t\t\t: ");
		gets((px + i)->name);
		fflush(stdin);
		printf("Tgl Lahir (dd-mm-yyy)\t: ");
		scanf("%d-%d-%d", &(px + i)->birthday.day, &(px + i)->birthday.month, &(px + i)->birthday.year);
		fflush(stdin);
		printf("Jenis Kelamin [L/P]\t: ");
		(px + i)->sex = getchar();
		fflush(stdin);
		printf("Gaji/Bln\t\t: ");
		scanf("%d", &(px + i)->honor);
		if (((px + i)->sex == 'l') || ((px + i)->sex == 'L'))
			strcpy((px + i)->sexname, "Laki-Laki");
		else
			strcpy((px + i)->sexname, "Perempuan");
	}
}

void tampil(pegawai *px, int *py) {
	puts("\nData pegawai yang telah diinputkan");
	for (i = 0; i < *py; i++) {
		printf("\nNo ID\t\t: %d\n", (px + i)->ID);
		printf("Nama\t\t: %s\n", (px + i)->name);
		printf("Tgl lahir\t: %d-%d-%d\n",
			(px + i)->birthday.day,
			(px + i)->birthday.month,
			(px + i)->birthday.year);
		printf("Jenis kelamin\t: %s\n", (px + i)->sexname);
		printf("Gaji/bln\t: Rp %7d.00\n", (px + i)->honor);
	}
}