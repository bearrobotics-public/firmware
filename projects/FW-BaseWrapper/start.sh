#!/bin/bash
docker buildx build -t example_node:latest . && \
docker run -it --rm --network host --name example_node_container example_node:latest
