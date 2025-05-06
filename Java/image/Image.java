import java.util.*;
import java.io.*;
public class Image {
    public static void main(String[] args) throws IOException {
        String filename = "image/test.bmp";
        intRef count = new intRef(0);
        File bmpImage = new File(filename);
        try(InputStream inputStream = new FileInputStream(bmpImage)) {
            int sigB = inputStream.read();
            int sigM = inputStream.read();
            if(sigB != 'B' || sigM != 'M')
            {
                return;
            }
            int fileSize = readDword(inputStream,count);
            System.out.printf("File size = %d\n",fileSize);
            int reserver1 = readword(inputStream,count);
            int reserver2 = readword(inputStream,count);
            System.out.printf("reversed 1 = %d, reserved 2 = %d\n",reserver1,reserver2);
            int ArrayOffset = readDword(inputStream,count);
            System.out.printf("The offset position of array is %d\n",ArrayOffset);
            int DIBheaderSize = readDword(inputStream,count);
            System.out.printf("Header Info size is %d\n",DIBheaderSize);
            int width = readDword(inputStream,count);
            int height = readDword(inputStream,count);
            System.out.printf("Height = %d and width = %d\n",height,width);
            int planes = readword(inputStream,count);
            int BitsPerPixel = readword(inputStream,count);
            int compression = readDword(inputStream,count);
            System.out.printf("Bits per pixed = %d\n",BitsPerPixel);
            System.out.printf("Planes = %d\n",planes);
            System.out.printf("Compression = %d\n",compression);
            int imageSize = readDword(inputStream,count);
            System.out.printf("Image size = %d\n",imageSize);
            System.out.println(count.count);
            count.count+=2;
            int BytesToskip = ArrayOffset-count.count;
            long result = inputStream.skip(BytesToskip);
            System.out.printf("The bytes that are skipped are %d\n",result);
            int rowSize = width*3;
            int padding = (4-(rowSize%4)) % 4;
            int rowStride = rowSize + padding;
            Pixel[][] pixelGrid = new Pixel[height][width];
            if(BitsPerPixel==24)
            {
                for(int i=0;i<height;i++)
                {
                    for(int j=0;j<width;j++)
                    {
                        int blue = inputStream.read();
                        int green = inputStream.read();
                        int red = inputStream.read();
                        if (blue == -1 || green == -1 || red == -1) {
                            throw new IOException("Unexpected EOF while reading pixel data at row " + i + ", col " + j);
                        }
                        pixelGrid[i][j] = new Pixel(red, green, blue);
                    }
                    if(padding>0)
                    {
                        long skipped = inputStream.skip(padding);
                        if(skipped!=padding)
                        {
                            throw new IOException("Woaw count skip the padding amount");
                        }
                    }
                }
                System.out.println("all values read. Great success");
            }
            Filter(pixelGrid,height,width);
            BMPWriter.saveBMP(pixelGrid,width,height,"image/editedImageRed.bmp");
            inputStream.close();
        }
        catch (IOException e)
        {
            System.err.print("Error during header read pls check"+ e.getMessage());
            e.printStackTrace();
        }
    }

    private static int readword(InputStream is,intRef count) throws IOException {
        int byte1 = is.read();
        int byte2 = is.read();
        count.count+=2;

        if(byte1==-1 || byte2 ==-1)
        {
            throw new IOException("woaw eof while reading little endiand word bro");
        }
        return (byte1 & 0b11111111) | ((byte2 & 0b11111111) << 8);
    }

    private static int readDword(InputStream is,intRef count) throws IOException {
        int byte1 = is.read();
        int byte2 = is.read();
        int byte3 = is.read();
        int byte4 = is.read();
        count.count+=4;
        if (byte1 == -1 || byte2 == -1 || byte3 == -1 || byte4 == -1) {
            throw new IOException("EOF while reading DWORD");
        }
        return (byte1 & 0xFF) |
                ((byte2 & 0xFF) << 8) |
                ((byte3 & 0xFF) << 16) |
                ((byte4 & 0xFF) << 24);

    }

    private static int readSignedLong(InputStream is,intRef count) throws IOException {
        int dwordValue = readDword(is,count);
        return dwordValue;
    }
    private static void Greyscale(Pixel[][] pixelgrid,int height,int width) {
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

    }
    private static void Filter(Pixel[][] pixelgrid,int height,int width) {
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++) {

                Pixel p = pixelgrid[i][j];
                int gray = (int) (0.299 * p.red + 0.587 * p.green + 0.114 * p.blue);
                int amount=40;
                if(p.red+amount<255)
                {
                    p.red+=amount;
                }
                else p.red=255;
//                p.blue=gray;
//                p.green=gray;
            }
        }

    }

    private static void Createnewimage(Pixel[][] pixelgrid,int height,int width,String filename,int pixelOffset,File file)
    {
        try(InputStream iostream = new FileInputStream(file))
        {

        }
        catch (IOException e)
        {

        }
    }
}

class Pixel {
    int red;
    int green;
    int blue;

    public Pixel(int r, int g, int b) {
        this.red = r;
        this.green = g;
        this.blue = b;
    }

    public String toString() {
        return "Pixel(R=" + red + ", G=" + green + ", B=" + blue + ")";
    }
}

class intRef{
    int count;
    intRef(int value)
    {
        this.count=value;
    }
}
