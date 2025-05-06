package io;

import Models.BmpHeader;
import Models.BmpImage;
import Models.Pixel;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class BmpWriter {
    public static void write(String outputFilePath, BmpImage image) throws IOException
    {
         if (image == null || image.header == null || image.pixelGrid == null) {
            throw new IllegalArgumentException("BmpImage or its components cannot be null.");
        }
        BmpHeader header = image.header;
        Pixel[][] pixelGrid = image.pixelGrid;
        int height = header.height;
        int width = header.width;
        if(header.bitsPerPixel!=24)
        {
            throw new IllegalArgumentException("Image is not 24 bit. cant write");
        }
        try(OutputStream os = new FileOutputStream(outputFilePath))
        {


            os.write((byte) 'B'); // Signature part 1
            os.write((byte) 'M'); // Signature part 2
            writeDword(os, header.fileSize);
            writeWord(os, header.reserved1);
            writeWord(os, header.reserved2);
            writeDword(os, header.pixelOffset);

            writeDword(os, header.headerSize);
            writeDword(os, header.width);
            writeDword(os, header.height);
            writeWord(os, header.planes);
            writeWord(os, header.bitsPerPixel);
            writeDword(os, header.compression);
            writeDword(os, header.imageSize);
            writeDword(os, header.xPixelsPerMeter);
            writeDword(os, header.yPixelsPerMeter);
            writeDword(os, header.colorsInColorTable);
            writeDword(os, header.importantColors);

            int rowSize = width * 3;
            int padding = (4 - (rowSize % 4)) % 4;

            for (int y = 0; y < height; y++) {
                // Write pixels for the current row
                for (int x = 0; x < width; x++) {
                    Pixel p = pixelGrid[y][x];
                    if (p == null) {
                        System.out.println("woawww why are pixels null??");
                       os.write(0); os.write(0); os.write(0); // Write black
                    }
                    else {
                       // Write in BGR order
                       os.write(p.blue);
                       os.write(p.green);
                       os.write(p.red);
                    }
                }

                for (int p = 0; p < padding; p++) {
                    os.write(0);
                }
            }
            System.out.println("Pixel data written.");
        }
        System.out.println("BMP file writing complete for: " + outputFilePath);
    }
    public static void writeWord(OutputStream os,int value) throws IOException
    {
        os.write(value & 0xFF);
        os.write((value >> 8) & 0xFF);
    }
    public static void writeDword(OutputStream os, int value) throws IOException {

        os.write(value & 0xFF);
        os.write((value >> 8) & 0xFF);
        os.write((value >> 16) & 0xFF);
        os.write((value >> 24) & 0xFF);
    }
}
