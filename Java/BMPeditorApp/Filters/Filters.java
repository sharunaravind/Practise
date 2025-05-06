package Filters;

import Models.BmpImage;
import Models.Pixel;

public class Filters {
    public void greyScale(BmpImage image)
    {
        int height = image.header.height;
        int width = image.header.width;
        Pixel[][] pixelgrid = image.pixelGrid;
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++) {

                Pixel p = pixelgrid[i][j];
                int gray = (int) (0.299 * p.red + 0.587 * p.green + 0.114 * p.blue);
                p.red=gray;
                p.blue=gray;
                p.green=gray;
            }
        }
        System.out.println("greyscale applied successfully");
    }
}
