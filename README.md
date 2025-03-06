# LocaLLM - Deploying DeepSeek LLM with Docker

This guide will help you set up, build, and run the DeepSeek LLM model using Docker.

## Prerequisites

Make sure you have the following installed on your system:
- **Git**
- **Docker**
- **Internet Connection** (to download the model)

---

## 1. Clone the Repository

First, clone the repository using Git:
```bash
# Clone the repository
git clone https://github.com/mjpvl-ai/LocaLLM.git

# Navigate into the directory
cd LocaLLM
```

If you get an error that the repository already exists, make sure you are inside the correct directory or delete the existing one before cloning.

---

## 2. Build the Docker Image

Run the following command to build the Docker image:
```bash
docker build -t llama-deepseek .
```

This will install dependencies, compile `llama.cpp`, and download the model inside the container.

---

## 3. Run the Docker Container

Start the container and expose it on port **8080**:
```bash
docker run -p 8080:8080 --name llama-container llama-deepseek
```

If you need to restart the container, first remove any existing one:
```bash
docker rm -f llama-container
```
Then rerun the container using the command above.

---

## 4. Check Running Containers

To check if the container is running, use:
```bash
docker ps
```
If it is not running, check all containers (including stopped ones):
```bash
docker ps -a
```
If the container has exited, check logs to debug the issue:
```bash
docker logs llama-container
```

---

## 5. Inferencing the Model

Once the server is running, you can interact with it via `curl` or a web request:
```bash
curl -X POST "http://localhost:8080/generate" \
     -H "Content-Type: application/json" \
     -d '{"prompt": "Hello, how are you?", "max_tokens": 100}'
```

You should see a response from the model in JSON format.

---

## 6. Pushing Changes to GitHub

If you make changes and want to push them to GitHub, follow these steps:
```bash
# Add changes
git add .

# Commit changes
git commit -m "Updated Docker setup and model deployment instructions"

# Pull the latest changes (to avoid conflicts)
git pull origin main --rebase

# Push the changes
git push origin main
```

If you get a push error due to conflicts, resolve them and try pushing again.

---

## 7. Clean Up Resources

If you need to clean up Docker resources, run:
```bash
# Stop and remove the container
docker rm -f llama-container

# Remove the Docker image
docker rmi llama-deepseek
```

If you need to remove all stopped containers and unused images:
```bash
docker system prune -a
```

---

## Troubleshooting

### Model Loading Error
If you see an error like:
```
gguf_init_from_file: failed to open GGUF file '/app/models/deepseek-llm-7b-base.Q2_K.gguf'
```
Check if the model exists inside the container:
```bash
docker exec -it llama-container ls /app/models/
```
If it’s missing, try rebuilding the container with:
```bash
docker build --no-cache -t llama-deepseek .
```

---

## Conclusion
You have successfully set up DeepSeek LLM using Docker. If you face any issues, check the logs or rebuild the container. Enjoy experimenting with the model!

