# Image-Steganography
# Introduction
Steganography is the practice of concealing a file, message, image, or video within 
another file, message, image, or video. It is concerned with concealing the fact that a 
secret message is being sent, as well as concealing the contents of the message.

# Problem Statement
-Image Steganography using the serial technique and speeding up the process using parallel
approach.

-Parallelising the Least Significant Bit encoding of pixels using CUDA.

# Relevance of Problem Statement
Steganography means of storing data in a way that it hides the existence of them. Using steganography to 
communicate greatly reduces the risk of information leakage. Thus steganography can be a way which 
makes it possible to send news and information without being censored and without the fear of the 
messages being intercepted and traced back to us.
It is used in secret operations such as military communication and other scenarios where privacy is 
desired. Hackers also use steganography to lure users to download some files(audio,video,etc) and hides a 
malicious script in it using steganography. Once a user downloads it and opens the file, the script executes 
and the Hacker gains the desired access to the computer.
If the data to be hidden is huge, the hiding process takes large amount of time. So using techniques 
of parallel computing, this process can be speeded up

# Methodology
Image
The computer sees the image as a matrix of pixels with each pixel having some RGB value indicating the 
intensities of these colors.
## LSB Encoding
 The pixels stores the data in form of rgb values. The procedure of LSB steganography Encoding is to 
modify the last bit of the RGB values according to the bits of the character of data.
The secret text is considered as set of characters, each character is represented as 8 bits, one by one 
each bit is stored in LSB of RGB values of pixels. Pixels are traversed from starting and the LSB encoding 
in pixels continues until the secret message is ended.
![CUDAchart](https://github.com/SARTHAK4U/Image-Steganography/blob/main/Outputs/CUDA%20Chart.png)

# Outputs
![Output1](https://github.com/SARTHAK4U/Image-Steganography/blob/main/Outputs/Output1.png)
![Output2](https://github.com/SARTHAK4U/Image-Steganography/blob/main/Outputs/Output2.png)
![Output3](https://github.com/SARTHAK4U/Image-Steganography/blob/main/Outputs/Output3.png)
![Output4](https://github.com/SARTHAK4U/Image-Steganography/blob/main/Outputs/Output4.png)
![Output5](https://github.com/SARTHAK4U/Image-Steganography/blob/main/Outputs/Output5.png)
![Output6](https://github.com/SARTHAK4U/Image-Steganography/blob/main/Outputs/Output6.png)
