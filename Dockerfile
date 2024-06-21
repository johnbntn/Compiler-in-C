# syntax=docker/dockerfile:1

FROM ubuntu:20.04

# Install dependencies
RUN apt-get update && apt-get install build-essential
RUN apt install nasm

# Copy in compiler and assembler
COPY jlcc /usr/bin
COPY asm /usr/bin

# Add test files
COPY Tests/
