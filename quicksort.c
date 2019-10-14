#include <stdio.h>

void troca(int vetor[], int el1, int el2) {
  int intermedio;
  intermedio = vetor[el1];
  vetor[el1] = vetor[el2];
  vetor[el2] = intermedio;
}

int particao1(int vetor[], int inicial, int final) {
  int pivot = vetor[final];
  int cMn = -1, cEl;
  for (cEl = 0; cEl < final - inicial; cEl++) {
    if (vetor[inicial+cEl] < pivot) {
      cMn++;
      troca(vetor, inicial+cEl, inicial+cMn);
    }
  }
  troca(vetor, inicial+cMn, final);
  return cMn;
}

/*
int particao2(int *inicial, int *final) {

}
*/

void quicksort(int vetor[], int inicial, int final) {
  int inc=inicial;
  int fim=final;
  if (inicial < final) {
    int pscPiv = particao1(vetor,inc, fim);
    quicksort(vetor, inicial, inicial+pscPiv);
    quicksort(vetor, inicial+pscPiv+2, final);
    
  }
}

int main() {
  int n_valores;
  int c1 = 0;
  printf("Escolha o numero de valores\n");
  scanf("%d", &n_valores);
  int vetor[n_valores];
  while (c1 < n_valores) {
    scanf("%d", &vetor[c1]);
    c1++;
  }
  c1 = 0;
  quicksort(vetor, 0, n_valores-1);
  while (c1 < n_valores) {
    printf("%d ", vetor[c1]);
    c1++;
  }
  printf("\n");
  return 0;
}
