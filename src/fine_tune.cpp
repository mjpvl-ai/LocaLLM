#include "fine_tune.h"
#include <iostream>

void fineTuneModel(const std::string &trainData, const std::string &modelPath) {
    std::cout << "Fine-tuning model: " << modelPath << " with dataset: " << trainData << std::endl;

    std::string command = "./extern/llama.cpp/build/train -m " + modelPath + " -d " + trainData;
    int ret = system(command.c_str());

    if (ret != 0) {
        std::cerr << "Error: Fine-tuning failed!" << std::endl;
    } else {
        std::cout << "Fine-tuning completed successfully!" << std::endl;
    }
}
