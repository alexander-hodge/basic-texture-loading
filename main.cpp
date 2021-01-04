#include <vector>
#include <iterator>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "middleware/stb_image/include/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "middleware/stb_image/include/stb_image_write.h"

int main(int argc, char** argv) {

  std::string inputPath = "input/texture.png";
  unsigned char* data;
  int width;
  int height;
  int channels; //per Pixel
  std::vector<unsigned char> pixelData;

  //load texture
  data = stbi_load(inputPath.c_str(), &width, &height, &channels, 0);
  pixelData.assign(data, data + ((int64_t)width * (int64_t)height * channels));
  stbi_image_free(data);

  std::string outputPath = "output/texture.png";
  //write texture
  stbi_write_png(outputPath.c_str(),
    width,
    height,
    channels, //RGB = 3, RGBA = 4
    &pixelData[0], //the pixel data
    //distance in bytes from the first byte of a row of pixels to 
    //the first byte of the next row of pixels
    width * channels);

  return 0;
}
