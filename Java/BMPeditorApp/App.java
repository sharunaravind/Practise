import Models.Pixel;
import io.*;
import Models.BmpHeader;
import Models.BmpImage;
import Filters.*;

import java.io.IOException;

public class App {
    public static void main(String[] args) {
        try{
            BmpImage img1 = BmpReader.read("/home/sharun/Documents/Practise/Java/image/test.bmp");
            System.out.println(img1.header);
            System.out.println(BmpReader.count);
            img1.header.headerSize=40;
            img1.header.pixelOffset=54;
            int finalHeight = img1.pixelGrid.length;
            int finalWidth = img1.pixelGrid[0].length;
            img1.header.width = finalWidth;
            img1.header.height = finalHeight;
            int rowDataSize = finalWidth * 3; // 3 bytes per pixel for 24-bit
            int padding = (4 - (rowDataSize % 4)) % 4;
            int stride = rowDataSize + padding;
            img1.header.imageSize = stride * finalHeight;
            img1.header.fileSize = 54 + img1.header.imageSize;
//             try
//             {
//                 BmpWriter.write("output_manual.bmp", img1);
//             }
//             catch (IOException e)
//             {
//                System.err.println("Failed to write BMP file: " + e.getMessage());
//                e.printStackTrace();
//             }
            Models.Pixel[][] newgrid=img1.pixelGrid;
//            BMPWriter.saveBMP(,img1.header.width,img1.header.height,"PleaseWork.bmp");
        }
        catch (IOException e)
        {
            System.out.println("error from reading the image in main");
        }
    }
}
