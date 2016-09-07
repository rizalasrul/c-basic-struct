#include <stdio.h>
#include <string.h>

typedef struct {
	char name[50];
	char scorechar;
	float scoreWork, scoreUTS, scoreUAS, scoreFin;
} collage;
typedef struct {
	char name[50];
	float scorefin;
} maks;

int i, j;

void input(collage *, int *, maks *);
void tampil(collage *, int *, maks *);

main() {
	collage data[7];
	maks ranking;
	int n;

	puts("MENGHITUNG NILAI AKHIR\nMATA KULIAH KONSEP PEMROGRAMAN\n");
	printf("Berapa jumlah mahasiswa ? ");
	scanf("%d", &n);
	printf("\nMasukkan DATA Mahasiswa\n");
	input(data, &n, &ranking);
	tampil(data, &n, &ranking);
}

void input(collage *px, int *py, maks *pz) {
	for (i = 0; i < *py; i++) {
		printf("\nMahasiswa ke-%d\n", i + 1);
		fflush(stdin);
		printf("Nama\t\t: ");
		gets((px + i)->name);
		fflush(stdin);
		printf("Nilai tugas\t: ");
		scanf("%f", &(px + i)->scoreWork);
		printf("Nilai uts\t: ");
		scanf("%f", &(px + i)->scoreUTS);
		printf("Nilai uas\t: ");
		scanf("%f", &(px + i)->scoreUAS);
		(px + i)->scoreFin = (0.2 * (px + i)->scoreWork) + (0.4 * (px + i)->scoreUTS) + (0.4 * (px + i)->scoreUAS);
		fflush(stdin);
		if ((px + i)->scoreFin >= 80)
			(px + i)->scorechar = 'A';
		else if (((px + i)->scoreFin < 80) && ((px + i)->scoreFin >= 70))
			(px + i)->scorechar = 'B';
		else if (((px + i)->scoreFin < 70) && ((px + i)->scoreFin >= 60))
			(px + i)->scorechar = 'C';
		else if (((px + i)->scoreFin < 60) && ((px + i)->scoreFin >= 50))
			(px + i)->scorechar = 'D';
		else
			(px + i)->scorechar = 'E';
		fflush(stdin);
	}
	i = 0;
	strcpy(pz->name, (px + i)->name);
	pz->scorefin = (px + i)->scoreFin;
	do {
		if ((px + i)->scoreFin > pz->scorefin)
			strcpy(pz->name, (px + i)->name), pz->scorefin = (px + i)->scoreFin;
		i++;
	} while (i < *py);
}

void tampil(collage *px, int *py, maks *pz) {
	puts("\t\t\tDAFTAR NILAI\n\t\tMATAKULIAH KONSEP PEMROGRAMAN");
	puts("---------------------------------------------------------------------");
	puts("No\tNama\t\t\t\tNilai\t\t\tGrade");
	puts("  \tMahasiswa\t\tTugas\tUTS\tUAS\tAkhir\t");
	puts("---------------------------------------------------------------------");
	for (i = 0; i < *py; i++) {
		printf("%d\t%s\t\t%g\t%g\t%g\t%g\t%c\n", i + 1,
			(px + i)->name,
			(px + i)->scoreWork,
			(px + i)->scoreUTS,
			(px + i)->scoreUAS,
			(px + i)->scoreFin,
			(px + i)->scorechar);
	}
	puts("---------------------------------------------------------------------");
	printf("\nTotal Mahasiswa = %d\n", *py);
	puts("Nilai Tertinggi");
	printf("Nama\t: %s\n", pz->name);
	printf("Nilai\t: %g\n", pz->scorefin);
}