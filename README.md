## Corewar

Compilateur d'ASM et Machine virtuelle

### ASM

Le compilateur d'ASM permet de créer de du code machine compatible avec la machine virtuelle.

### Machine virtuelle

La machine virtuelle permet de confronter 4 programmes donnés en paramètre.

#### Interface graphique

Pour avoir l'interface 3D de la machine virtuelle, vous devez avoir les libraires
 * CGLM [GitHub](https://github.com/recp/cglm)
 * OpenGL
 * CSFML

Vous devez ensuite compiler le Corewar avec
> make -C ./corewar bonus

Vous devez être dans à la racine du projet pour lancer l'interface

Contrôles:
 * Q / D : Rotation
 * Z / S : Hauteur
 * A / E : Gauche / Droite
 * Molette : Zoom