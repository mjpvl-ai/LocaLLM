# Use a base image
FROM ubuntu:latest

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    curl \
    wget \
    bash \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Clone llama.cpp repository
RUN git clone https://github.com/ggerganov/llama.cpp.git /app/llama.cpp

# Build llama.cpp with CPU support
RUN cd /app/llama.cpp && mkdir build && cd build && \
    cmake .. && make -j$(nproc)

# Copy the config file
COPY config.txt /app/config.txt

# Fetch model name and URL from config file
RUN mkdir -p /app/models && \
    bash -c 'source /app/config.txt && wget -O "/app/models/${MODEL_NAME}" "${MODEL_URL}"'

# Set the default command to run the server
CMD ["/app/llama.cpp/build/bin/llama-server", "-m", "/app/models/DeepSeek-R1-Distill-Qwen-14B-IQ2_XS.gguf", "--host", "0.0.0.0"]
