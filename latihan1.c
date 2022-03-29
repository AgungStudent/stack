#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK 3

typedef struct STACK {
  short top;
  char data[3][3];
} STACK;
STACK tumpuk;

void inisialisasi() { tumpuk.top = -1; }

short isFull() {
  if (tumpuk.top == MAX_STACK - 1)
    return 1;
  return 0;
}

short isEmpty() {
  if (tumpuk.top == -1)
    return 1;
  return 0;
}

void push(char d[]) {
  tumpuk.top++;
  strcpy(tumpuk.data[tumpuk.top], d);
}

void pop() {
  printf("Data yang diambil: %s", tumpuk.data[tumpuk.top]);
  tumpuk.top--;
}

void tampil() {
  for (int i = tumpuk.top; i >= 0; i--)
    printf("Data: %s\n", tumpuk.data[i]);
}

void clear() { tumpuk.top = -1; }

int main() {
  short pilihan;
  inisialisasi();
  char dt[3];
  do {
    system("cls");
    puts("Menu");
    puts("1. Push");
    puts("2. Pop");
    puts("3. Cetak isi array STACK!");
    puts("4. Hapus isi array STACK!");
    puts("5. keluar");
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    if (pilihan == 1) {
      if (isFull() != 1) {
        printf("Data yg ingin disimpan: ");
        scanf("%s", dt);
        push(dt);
      } else {
        printf("Array STACK sudah penuh!");
      }
    } else if (pilihan == 2) {
      if (isEmpty() != 1)
        pop();
      else
        printf("Data masih kosong!");
    } else if (pilihan == 3) {
      if (isEmpty() != 1)
        tampil();
      else
        printf("Masih kosong!");
    } else if (pilihan == 4) {
      clear();
      printf("Array STACK sudah kosong!");
    } else if (pilihan == 5) {
      printf("Keluar dari program");
      getch();
      break;
    } else {
      printf("Pilihan salah");
    }

    getch();
  } while (pilihan != 5);
}