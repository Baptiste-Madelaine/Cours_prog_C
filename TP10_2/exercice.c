
#include "ppm.h"
#include <stdio.h>
void rectangle_gris(struct imagePPM *image){
   for(int i = image->nbl/2 - 15; i< image->nbl/2 +15; i++){
    for(int t = image->nbc * 1/6; t < image->nbc * 5/6; t++){
        struct pixelRVB pix = {127,127,127};
        putPixel(image, pix, i,t);
        
    }
   }
}
struct imagePPM degrade(){
    struct imagePPM deg = allouer_image_vide_PPM(300, 500, 255);
    struct pixelRVB pix;
    for(int l = 0; l<deg.nbl; l++){
        for(int c = 0; c<deg.nbc; c++){
            pix.r = pix.v = pix.b = 255 * (deg.nbc - c)/deg.nbc;
            putPixel(&deg, pix, l, c);
        }
    }
    return deg;
}

void eclaircir_ligne(struct imagePPM *img, int ligne){
    struct pixelRVB pix;
    for(int i = 0; i< img->nbc; i++){
        if(128 + getPixel(*img,ligne, i).r>255){
            pix.r = 255;
        }
        else{
            pix.r = getPixel(*img,ligne, i).r + 128;
        }
        if(getPixel(*img,ligne, i).v + 128>255){
            pix.v = 255;
        }
        else{
            pix.v = getPixel(*img,ligne, i).v + 128;
        }
        if(getPixel(*img,ligne, i).b + 128>255){
            pix.b = 255;
        }
        else{
            pix.b = getPixel(*img,ligne, i).b + 128;
        }
        putPixel(img, pix, ligne, i);
    }
}
void eclaircir_colonne(struct imagePPM *img, int colonne){
    struct pixelRVB pix;
    for(int i = 0; i< img->nbl; i++){
        if(128 + getPixel(*img,i, colonne).r>255){
            pix.r = 255;
        }
        else{
            pix.r = getPixel(*img,i, colonne).r + 128;
        }
        if(getPixel(*img,i, colonne).v + 128>255){
            pix.v = 255;
        }
        else{
            pix.v = getPixel(*img,i, colonne).v + 128;
        }
        if(getPixel(*img,i, colonne).b + 128>255){
            pix.b = 255;
        }
        else{
            pix.b = getPixel(*img,i, colonne).b + 128;
        }
        putPixel(img, pix, i, colonne);
    }
}

struct imagePPM cadri(){
    struct imagePPM deg = allouer_image_vide_PPM(360,590, 255);
    struct pixelRVB pix;
    for(int l = 0; l < deg.nbl; l++){
        for(int c = 0; c < deg.nbc; c++){
            pix.r = pix.v = pix.b = 0;
            putPixel(&deg, pix, l, c);
        }
    }
    for(int i = 10; i < deg.nbl+10; i++){
        if(i%60<10){
            eclaircir_ligne(&deg, i-10);
        }
    }
    for(int k = 10; k < deg.nbc+10; k++){
        if(k%60 < 10 ){
            eclaircir_colonne(&deg, k-10);
        }
    }
    return deg;
}

/*struct imagePPM filte_rouge(struct imagePPM image){
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
}*/


int main(){
    /*struct imagePPM im;
    im=lire_image_PPM("FleurRVB.ppm");
    struct imagePPM im_gris = niv_gris(im);
    rectangle(&im, 1, 1, 500, 500, 10);
    ecrire_image_PPM(im, "rec.ppm");
    ecrire_image_PPM(im_gris, "niv_gris.ppm");
    detruire_image(im);
     */
    struct imagePPM im;
    im=degrade();
    eclaircir_ligne(&im, 5);
    eclaircir_colonne(&im, 255);
    rectangle_gris(&im);
    struct imagePPM im2 = cadri();
    ecrire_image_PPM(im2, "non.PPM");
    ecrire_image_PPM(im, "oui.PPM");
    detruire_image(im);
    detruire_image(im2);
    return 0;
}