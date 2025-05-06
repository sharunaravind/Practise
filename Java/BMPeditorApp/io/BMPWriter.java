package io;

import Models.Pixel;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
// Assuming your Pixel class is defined elsewhere or as a nested class

public class BMPWriter { // Or add this method to your BMPReader class

    /**
     * Saves the pixel data to a new BMP file using ImageIO.
     *
     * @param pixelGrid The 2D array of Pixel objects holding the image data.
     * @param width     The width of the image to save.
     * @param height    The height of the image to save.
     * @param outputFilePath The path for the new BMP file (e.g., "output.bmp").
     * @return true if saving was successful, false otherwise.
     */
    public static boolean saveBMP(Pixel[][] pixelGrid, int width, int height, String outputFilePath) {
        System.out.println("Preparing to save image to: " + outputFilePath);
        width=width-50;
        if (pixelGrid == null || width <= 0 || height <= 0) {
            System.err.println("Error: Invalid pixel data or dimensions for saving.");
            return false;
        }

        // 1. Create a BufferedImage
        // TYPE_INT_RGB stores pixels as standard 32-bit integer RGB values (Alpha ignored).
        // TYPE_3BYTE_BGR might be slightly more direct for BMP, but TYPE_INT_RGB with setRGB is often simpler.
        BufferedImage imageToSave = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);

        // 2. Copy data from your Pixel grid to the BufferedImage
        System.out.println("Copying pixel data to BufferedImage...");
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (pixelGrid[y][x] == null) {
                    System.err.println("Warning: Null pixel found at (" + x + ", " + y + "). Setting to black.");
                    imageToSave.setRGB(x, y, 0); // Set to black (0x000000)
                    continue;
                }
                Pixel p = pixelGrid[height-1-y][x];

                // Combine your R, G, B ints into a single packed integer for setRGB.
                // Alpha is effectively ignored for TYPE_INT_RGB, or assumed 255 (opaque).
                // Format: 0xAARRGGBB (Alpha, Red, Green, Blue)
                int rgb = (p.red << 16) | (p.green << 8) | p.blue;
                // The alpha component defaults to 255 (opaque) here: (255 << 24) | (p.red << 16) | (p.green << 8) | p.blue;

                // setRGB(x, y, rgb) uses standard image coordinates (y=0 is top row)
                imageToSave.setRGB(x, y, rgb);
            }
        }
        System.out.println("Pixel data copied.");

        // 3. Write the BufferedImage to a file using ImageIO
        try {
            File outputFile = new File(outputFilePath);
            System.out.println("Writing BMP file...");
            boolean success = ImageIO.write(imageToSave, "BMP", outputFile); // Specify "BMP" format

            if (success) {
                System.out.println("Image successfully saved to " + outputFilePath);
                return true;
            } else {
                System.err.println("Error: ImageIO failed to write BMP file. No suitable writer found?");
                return false;
            }
        } catch (IOException e) {
            System.err.println("Error writing file: " + e.getMessage());
            e.printStackTrace();
            return false;
        }
    }

    // --- You would call this method from your main ---
    // Example usage in main (after loading and editing):
    /*
    Pixel[][] editedPixels = ... // Your potentially rotated or grayscaled grid
    int finalWidth = ... // Width of editedPixels
    int finalHeight = ... // Height of editedPixels
    String outputPath = "edited_image.bmp";

    boolean saved = saveBMP(editedPixels, finalWidth, finalHeight, outputPath);
    if (saved) {
        System.out.println("To view the image, open the file: " + outputPath);
    }
    */
}