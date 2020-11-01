/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */
    // if (theSource.getColumns()== 0 || theSource.getRows() == 0 || theTiles.size() == 0)
    //     return NULL; this is already assumed
    int x = theSource.getRows();
    int y = theSource.getColumns();
    MosaicCanvas *canvas = new MosaicCanvas(x, y);
    vector <Point<3>>  average(theTiles.size());
    map <Point<3>, int> themap;
    // use theTiles.getAverageColor()? , confused about the color conversion, use convertToXYZ as well? map class?
    //"place that TileImage into the MosaicCanvas in the same tile position as the SourceImage’s region." - is that not already assumed? 
    for (unsigned long v = 0; v < theTiles.size(); v++){ // go through every region
        average[v] = convertToXYZ(theTiles[v].getAverageColor());
        themap[average[v]] = v;
    }
    // using kdtree to find nearest neighbor in order to determine the average color? -- build a kdtree from a vector of average colors per region?
    KDTree<3> thetree(average);

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            // use findnearestneightbor here and set to the average color to various pixels
            Point<3> z = thetree.findNearestNeighbor(convertToXYZ(theSource.getRegionColor(i, j)));
            // if (z != NULL) // this was segfaulting for some reason, but no faulty inputs
            canvas->setTile(i, j, &theTiles[themap[z]]);
        }
    }
    return canvas;
}

