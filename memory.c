#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int a = 50;
  // nの出力
  printf("%i\n", a);
  // nのアドレス
  printf("%p\n", &a);
  // *(間接参照演算子)を使用してポインタの指す先へアクセス
  printf("%i\n", *&a);


  printf("----------\n\n");


  int b = 50;
  // 下記はポインタ（アドレスを格納する変数)という
  // ＊でポインタ変数を宣言する
  int *c = &b; // ← bのアドレスが入っている
  printf("%p\n", c);
  // 最近のコンピューターは64ビット＝メモリのアドレス指定は６４ビット＝ポインタは8バイトになる
  // 元は３２ビットのため4バイトが基本であった


  printf("----------\n\n");


  // 文字列はchar *変数名 = "文字列";で宣言する
  char *d = "HI!";
  // HI!を出力
  printf("%s\n", d);
  // HI!は１文字ずつメモリ格納されている＝配列になっている
  printf("%c\n", d[0]);
  printf("%c\n", d[1]);
  printf("%c\n", d[2]);
  printf("%c\n", d[3]);


  printf("----------\n\n");

  // 文字列の比較では文字列自体がメモリ内の異なるポインタを指しているためFalseを返す
  char *e = "tennis";
  char *f = e;
  // なぜか動かない
  // f[0] = toupper(f[0]);
  // fだけ大文字返還したはずなのにeとfは両方大文字になってしまう
  // eとfは同じアドレスを参照しているから
  printf("e: %s\n", e);
  printf("f: %s\n", f);


  printf("----------\n\n");


  char *g = "tennis";
  // mallocは指定した数値分のメモリを割り当てる関数
  // ここでは変数gと終端のヌル文字分を合わせた数値を入力している
  char *h = malloc(strlen(g) + 1);
  // ループでhにgの文字列を1文字ずつコピーする
  for(int i = 0, n = strlen(g); i < n + 1; i++) {
    h[i] = g[i];
  }
  // hの１文字目を大文字にする
  h[0] = toupper(h[0]);
  // hだけ先頭が大文字に変更されているはず
  printf("g: %s\n", g);
  printf("h: %s\n", h);


  printf("----------\n\n");


  // 上記にエラーチェックを追加したバージョン
  char *i = "tennis";
  char *j = malloc(strlen(i) + 1);
  // メモリ不足の場合にmallocはNULLを返す
  // jがNULLなら1（終了）を返す
  if(j == NULL) {
    return 1;
  };
  for(int k = 0; k < strlen(j) + 1; k++) {
    j[k] = i[k];
  };
  // jが１文字でも入っているか（空ではないか）チェック
  if(strlen(j) > 0) {
    j[0] = toupper(j[0]);
  };
  printf("i: %s\n", i);
  printf("j: %s\n", j);
  // メモリを解放する場合はfree関数を使用する
  free(j);


  printf("----------\n\n");


  // 実際の文字列よりも少ないメモリ数を割り当てる
  // 文字数＝４、メモリ＝3
  char *l = malloc(3);
  l[0] = 'H';
  l[1] = 'I';
  l[2] = '!';
  l[3] = '\0';
  printf("%s\n", l);
  // valgrind ./memoryをターミナルで実行
  // 「Invalid write of size 1」 「Invalid read of size 1」 「3 bytes in 1 blocks are definitely lost」が返ってくる
  // なので適切なメモリ数を割り当てると、、
  char *m = malloc(4);
  m[0] = 'H';
  m[1] = 'I';
  m[2] = '!';
  m[3] = '\0';
  printf("%s\n", m);
  // valgrind ./memoryをターミナルで実行
  // エラーは出てこない

  printf("----------\n\n");


  int *n;
  int *o;
  n = malloc(sizeof(int));
  *n = 42;
  *o = 13;
  o = n;
  *o = 13;
  printf("%i\n", n);
  printf("%i\n", o);
};