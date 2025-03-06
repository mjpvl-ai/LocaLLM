#include "quantization.h"
#include <iostream>
#include <fstream>

void quantizeModel(const std::string &modelPath, const std::string &outputPath) {
    std::cout << "Quantizing model: " << modelPath << std::endl;

    std::string command = "./extern/llama.cpp/build/quantize " + modelPath + " " + outputPath + " Q4_0";
    int ret = system(command.c_str());

    if (ret != 0) {
        std::cerr << "Error: Quantization failed!" << std::endl;
    } else {
        std::cout << "Quantization successful! Saved to " << outputPath << std::endl;
    }
}
