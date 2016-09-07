#include <stdio.h>
#include <string.h>

main() {
	struct GFC {
		char kind;
		char food[6];
		int price, qty, sum;
	} order[15];
	int i = 0, tempcount, total = 0, fee;
	char option;

	puts("Toko GFC - Gerobak Fried Chicken\n");
	puts("DAFTAR HARGA");
	puts("Kode\tJenis\tHarga Per Potong");
	puts("D\tDada\tRp. 5000.00");
	puts("P\tPaha\tRp. 4000.00");
	puts("S\tSayap\tRp. 3000.00\n");
	puts("Harga belum termasuk pajak : 10%\n");
	puts("Masukkan Pesanan Anda");
	do {
		printf("Pesanan ke-%d\n", i + 1);
		fflush(stdin);
		printf("Jenis [D/P/S]\t: ");
		scanf("%c", &order[i].kind);
		fflush(stdin);
		printf("Jumlah\t\t: ");
		scanf("%d", &order[i].qty);
		fflush(stdin);
		printf("Ada lagi <Y/T>? ");
		option = getchar();
		fflush(stdin);
		if (order[i].kind == 'D' || order[i].kind == 'd') {
			strcpy(order[i].food, "DADA");
			order[i].price = 5000;
		}
		else if (order[i].kind == 'P' || order[i].kind == 'p') {
			strcpy(order[i].food, "PAHA");
			order[i].price = 4000;
		}
		else {
			strcpy(order[i].food, "SAYAP");
			order[i].price = 3000;
		}
		order[i].sum = order[i].qty * order[i].price;
		total += order[i].sum;
		i++;
		puts("");
	} while (option == 'y' || option == 'Y');
	tempcount = i;
	fee = total / 10;
	puts("\nNota Belanja Anda :\n");
	puts("\t\tGEROBAK FRIED CHICKEN\n");
	puts("============================================================");
	puts("No\tJenis Potong\tHarga Satuan\tQty\tJumlah Harga");
	puts("============================================================");
	for (i = 0; i < tempcount; i++) {
		printf("%d\t%s\t\tRp.%6d.00\t%d\tRp.%6d.00\n", i + 1,
			order[i].food,
			order[i].price,
			order[i].qty,
			order[i].sum);
	}
	puts("============================================================");
	printf("\t\t\t\tJumlah Bayar\tRp.%6d.00\n", total);
	printf("\t\t\t\tPajak 10%%\tRp.%6d.00\n", fee);
	printf("\t\t\t\tTOTAL BAYAR\tRp.%6d.00\n", total + fee);
}