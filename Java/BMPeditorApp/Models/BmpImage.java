package Models;

public class BmpImage {
    //has both header and the pixelGrid
    public BmpHeader header;
    public Pixel[][] pixelGrid;

    public BmpImage(BmpHeader header,int width, int height)
    {
        this.header=header;
        this.pixelGrid = new Pixel[height][width];
    }
}
