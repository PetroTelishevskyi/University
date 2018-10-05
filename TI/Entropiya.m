 pkg load image;
 Image = imread('E:\ImagesTI\image.jpg');
 
 [height,width] = size(Image);
 Square = height*width;
 disp("Total pixels: "),disp(Square);
 
 figure,imhist(Image,16);
 [counts, X] = imhist(Image);
 X = counts./Square;
 Entropy = -sum(X.*log2(X));
 E = entropy(Image);
 disp("Entropy according to formula 2.1 (jpeg): "), disp(Entropy); 
 disp("Entropy of the built-in function (jpeg): "), disp(E);
 
 Image1 = imread('E:\ImagesTI\image1.bmp');
 [height,width] = size(Image1);
 Square = height*width;
 [counts, X] = imhist(Image1);
 X = counts./Square;
 Entropy = -sum(X.*log2(X));
 E1 = entropy(Image1);
 disp("Entropy according to formula 2.1 (bmp): "), disp(Entropy); 
 disp("Entropy(bmp): "), disp(E1);
 
 Image2 = imread('E:\ImagesTI\image2.png');
 [height,width] = size(Image2);
 Square = height*width;
 [counts, X] = imhist(Image2);
 X = counts./Square;
 Entropy = -sum(X.*log2(X));
 E2 = entropy(Image2);
 disp("Entropy according to formula 2.1 (png): "), disp(Entropy); 
 disp("Entropy(png): "), disp(E2);
 
 Image3 = imread('E:\ImagesTI\image3.tiff');
 [height,width] = size(Image3);
 Square = height*width;
 [counts, X] = imhist(Image3);
 X = counts./Square;
 Entropy = -sum(X.*log2(X));
 E3 = entropy(Image3);
 disp("Entropy according to formula 2.1 (tiff): "), disp(Entropy); 
 disp("Entropy(tiff): "), disp(E3); 
 