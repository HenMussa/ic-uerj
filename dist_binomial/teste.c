#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *gp = popen("gnuplot -persistent", "w");
    
    fprintf(gp, "set title 'Gráfico de sen(x)'\n");
    fprintf(gp, "set xlabel 'x'\n");
    fprintf(gp, "set ylabel 'sen(x)'\n");
    fprintf(gp, "plot '-' with lines title 'sen(x)'\n");
    
    // Enviar dados diretamente
    for (double x = 0; x <= 10; x += 0.1) {
        fprintf(gp, "%f %f\n", x, x*x);
    }
    fprintf(gp, "e\n");  // Indica fim dos dados
    
    pclose(gp);
    return 0;
}