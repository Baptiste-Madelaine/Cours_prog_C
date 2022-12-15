#include <stdio.h>
#include <stdlib.h>
#include "pgm.h"

struct imagePGM negatif(struct imagePGM image){
   struct imagePGM neg = allouer_image_vide_PGM(image.nbl,  image.nbc, image.nbNiveau);
    for(int l=0; l< image.nbl ; l++){
	for(int c = 0; c < image.nbc; c++){
	    struct pixelRVB pix = getPixel(image, l, c);
	    pix.r = image.nbNiveau - pix.r;
	    putPixel(&neg, pix, l, c);
	}
    }
    return neg;
}

int main()
{
    struct imagePGM im;
    struct imagePGM imResultat;
    im=lire_image_PGM("FleurRVB.ppm");

    imResultat = negatif(im);
    ecrire_image_PGM(imResultat, "negatif.pgm");   
    detruire_image(im);
    return 0;
}
