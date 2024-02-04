#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
 * 配列setが集合{3,7,11,15} を表現
 */
int set[] = {3, 7, 11, 15};
int len = 4;

// setが10要素の場合
// int set[] = {3, 5, 7, 11, 13, 15, 17, 19, 23, 29};
// int len = 10;

/*
 * set[]: 正の整数の集合
 * n:     対象とする要素数
 * sum:   部分和
 */
bool* subsetSum(int* set, int n, int sum) {
  bool* S  = (bool*)malloc(sizeof(bool) * len);
  bool** dp_table = (bool**)malloc(sizeof(bool*) * (n + 1));

  //初期化
  for (int i = 0; i <= n; i++) {
    dp_table[i] = (bool*)malloc(sizeof(bool) * (sum + 1));
    dp_table[i][0] = true;
  }
  for (int j = 1; j <= sum; j++) {
    dp_table[0][j] = false;
  }

  //DPテーブルの計算
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (j < set[i - 1]) {
        dp_table[i][j] = dp_table[i - 1][j];
      } else {
        dp_table[i][j] = dp_table[i - 1][j] || dp_table[i - 1][j - set[i - 1]];
      }
    }
  }

  //部分集合が存在しなかった場合
  if (!dp_table[n][sum]) {
    for (int i = 0; i <= n; i++) {
      free(dp_table[i]);
    }
    free(dp_table);
    free(S);
    return NULL;
  }

  //配列Sの計算
  for (int i = 0; i < len; i++) {
    S[i] = false;
  }

  int j = sum;
  for (int i = n; i > 0; i--) {
    if (dp_table[i][j] && !dp_table[i - 1][j]) {
      S[i - 1] = true;
      j -= set[i - 1];
    }
  }

  //メモリの解放
  for (int i = 0; i <= n; i++) {
    free(dp_table[i]);
  }
  free(dp_table);

  return S;
}

int main(int argc, char* argv[]) {
  if (argc == 3) {
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    bool* S = subsetSum(set, n, k);
    if (S != NULL) {
      printf("部分集合");
      for (int j = 0; j < len; j++)
        if (S[j])
          printf(" %d", set[j]);
      printf("\n");
      } else
      printf("条件を満たす部分集合はない．\n");
  } else 
    fprintf(stderr, "Usage: subsetsum <n> <sum>\n");

  return 0;
}
