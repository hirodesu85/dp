#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * 二次元int配列の生成
 * rows: 行数
 * cols: 列数
 */
int** makeIntMatrix(int rows, int cols) {
  int** matrix = (int **)malloc(sizeof(int*) * (rows + 1));
  int* array = (int *)malloc(sizeof(int) * (rows + 1) * (cols + 1));
  for (int i = 0; i < rows + 1; i++) {
    matrix[i] = array + (cols + 1) * i;
  }
  return matrix;
}

/**
 * 二次元bool配列の生成
 * rows: 行数
 * cols: 列数
 */
bool** makeBoolMatrix(int rows, int cols) {
  bool** matrix = (bool **)malloc(sizeof(bool*) * (rows + 1));
  bool* array = (bool *)malloc(sizeof(bool) * (rows + 1) * (cols + 1));
  for (int i = 0; i < rows + 1; i++) {
    matrix[i] = array + (cols + 1) * i;
  }
  return matrix;
}

/**
 * ナップサック問題の最適解を探索（動的計画法）
 * v: 価格の配列
 * w: 重さの配列
 * n: 対象とする荷物の数
 * C: ナップサックの容量
 */
bool* knapsack(int v[], int w[], int n, int C) {
  int k, i, v1;
  int** G = makeIntMatrix(n, C);
  bool** S = makeBoolMatrix(n, C);
  bool* SS = (bool*)malloc(sizeof(bool) * (n + 1));

  // 動的計画法のプログラム（配列S[][]を計算）

  // 配列G[][]と配列S[][]から選択された荷物の集合SS[]を計算

  return SS;
}

int main(int argc, char** argv) {
  /* 教科書：表 6.1の例
     v[1]〜v[4]：価格
     w[1]〜w[4]：重さ */
  int num = 4;
  int v[] = {0, 250, 380, 420, 520};
  int w[] = {0, 1, 2, 4, 3};

  // 引数処理
  if (argc == 3) {
    int k = atoi(argv[1]);
    int i = atoi(argv[2]);
    bool* S = knapsack(v, w, k, i);  
    int total = 0;
    for (int k = 1; k <= num; k++) 
      if (S[k]) {
	total = total + v[k];
	printf("重さ %d 価値 %d\n", w[k], v[k]);
      }
    printf("合計価値 %d\n", total);
  } else {
    fprintf(stderr, "Usage: knapsackDP2 <k: no. of items> <i: capacity>\n");
    return 1;
  }
  return 0;
}
