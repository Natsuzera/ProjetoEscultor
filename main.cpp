#include "Sculptor.h"

int main() {
    // Cria um objeto Sculptor com dimensões adequadas
    Sculptor sculptor(80, 80, 80);

    // Eixos coordenados
    
    sculptor.setColor(1.0, 0.0, 0.0, 1.0); // Eixo X (vermelho) LARGURA
    sculptor.putBox(0, 45, 0, 1, 0, 1);
    sculptor.setColor(0.0, 1.0, 0.0, 1.0); // Eixo Y (verde) ALTURA
    sculptor.putBox(0, 1, 0, 45, 0, 1);
    sculptor.setColor(0.0, 0.0, 1.0, 1.0); // Eixo Z (azul) PROFUNDIDADE
    sculptor.putBox(0, 1, 0, 1, 0, 45);
    sculptor.putVoxel(25, 25, 25);
    

    // Define as cores normalizadas
    float colors[3][3] = {
        {0.7608, 0.6980, 0.5020}, // intermediária (areia original)
        {1.0, 0.9210, 0.6626}, // Cor mais clara
        {0.4869, 0.4464, 0.3213}  // Cor mais escura
    };

    // Defina as transparências para cada camada
    float alphas[3] = {1.0, 1.0, 1.0};

    // Define os raios externos das elipsoides por camada
    int radii[3][4] = {
        {40, 39, 38, 37}, // Para a cor mais clara
        {36, 35, 34, 31}, // Para a cor intermediária
        {29, 28, 27, 26}  // Para a cor mais escura
    };

    // Loop pelas camadas de cores
    for (int i = 0; i < 3; i++) {
        sculptor.setColor(colors[i][0], colors[i][1], colors[i][2], alphas[i]);
        for (int j = 0; j < 3; j++) {
            sculptor.putEllipsoid(40, 40, 40, radii[i][j], 1, radii[i][j]);
        }
        sculptor.cutEllipsoid(40, 40, 40, radii[i][3], 1, radii[i][3]);
    }


    sculptor.setColor(0.7608, 0.6980, 0.5020, 1.0);
    sculptor.putSphere(40, 40, 40, 22);
    sculptor.setColor(0.6086, 0.5580, 0.4016, 1.0);
    sculptor.putEllipsoid(40, 40, 40, 22, 15, 22);
    sculptor.cutEllipsoid(40, 40, 40, 21, 15, 21);

    sculptor.setColor(0.1569, 0.4314, 0.3922, 1.0);
    sculptor.putEllipsoid(40, 61, 40, 6, 1, 6);
    sculptor.cutVoxel(40, 62, 40);


    sculptor.cutSphere(40, 40, 40, 21);
    // Salva a escultura em um arquivo OFF
    sculptor.writeOFF("minecraft_character_axes.off");

    return 0;
}

