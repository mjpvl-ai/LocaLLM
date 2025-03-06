# Use a base image
FROM ubuntu:latest

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    curl \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Clone llama.cpp repository
RUN git clone https://github.com/ggerganov/llama.cpp.git /app/llama.cpp

# Build llama.cpp with CPU support
RUN cd /app/llama.cpp && mkdir build && cd build && \
    cmake .. && make -j$(nproc)

# Download the correct model
RUN mkdir -p /app/models && \
    wget -O /app/models/DeepSeek-R1-Distill-Qwen-14B-IQ2_XS.gguf \
    "https://huggingface.co/bartowski/DeepSeek-R1-Distill-Qwen-14B-GGUF/resolve/main/DeepSeek-R1-Distill-Qwen-14B-IQ2_XS.gguf"

# Set the default command to run the server
CMD ["/app/llama.cpp/build/bin/llama-server", "-m", "/app/models/DeepSeek-R1-Distill-Qwen-14B-IQ2_XS.gguf", "--host", "0.0.0.0"]
