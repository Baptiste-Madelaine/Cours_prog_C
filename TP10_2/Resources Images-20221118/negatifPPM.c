#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"

struct imagePPM negatif(struct imagePPM image){
   struct imagePPM neg = allouer_image_vide_PPM(image.nbl,  image.nbc, image.nbNiveau);
    for(int l=0; l< image.nbl ; l++){
	for(int c = 0; c < image.nbc; c++){
	    struct pixelRVB pix = getPixel(image, l, c);
	    pix.r = image.nbNiveau - pix.r;
	    pix.v = image.nbNiveau - pix.v;
	    pix.b = image.nbNiveau - pix.b;
	    putPixel(&neg, pix, l, c);
	}
    }
    return neg;
}

int main()
{
    struct imagePPM im;
    struct imagePPM imResultat;
    im=lire_image_PPM("FleurRVB.ppm");

    imResultat = negatif(im);
    ecrire_image_PPM(imResultat, "negatif.ppm");   
    detruire_image(im);
    return 0;
}
