package io;

import Models.BmpHeader;
import Models.BmpImage;
import Models.Pixel;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;

public class BmpReader {
    public static int count = 0;

    public static BmpImage read(String filePath) throws IOException
    {
       try(InputStream iostream = new FileInputStream(filePath))
       {
           BmpHeader header = ReadHeader(iostream); //first read the header
           BmpImage image = new BmpImage(header,header.width,header.height); //creating new Image object
           int BytestoSkip = header.pixelOffset-54;
           long skipped = iostream.skip(BytestoSkip);
           if(skipped != BytestoSkip) throw new IOException("Error with skipping for reading pixel grid");
           ReadImage(iostream,image);
           return image;
       }
    }

    private static BmpHeader ReadHeader(InputStream iostream)
    {
        BmpHeader header = new BmpHeader();
        try{
            header.sigB=iostream.read();
            header.sigM= iostream.read();
            if(header.sigB != 'B' || header.sigM != 'M')
            {
                throw new IOException("Signature is wrong. pleaseo checko");
            }
            header.fileSize=readDword(iostream);
            header.reserved1=readword(iostream);
            header.reserved2=readword(iostream);
            header.pixelOffset=readDword(iostream);
            header.headerSize=readDword(iostream);
            header.width=readDword(iostream);
            header.height=readDword(iostream);
            header.planes=readword(iostream);
            header.bitsPerPixel=readword(iostream);
            header.compression=readDword(iostream);
            header.imageSize=readDword(iostream);
            header.xPixelsPerMeter=readDword(iostream);
            header.yPixelsPerMeter=readDword(iostream);
            header.colorsInColorTable=readDword(iostream);
            header.importantColors=readDword(iostream);
            return header;
        }

        catch (IOException e)
        {
            System.out.println("something went wrong in reading the header. plso checko");
            System.out.println(e.getMessage());
            System.out.println(Arrays.toString(e.getStackTrace()));
        }
        return null;
    }

    private static void ReadImage(InputStream iostream, BmpImage image)
    {
        int height = Math.abs(image.header.height);
        int width = image.header.width;
        boolean isBottomUp = image.header.height>0;
        int rowSize = width*3;
        int padding = (4-(rowSize%4) % 4);
        try
        {
            if(image.header.bitsPerPixel==24)
            {
                for(int i=0;i<height;i++)
                {
                    for(int j=0;j<width;j++)
                    {
                        int blue = iostream.read();
                        int green = iostream.read();
                        int red = iostream.read();
                        if (blue == -1 || green == -1 || red == -1) {
                            throw new IOException("Unexpected EOF while reading pixel data at row " + i + ", col " + j);
                        }
                        image.pixelGrid[i][j] = new Pixel(red,green,blue);
                    }

                    if(padding>0)
                    {
                        long skipped = iostream.skip(padding);
                        if(skipped!=padding)
                        {
                            throw new IOException("Woaw count skip the padding amount");
                        }
                    }
                }
                System.out.println("all values read. Great success");
            }
        }
        catch (IOException e)
        {
            System.out.println("something wrong while reading pixel grid. Stack trace not printed print that if u face this error");
        }
    }

    private static int readword(InputStream is) throws IOException {
        int byte1 = is.read();
        int byte2 = is.read();
        count+=2;
        if(byte1==-1 || byte2 ==-1)
        {
            throw new IOException("woaw eof while reading little endiand word bro");
        }
        return (byte1 & 0b11111111) | ((byte2 & 0b11111111) << 8);
    }

    private static int readDword(InputStream is) throws IOException {
        int byte1 = is.read();
        int byte2 = is.read();
        int byte3 = is.read();
        int byte4 = is.read();
        count+=4;
        if (byte1 == -1 || byte2 == -1 || byte3 == -1 || byte4 == -1) {
            throw new IOException("EOF while reading DWORD");
        }
        return (byte1 & 0xFF) |
                ((byte2 & 0xFF) << 8) |
                ((byte3 & 0xFF) << 16) |
                ((byte4 & 0xFF) << 24);

    }
}



