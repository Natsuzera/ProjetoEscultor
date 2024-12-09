#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <string>

// Estrutura para representar um voxel
struct Voxel {
    float r, g, b;  // Cores (vermelho, verde, azul)
    float a;        // Transparência (alpha)
    bool isOn;      // Voxel ativo ou inativo
};

// Classe principal para manipular a matriz 3D
class Sculptor {
private:
    Voxel ***v;     // Matriz 3D de voxels
    int nx, ny, nz; // Dimensões da matriz
    float r, g, b, a; // Cor atual
public:
    // Construtor e destrutor
    Sculptor(int _nx, int _ny, int _nz);
    ~Sculptor();

    // Define a cor atual
    void setColor(float r, float g, float b, float alpha);

    // Ativa/desativa voxels
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);

    // Manipulação de caixas (retângulos)
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

    // Manipulação de esferas
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

    // Manipulação de elipsoides
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    // Exporta a matriz para um arquivo OFF
    void writeOFF(const char* filename);
};

#endif // SCULPTOR_H
