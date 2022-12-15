
#include "pgm.h"
#include <stdio.h>

struct imagePGM niv_gris(struct imagePGM image){
   struct imagePGM rouge = allouer_image_vide_PGM(image.nbl,  image.nbc, image.nbNiveau);
    for(int l=0; l< image.nbl ; l++){
	for(int c = 0; c < image.nbc; c++){
	    struct pixelRVB pix = getPixel(image, l, c);
        int x = pix.r*0.3 + 0.59;
        pix.r = image.nbNiveau - pix.r;

	        //pix.v = x;
	        //pix.b = x;
	    putPixel(&rouge, pix, l, c);
	}
    }
    return rouge;
}
/*
void rectangle(struct imagePGM *image, int l1, int c1, int l2, int c2, int epaisseur){
    for(int l = 0; l< image->nbl ; l++){
        for(int c = 0; c < image->nbc; c++){
            struct pixelRVB pix = getPixel(*image, l, c);
            
            if(c>c1 && c<c2 && l>l1 && l<l2){
                pix.r = 255;
                pix.v = 255;
                pix.b = 255;
                putPixel(image, pix, l, c);
            }

            if((c>=c1 && c- epaisseur<=c2 && (( l >= l1 && l <= l1+epaisseur ) || ( l>=l2 && l<= l2+epaisseur)))||(l>=l1 && l<=l2 && (( c >= c1 && c <= c1+epaisseur ) || ( c>=c2 && c<= c2+epaisseur)))){
                pix.r = 0;
                pix.v = 0;
                pix.b = 0;
                putPixel(image, pix, l,c);
            }
            
            
        }
    }
}
*/


int main(){
    struct imagePGM im;
    im = lire_image_PGM("img.pgm");
    
    
    ecrire_image_PGM(niv_gris(im), "niv_gris.pgm");
    /*
    
    im=lire_image_PGM("FleurRVB.pgm");
    struct imagePGM im_gris = niv_gris(im);
    rectangle(&im, 1, 1, 500, 500, 10);
    ecrire_image_PGM(im, "rec.pgm");
    ecrire_image_PGM(im_gris, "niv_gris.pgm");
    detruire_image(im);
     */
    /*struct imagePGM im;
    eclaircir_ligne(&im, 5);
    eclaircir_colonne(&im, 255);
    rectangle_gris(&im);
    ecrire_image_PGM(im2, "non.PGM");
    ecrire_image_PGM(im, "oui.PGM");
    detruire_image(im);
    detruire_image(im2);
    
    */
    return 0;
}