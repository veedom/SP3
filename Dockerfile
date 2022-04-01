FROM ubuntu
COPY 1.cpp .
RUN apt-get update
RUN apt-get install -y gcc
RUN apt-get install -y g++
RUN g++ 1.cpp -static -o 1cpp
CMD ./1cpp
