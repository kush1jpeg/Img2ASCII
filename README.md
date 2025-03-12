# 🎨 ASCII Art Generator  

This project converts images (JPEG/PNG) into ASCII art using the **PPM (P3) format**. It reads an image, processes its pixel values, and maps them to ASCII characters based on brightness.  

## 🚀 Features  
- ✔️ Converts images to ASCII art  
- ✔️ Automatically converts non-PPM images to PPM format using ImageMagick  
- ✔️ Removes unnecessary comments from the PPM file  
- ✔️ Outputs the ASCII art to a text file  

## 🛠 Installation  

### Prerequisites  
- **C++ Compiler (G++)**  
- **ImageMagick** (for automatic image conversion)  
  - Install it using:  
    ```bash
    sudo apt install imagemagick  # Linux  
    brew install imagemagick       # macOS  
    winget install ImageMagick     # Windows  
    ```

### Clone the Repository  
```bash
git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name
```

### Clone the Repository  
```bash
git clone https://github.com/kush1jpeg/Img2ASCII.git
cd Img2ASCII
```
### Compile the Code
```bash
g++ -o ascii_art_generator ppm2ASCII.cpp
```
### 📸 Usage
Run the program:
```bash
./ascii_art_generator
```

##### Enter the image filename(eg- linux.jpg) when prompted. If it's not a .ppm file, it will be converted automatically.
The ASCII art will be saved as:
```bash
asciiART.txt
```
#### 🖼 Best Image Types for ASCII Conversion
High-contrast images work best
Simple images with clear edges and details
Black & White or Grayscale images produce better results
Resized images (smaller dimensions) improve clarity in ASCII format
#### 🏗️ How It Works
- Checks Image Format – Converts to .ppm (P3) if necessary
- Reads Pixel Data – Extracts RGB values
- Converts to Grayscale – Averages RGB values to determine brightness
- Maps to ASCII Characters – Darker pixels get denser characters (#), while lighter ones get sparse characters (.)
- Saves ASCII Art – Outputs to asciiART.txt

### 😒My thoughts-
I wanted to build it as soon as i saw it cuz it looked cool + i would get to work with raw image processing.The person had coded it in python (the lang for the retarded) and i wanted to do it in c++(cuz i am an idiot who admires complexity) .
I wanted to code everything from scratch ; reading the ppm file and displaying ascii values acc to it was easy as f#ck but wat if the person enters another file type i mean jpeg, jpg or png which is mostly commmon. Now
i wanted this proj to read other extns too ...and convert them to ppm : but remember without any library ; so i researched and gpt told its very difficult for a newbie like me i then resorted to Image Magick an opensource cli tool exactly 
meant for this type of conversion from one religion to another. I feel lost cuz uk ultimately its not something as raw as i imagined but ig its a challenge for the future me to make that. Some logics were not clicking on to my lil brain 
like i was using iterator_buff even though i had to read int values but hail gpt for helping me out.....  so yeah it works , but i failed leaving all that ------------the ascii default art is kinda insane.
