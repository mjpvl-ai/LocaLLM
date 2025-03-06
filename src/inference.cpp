#include "inference.h"
#include <iostream>

void runInference(const std::string &modelPath, const std::string &prompt) {
    std::cout << "Running inference on model: " << modelPath << std::endl;

    std::string command = "./extern/llama.cpp/build/main -m " + modelPath + " -p \"" + prompt + "\"";
    int ret = system(command.c_str());

    if (ret != 0) {
        std::cerr << "Error: Inference failed!" << std::endl;
    } else {
        std::cout << "Inference completed successfully!" << std::endl;
    }
}
