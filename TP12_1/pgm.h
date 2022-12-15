#ifndef __PGMPGM_PGM
#define __PGMPGM_PGM

struct pixelRVB{
    unsigned char r;
    // on met un octet de plus, dit "de padding" pour remplir
    // la structure et avoir une structure de 4 octets qui s'aligne bien en mémoire
    // et permet de meilleures performances.
    // Souvent, les compilateurs font ce remplissage automatiquement.
};

struct imagePGM {
    int nbl; // nombre de lignes de l'image
    int nbc;  // nombre de colonnes de l'image
    int nbNiveau; // nombre de niveaux par pixel (qualité des couleurs)
    struct pixelRVB *img; // un pointeur sur un tableau de pixels
};

/**
 * @brief Ouvre le fichier du nom indiqué en mémoire, le stocke dans la structure de donnée adaptée.
 * @param nom nom du fichier à ouvrir
 * @return une struct imagePGM contenant l'image
 **/
struct imagePGM  lire_image_PGM(char nom[]);

/**
 * récupère le pixel à la position donnée.
 * @param img l'image à lire
 * @param ligne numéro de ligne à consulter
 * @param col numéro de colonne à consulter
 * @return le pixel consulté
 */
struct pixelRVB getPixel(struct imagePGM img, int ligne, int col);

/**
 * affecte le pixel fourni à la position donnée.
 * @param p_img l'adresse de l'image à lire
 * @param pix le pixel à positionner
 * @param ligne numéro de ligne à consulter
 * @param col numéro de colonne à consulter
 */
void putPixel(struct imagePGM *p_img, struct pixelRVB pix, int ligne, int col);

/**
 * @brief enregistre la struct image en paramètre dans le fichier nommé *nom*
 * Si un tel fichier existe déjà, il est écrasé.
 * @param imagePGM une image dans la structure ci-dessus
 * @param nom le nom du ficher dans lequel l'image doit être sauvegardée.
 **/
void  ecrire_image_PGM(struct imagePGM im, char nom[]);

/**
 * @brief crée une image vide
 * @param nb_lignes nombre de lignes de l'image créée (e.g. 384)
 * @param nb_colonnes nombre de colonne de l'image créée (e.g. 512)
 * @param nb_niveaux nombre de nuances de chaque couleur (typiquement 256)
 **/
struct imagePGM allouer_image_vide_PGM(int nb_lignes, int nb_colonnes, int nb_niveaux);

/**
 * Libère la mémoire réservée à la création de l'image
 **/
void detruire_image(struct imagePGM image);

#endif
