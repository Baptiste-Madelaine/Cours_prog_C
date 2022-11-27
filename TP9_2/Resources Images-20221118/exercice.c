#include <stdio.h>
#include "ppm.h"

struct imagePPM filte_rouge(struct imagePPM image){
   struct imagePPM rouge = allouer_image_vide_PPM(image.nbl,  image.nbc, image.nbNiveau);
    for(int l=0; l< image.nbl ; l++){
	for(int c = 0; c < image.nbc; c++){
	    struct pixelRVB pix = getPixel(image, l, c);
	    pix.v = 0;
	    pix.b = 0;
	    putPixel(&rouge, pix, l, c);
	}
    }
    return rouge;
}
struct imagePPM niv_gris(struct imagePPM image){
   struct imagePPM rouge = allouer_image_vide_PPM(image.nbl,  image.nbc, image.nbNiveau);
    for(int l=0; l< image.nbl ; l++){
	for(int c = 0; c < image.nbc; c++){
	    struct pixelRVB pix = getPixel(image, l, c);
        int x = pix.r*0.3 + 0.59 * pix.v + pix.b* 0.11;
        pix.r = x;
	    pix.v = x;
	    pix.b = x;
	    putPixel(&rouge, pix, l, c);
	}
    }
    return rouge;
}
void rectangle(struct imagePPM *image, int l1, int c1, int l2, int c2, int epaisseur){
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


int main(){
    struct imagePPM im;
    im=lire_image_PPM("FleurRVB.ppm");
    struct imagePPM im_gris = niv_gris(im);
    rectangle(&im, 1, 1, 500, 500, 10);
    ecrire_image_PPM(im, "rec.ppm");
    ecrire_image_PPM(im_gris, "niv_gris.ppm");
    detruire_image(im);
    return 0;
}