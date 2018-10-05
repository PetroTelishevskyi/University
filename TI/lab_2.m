
Image = imread('E:\ImagesTI\wolf.jpg');

figure, imshow(Image); 
E = entropy(Image);
disp("Entropy standart image"), disp(E);
[rowN, columnN]= size(Image);
pixelN = 0;
for i=1:rowN
    for j=1:columnN
            pixelN = pixelN + 1;       
    end
end
[aN, bN] = imhist(Image);
p = aN./pixelN;



Samping_Image = downsample(Image,2);
figure,imshow (Samping_Image);
E = entropy(Samping_Image);
disp("Entropy samping image of step 2"), disp(E);

Samping_Image1 = downsample(Image,4);
figure, imshow  (Samping_Image1);
E1 = entropy(Samping_Image1);
disp("Entropy samping image of step 4"), disp(E1);

quant_Image1 = quantiz (Image,8);
figure, imshow  (quant_Image1);
E2 = entropy(quant_Image1);
disp("Entropy quant image of level 8"), disp(E2);

quant_Image2 = quantiz (Image,16);
figure, imshow  (quant_Image2);
E3 = entropy(quant_Image2);
disp("Entropy quant image of level 16"), disp(E3);

quant_Image3 = quantiz (Image,64);
figure, imshow  (quant_Image3);
E4 = entropy(quant_Image3);
disp("Entropy quant image of level 64"), disp(E4);

restored_Image_2 = interp2(Samping_Image, 'linear');
figure, imshow  (restored_Image_2);

restored_Image_4 = interp2(Samping_Image, 'cubic');
figure, imshow  (restored_Image_4);

[rowN, columnN]= size(restored_Image_2);
pixelN = 0;
for i=1:rowN
    for j=1:columnN
            pixelN = pixelN + 1;       
    end
end
[aN, bN] = imhist(restored_Image_2);
q1 = aN./pixelN;
 
[rowN, columnN]= size(restored_Image_4);
pixelN = 0;
for i=1:rowN
    for j=1:columnN
            pixelN = pixelN + 1;       
    end
end
[aN, bN] = imhist(restored_Image_4);
q2 = aN./pixelN;
 R1 = sum(p.*log(p./q1));
 R2 = sum(p.*log(p./q2));
disp('Relative entropy for image and downsample image with step 2:');
disp(R1);
disp('Relative entropy for image and downsample image with step 4:');
disp(R2);
 [rowN, columnN]= size(quant_Image1);
pixelN = 0;
for i=1:rowN
    for j=1:columnN
            pixelN = pixelN + 1;       
    end
end
[aN, bN] = imhist(quant_Image1);
q3 = aN./pixelN;

[rowN, columnN]= size(quant_Image2);
pixelN = 0;
for i=1:rowN
    for j=1:columnN
            pixelN = pixelN + 1;       
    end
end
[aN, bN] = imhist(quant_Image2);
q4 = aN./pixelN;

[rowN, columnN]= size(quant_Image3);
pixelN = 0;
for i=1:rowN
    for j=1:columnN
            pixelN = pixelN + 1;       
    end
end
[aN, bN] = imhist(quant_Image3);
q5 = aN./pixelN;

 R3 = sum(p.*log(p./q3));
 R4 = sum(p.*log(p./q4));
 R5 = sum(p.*log(p./q5));
disp('Relative entropy for image and quant image with step 8:');
disp(R3);
disp('Relative entropy for image and quant image with step 16:');
disp(R4);
disp('Relative entropy for image and quant image with step 64:');
disp(R5);