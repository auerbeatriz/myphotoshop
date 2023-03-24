#ifndef PARSER_H
#define PARSER_H

struct pgm_image {
    // width: n colunas
    // height: n linhas
    // imgmx: final image matrix
    
    int width;
    int height;
    int max_gray_level;
    int** imgmx;
};

#endif