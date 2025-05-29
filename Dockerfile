FROM ubuntu:22.04
LABEL authors="without eyes"

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    qtbase5-dev qtdeclarative5-dev qttools5-dev \
    libqt5multimedia5-plugins libqt5multimediawidgets5 libqt5multimedia5 qtmultimedia5-dev \
    cmake g++ build-essential \
    libgl1-mesa-dev \
    ca-certificates curl \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/*

RUN curl -LO https://github.com/Kitware/CMake/releases/download/v3.28.3/cmake-3.28.3-linux-x86_64.sh \
  && chmod +x cmake-3.28.3-linux-x86_64.sh \
  && ./cmake-3.28.3-linux-x86_64.sh --skip-license --prefix=/usr/local \
  && rm cmake-3.28.3-linux-x86_64.sh

WORKDIR /app
COPY . .

RUN cmake -B build -S . && cmake --build build --parallel

CMD ["./build/EasyLearner"]