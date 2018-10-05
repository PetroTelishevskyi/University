
I = imread('E:\ImagesTI\image.jpg');
R = entropy(I);

[x,map] = rgb2ind(I,8);
figure,imshow(x,map);

