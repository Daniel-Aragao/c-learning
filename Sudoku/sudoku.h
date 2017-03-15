#define true 1
#define false 0

void resetarMatriz(int m[9][9]);

int validarOcupacao(int m[9][9], int i, int j);

int validarQuadrante(int tab[9][9], int i, int j, int num);

int validarHorizontal(int m[9], int num);

int validarVertical(int m[9][9], int j, int num);

void printMatriz(int m[9][9]);
