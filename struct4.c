#include <stdio.h>

struct collage {
	char name[50];
	char scorechar;
	int scoreWork, scoreUTS, scoreUAS, scoreFin;
};
int i;

void input(struct collage[], int);
void tampil(struct collage[], int);

main() {
	struct collage data[7];
	int n;

	puts("MENGHITUNG NILAI AKHIR\nMATA KULIAH KONSEP PEMROGRAMAN\n");
	printf("Berapa jumlah mahasiswa ? ");
	scanf("%d", &n);
	printf("\nMasukkan DATA Mahasiswa\n");
	input(data, n);
	tampil(data, n);
}

void input(struct collage x[], int y) {
	for (i = 0; i < y; i++) {
		printf("\nMahasiswa ke-%d\n", i + 1);
		fflush(stdin);
		printf("Nama\t\t: ");
		gets(x[i].name);
		fflush(stdin);
		printf("Nilai tugas\t: ");
		scanf("%d", &x[i].scoreWork);
		printf("Nilai uts\t: ");
		scanf("%d", &x[i].scoreUTS);
		printf("Nilai uas\t: ");
		scanf("%d", &x[i].scoreUAS);
		x[i].scoreFin = (0.2 * x[i].scoreWork) + (0.4 * x[i].scoreUTS) + (0.4 * x[i].scoreUAS);
		fflush(stdin);
		if (x[i].scoreFin >= 80)
			x[i].scorechar = 'A';
		else if ((x[i].scoreFin < 80) && (x[i].scoreFin >= 70))
			x[i].scorechar = 'B';
		else if ((x[i].scoreFin < 70) && (x[i].scoreFin >= 60))
			x[i].scorechar = 'C';
		else if ((x[i].scoreFin < 60) && (x[i].scoreFin >= 50))
			x[i].scorechar = 'D';
		else
			x[i].scorechar = 'E';
		fflush(stdin);
	}
}

void tampil(struct collage x[], int y) {
	puts("\t\t\tDAFTAR NILAI\n\t\tMATAKULIAH KONSEP PEMROGRAMAN");
	puts("---------------------------------------------------------------------");
	puts("No\tNama\t\t\t\tNilai\t\t\tGrade");
	puts("  \tMahasiswa\t\tTugas\tUTS\tUAS\tAkhir\t");
	puts("---------------------------------------------------------------------");
	for (i = 0; i < y; i++) {
		printf("%d\t%s\t\t%d\t%d\t%d\t%d\t%c\n", i + 1,
			x[i].name,
			x[i].scoreWork,
			x[i].scoreUTS,
			x[i].scoreUAS,
			x[i].scoreFin,
			x[i].scorechar);
	}
	puts("---------------------------------------------------------------------");
	printf("\nTotal Mahasiswa = %d\n", y);
}