#include "quantization.h"
#include "fine_tune.h"
#include "inference.h"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: ./localllm [quantize | finetune | infer] <args>" << std::endl;
        return 1;
    }

    std::string mode = argv[1];
    
    if (mode == "quantize" && argc == 4) {
        quantizeModel(argv[2], argv[3]);
    } else if (mode == "finetune" && argc == 4) {
        fineTuneModel(argv[2], argv[3]);
    } else if (mode == "infer" && argc == 4) {
        runInference(argv[2], argv[3]);
    } else {
        std::cerr << "Invalid command. Use: quantize, finetune, or infer" << std::endl;
    }

    return 0;
}
