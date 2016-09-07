#include <stdio.h>
#include <string.h>

struct LARIS {
	char code;
	char name[7];
	int price, discount, qty, pricetotal;
};
int i, fee, total;

void input(struct LARIS[], int);
void nota(struct LARIS[], int);

main() {
	struct LARIS data[3] = { 0 };
	int n;

	puts("\t\tToko LARIS\n\t\tDaftar Harga");
	puts("-------------------------------------------------");
	puts("Ukuran Baju\tNama Ukuran\tHarga per Potong");
	puts("-------------------------------------------------");
	puts("     S\t\tSmall\t\tRp.36.000,-");
	puts("     M\t\tMedium\t\tRp.36.000,-");
	puts("     L\t\tSmall\t\tRp.36.000,-");
	puts("-------------------------------------------------");
	puts("\nDapatkan diskon 20% untuk pembelian lebih dari 10 potong...");
	puts("Jangan lupa, pajaknya ya... (10% x (harga - diskon))");
	do {
		printf("\nBerapa jumlah data (maks 3) ? ");
		scanf("%d", &n);
		if ((n < 1) || (n > 3))
			puts("Tidak sesuai ketentuan. Masukkan lagi");
	} while ((n < 1) || (n > 3));
	input(data, n);
	nota(data, n);
}

void input(struct LARIS x[], int y) {
	for (i = 0; i < y; i++) {
		printf("\nData ke-%d\n", i + 1);
		fflush(stdin);
		printf("Ukuran [S/M/L]\t: ");
		x[i].code = getchar();
		fflush(stdin);
		printf("Jumlah beli\t: ");
		scanf("%d", &x[i].qty);
		if ((x[i].code == 'S') || (x[i].code == 's'))
			strcpy(x[i].name, "SMALL"), x[i].price = 36000;
		else if ((x[i].code == 'M') || (x[i].code == 'm'))
			strcpy(x[i].name, "MEDIUM"), x[i].price = 43000;
		else
			strcpy(x[i].name, "LARGE"), x[i].price = 62000;
		x[i].pricetotal = x[i].qty * x[i].price;
		if (x[i].qty > 10)
			x[i].discount = 0.2 * x[i].pricetotal;
		x[i].pricetotal -= x[i].discount;
		total += x[i].pricetotal;
	}
	fee = 0.1 * total;
}

void nota(struct LARIS x[], int y) {
	puts("\nNota Belanja Anda :");
	puts("\n\t\t\tToko LARIS\n");
	puts("=============================================================================");
	puts("No\tNama Ukuran\tHarga Satuan\tQty\tDiskon\t\tJumlah Harga");
	puts("=============================================================================");
	for (i = 0; i < y; i++) {
		printf("%d\t%s\t\tRp%7d.00\t%d\tRp%7d.00\tRp%7d.00\n", i + 1,
			x[i].name,
			x[i].price,
			x[i].qty,
			x[i].discount,
			x[i].pricetotal);
	}
	puts("=============================================================================");
	printf("\t\t\t\t\t\tJumlah bayar\tRp%8d.00\n", total);
	printf("\t\t\t\t\t\tPajak 10%\tRp%8d.00\n", fee);
	printf("\t\t\t\t\t\tTOTAL BAYAR\tRp%8d.00\n", total + fee);
	puts("\n\t\tTERIMA KASIH ATAS KUNJUNGAN ANDA");
}