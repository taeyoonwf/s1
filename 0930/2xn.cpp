#include <stdio.h>
#define MAX 1000
long long arr[MAX+1];
int sizeN;
int main() {
  int i;
  arr[1] = 1; arr[2] = 2;
  scanf("%d", &sizeN);
  if (sizeN>2) {
    for (i=3; i<=sizeN; i++) {
      arr[i] = arr[i-1] + arr[i-2];
    } 
  }
  printf("%d\n", arr[sizeN]%10007);
  return 0;
}
