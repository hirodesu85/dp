#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
 * 配列setが集合{3,7,11,15} を表現
 */
int set[] = {3, 7, 11, 15};
int len = 4;

/*
 * set[]: 正の整数の集合
 * n:     対象とする要素数
 * sum:   部分和
 */
bool* subsetSum(int* set, int n, int sum) {
  bool* S  = (bool*)malloc(sizeof(bool) * len);

  /* 関数を完成 */
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
	  printf("%d ", set[j]);
    } else
      printf("条件を満たす部分集合はない．\n");
  } else 
    fprintf(stderr, "Usage: subsetsum <n> <sum>\n");

  return 0;
}
